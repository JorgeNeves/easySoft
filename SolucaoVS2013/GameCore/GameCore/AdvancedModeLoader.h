#pragma once ADVANCEDMODELOADER

#include <cpprest\http_client.h>
#include <cpprest\json.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

#include <map>
#include <list>
#include <iostream>
#include <string>
#include "grafos.h"

enum FieldValue { UserFriendsIDs, UserID, UserMood, UserName, UserTags};

class AdvancedGraphGenerator
{
	std::map <std::wstring, FieldValue> fieldMap;

public:
	AdvancedGraphGenerator()
	{
		fieldMap[L"UserFriendsIDs"] = FieldValue::UserFriendsIDs;
		fieldMap[L"UserID"] = FieldValue::UserID;
		fieldMap[L"UserMood"] = FieldValue::UserMood;
		fieldMap[L"UserName"] = FieldValue::UserName;
		fieldMap[L"UserTags"] = FieldValue::UserTags;
	}

	void SetField(std::wstring name, json::value value)
	{
		switch (fieldMap[name])
		{
		case FieldValue::UserFriendsIDs:
			//op
			break;
		case FieldValue::UserID:
			//op
			break;
		case FieldValue::UserMood:
			//op
			break;
		case FieldValue::UserName:
			//op
			break;
		case FieldValue::UserTags:
			//op
			break;
		}
	}
};

pplx::task<void> GetAll()
{
	return pplx::create_task([]
	{
		http_client client(L"http://wvm054.dei.isep.ipp.pt/SocialiteWebService/SocialiteWS.svc/userdata?id=1&token=debug");

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

		/* graph build routines
		StatusGenerator generator;
		auto member = generator.GetStatusFromJson(jsonValue);
		member.Display();*/
	});
}