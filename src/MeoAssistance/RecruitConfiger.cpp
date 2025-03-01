﻿#include "RecruitConfiger.h"

#include <fstream>
#include <sstream>
#include <algorithm>

#include <json.h>

#include "Logger.hpp"

using namespace asst;

bool asst::RecruitConfiger::parse(json::value&& json)
{
	json::value root = std::move(json);
	for (json::value& oper : root.as_array()) {
		OperRecruitInfo oper_temp;
		oper_temp.name = oper["name"].as_string();
		oper_temp.type = oper["type"].as_string();
		m_all_types.emplace(oper_temp.type);
		// 职业类型也作为tag之一，加上"干员"两个字
		std::string type_as_tag = oper_temp.type + "干员";
		oper_temp.tags.emplace(type_as_tag);
		m_all_tags.emplace(std::move(type_as_tag));

		oper_temp.level = oper["level"].as_integer();
		oper_temp.sex = oper.get("sex", "unknown");
		for (const json::value& tag_value : oper["tags"].as_array()) {
			std::string tag = tag_value.as_string();
			oper_temp.tags.emplace(tag);
			m_all_tags.emplace(std::move(tag));
		}
		oper_temp.hidden = oper.get("hidden", false);
		oper_temp.name_en = oper.get("name-en", "unknown");
		m_all_opers.emplace_back(std::move(oper_temp));
	}

	// 按干员等级排个序
	std::sort(m_all_opers.begin(), m_all_opers.end(), [](
		const auto& lhs,
		const auto& rhs)
		-> bool {
			return lhs.level > rhs.level;
		});

	return true;
}