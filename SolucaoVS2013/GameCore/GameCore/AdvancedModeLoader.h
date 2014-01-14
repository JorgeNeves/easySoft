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

enum FieldValue { UserFriendsIDs, UserID, UserMood, UserName, UserTags };

class Node
{
public:
	int UserID;
	int x, y, z;
	wstring UserMood;
	wstring UserName;
	list<wstring> UserTags;
	list<Node*> friends;
};

class Arch
{
public:
	int friend1;
	int friend2;
	list<wstring> tags;
};

class Graph
{
public:
	list<Node*> nodelist;
	list<Arch*> archlist;

	Node* GetUserFromId(int id)
	{
		for (std::list<Node*>::iterator it = nodelist.begin(); it != nodelist.end(); it++)
		{
			if ((*it)->UserID == id)
				return (*it);
		}

	}
};

class AdvancedGraphGenerator
{
	std::map <std::wstring, FieldValue> fieldMap;
	Graph* graph;

public:
	wstring url;

	AdvancedGraphGenerator(wstring url)
	{
		fieldMap[L"UserFriendsIDs"] = FieldValue::UserFriendsIDs;
		fieldMap[L"UserID"] = FieldValue::UserID;
		fieldMap[L"UserMood"] = FieldValue::UserMood;
		fieldMap[L"UserName"] = FieldValue::UserName;
		fieldMap[L"Usertags"] = FieldValue::UserTags;
		graph = new Graph();
		this->url = url;
	}

	Graph* GetGeneratedGraph()
	{
		return graph;
	}

	void SetField(std::wstring name, json::value value, Node* node)
	{
		switch (fieldMap[name])
		{
		case FieldValue::UserFriendsIDs:
			for (auto iterInner = value.cbegin(); iterInner != value.cend(); ++iterInner)
			{
				Node* userfriend = new Node();
				int id = iterInner->second.as_integer();
				if (graph->GetUserFromId(id) == nullptr)
				{
					userfriend->UserID = id;
					node->friends.push_back(userfriend);
					graph->nodelist.push_back(userfriend);

					Arch* arch = new Arch();
					arch->friend1 = node->UserID;
					arch->friend2 = userfriend->UserID;
					graph->archlist.push_back(arch);
				}
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
			for (auto iterInner = value.cbegin(); iterInner != value.cend(); ++iterInner)
			{
				std::wstring tag = iterInner->second.as_string();
				node->UserTags.push_back(tag);
			}
			break;
		}
	}

	Graph* GetGraphFromJson(json::value value)
	{
		Node* node = new Node();
		for (auto iterInner = value.cbegin(); iterInner != value.cend(); ++iterInner)
		{
			const json::value &propertyName = iterInner->first;
			const json::value &propertyValue = iterInner->second;

			SetField(propertyName.as_string(), propertyValue, node);
		}
		graph->nodelist.push_back(node);
		return graph;
	}

	pplx::task<void> GetRemoteUserData()
	{
		return pplx::create_task([this]
		{
			http_client client(this->url);

			return client.request(methods::GET);
		}).then([](http_response response)
		{
			if (response.status_code() == status_codes::OK)
			{
				return response.extract_json();
			}

			return pplx::create_task([] { return json::value(); });

		}).then([this](json::value jsonValue)
		{
			if (jsonValue.is_null())
				return;

			this->GetGraphFromJson(jsonValue);
		});
	}
};

#endif