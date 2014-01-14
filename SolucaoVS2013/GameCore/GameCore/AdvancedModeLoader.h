#ifndef ADVMODE_
#define ADVMODE_

#include <cpprest\http_client.h>
#include <cpprest\json.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

#include <map>
#include <list>
#include <iostream>
#include <string>

using namespace std;

enum FieldValue { UserFriendsIDs, UserID, UserMood, UserName, UserTags};

class Node
{
public:
	int UserID;
	int x, y, z;
	wstring UserMood;
	wstring UserName;
	list<string> UserTags;
	list<Node*> friends;
};

class Arch
{
public:
	int friend1;
	int friend2;
	list<string> tags;
};

class Graph
{
public:
	list<Node*> nodelist;
	list<Arch*> archlist;
};

class AdvancedGraphGenerator
{
	std::map <std::wstring, FieldValue> fieldMap;
	Graph graph;

public:
	AdvancedGraphGenerator()
	{
		fieldMap[L"UserFriendsIDs"] = FieldValue::UserFriendsIDs;
		fieldMap[L"UserID"] = FieldValue::UserID;
		fieldMap[L"UserMood"] = FieldValue::UserMood;
		fieldMap[L"UserName"] = FieldValue::UserName;
		fieldMap[L"Usertags"] = FieldValue::UserTags;
	}

	void SetField(std::wstring name, json::value value, Node* node)
	{
		switch (fieldMap[name])
		{
		case FieldValue::UserFriendsIDs:
			for (auto iterInner = value.cbegin(); iterInner != value.cend(); ++iterInner)
			{
				Node* userfriend = new Node();
				userfriend->UserID = iterInner->second.as_integer();
				node->friends.push_back(userfriend);
			}
			break;
		case FieldValue::UserID:
			node->UserID = value.as_integer();
			break;
		case FieldValue::UserMood:
			node->UserMood = value.as_string();
			break;
		case FieldValue::UserName:
			node->UserName = value.as_string();
			break;
		case FieldValue::UserTags:
			//op
			break;
		}
	}

	Graph GetGraphFromJson(json::value value)
	{
		Node* node = new Node();
		for (auto iterInner = value.cbegin(); iterInner != value.cend(); ++iterInner)
		{
			const json::value &propertyName = iterInner->first;
			const json::value &propertyValue = iterInner->second;

			SetField(propertyName.as_string(), propertyValue, node);
		}
		graph.nodelist.push_back(node);
		return graph;
	}
};

pplx::task<void> GetAll()
{
	return pplx::create_task([]
	{
		http_client client(L"http://wvm054.dei.isep.ipp.pt/SocialLiteWS/SocialiteWS.svc/userdata?id=1&token=debug");

		return client.request(methods::GET);
	}).then([](http_response response)
	{
		if (response.status_code() == status_codes::OK)
		{
			return response.extract_json();
		}

		return pplx::create_task([] { return json::value(); });

	}).then([](json::value jsonValue)
	{
		if (jsonValue.is_null())
			return;

		AdvancedGraphGenerator generator;
		auto graph = generator.GetGraphFromJson(jsonValue);
		/* graph build routines
		StatusGenerator generator;
		auto member = generator.GetStatusFromJson(jsonValue);
		member.Display();*/
	});
}

#endif