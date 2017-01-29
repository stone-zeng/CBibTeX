#include <cctype>
#include <iostream>
#include "BibString.h"
#include "BibEntry.h"
#include "MyFunctions.h"

using namespace std;

namespace CBibTeX
{
    BibEntry::BibEntry()
    {}

    BibEntry::BibEntry(const BibString& str_BibEntryType, const BibString& str_BibEntryBody)
    {
        type = getType(str_BibEntryType);
        key = getKey(str_BibEntryBody);
        fields = getFields(str_BibEntryBody);
    }

    enum_BibEntry BibEntry::getType(const BibString& str_BibEntryType)
    {
        // 不含 '@' 的条目名称字符串
        // e.g. "Article"
        BibString temp_str_BibEntryType(str_BibEntryType);

        temp_str_BibEntryType = deleteLeftRightSpace(temp_str_BibEntryType);

        // Bib 条目名不区分大小写
        // 此处全部转换为大写
        temp_str_BibEntryType = toUpperCase(temp_str_BibEntryType);

        // 遍历 map_BibEntry，找到与字符串对应的类型名
        for (auto iter = map_BibEntry.begin(); iter != map_BibEntry.end(); ++iter)
            if (temp_str_BibEntryType == iter->second)
                return iter->first;

        // TODO: 20170124  need to return an error.
        return enum_BibEntry(-1);
    }

    BibString BibEntry::getKey(const BibString& str_BibEntryBody)
    {
        // TODO: 20170127  类型名需要统一
        size_t pos_beginKey = 0;
        size_t pos_endKey = findCharacter(str_BibEntryBody, ',');

        auto len_Key = pos_endKey - pos_beginKey;

        return BibString(str_BibEntryBody, pos_beginKey, len_Key);
    }

    BibFieldSet BibEntry::getFields(const BibString& str_BibEntryBody)
    {
        // key 后 ',' 后的第一个字符
        auto pos_begin = findCharacter(str_BibEntryBody, ',') + 1;
        auto pos_end = str_BibEntryBody.length();

        // DEBUG
        char buffer1[1000] = { 0 };
        char buffer2[1000] = { 0 };
        char buffer3[1000] = { 0 };
        char buffer4[1000] = { 0 };
        // DEBUG

        // 域集合
        BibFieldSet fields;

        while (pos_begin < pos_end)
        {
            //********** 读取域名 (field name) **********//
            auto pos_beginFieldName = pos_begin;
            auto pos_endFieldName = findCharacter(str_BibEntryBody, '=', pos_begin);

            // 未找到 '=' 则退出循环
            if (pos_endFieldName == str_BibEntryBody.npos)
                break;

            auto len_fieldName = pos_endFieldName - pos_beginFieldName;
            BibString fieldName(str_BibEntryBody, pos_begin, len_fieldName);
            
            // DEBUG
            strcpy(buffer1, fieldName.c_str());
            // DEBUG

            // 删除头尾空白字符
            fieldName = deleteLeftRightSpace(fieldName);

            // Bib 域不区分大小写，全部转换为大写
            fieldName = toUpperCase(fieldName);

            // DEBUG
            strcpy(buffer2, fieldName.c_str());
            // DEBUG

            //********** 读取域值 (field value) **********//
            int bracketFlag = 0;
            int quotationFlag = 0;

            // '=' 后第一个字符
            auto i_beginFieldValue = pos_endFieldName + 1;
            auto i_endFieldValue = i_beginFieldValue;

            while (true)
            {
                auto temp_ch = str_BibEntryBody[i_endFieldValue];

                // 检测到 Bib 条目的最外层 '}' 则退出内层循环
                if (bracketFlag < 0)
                    break;

                // 检测到 ',' 且不在 '{' '}' 或 '\"' '\"' 之间，退出内层循环
                if (temp_ch == ',')
                    if (bracketFlag == 0 && quotationFlag == 0)
                        break;

                // 遇到 '{' 则 +1，遇到 '}' 则 -1；
                // 回到 0 值，说明括号结束
                if (temp_ch == '{')
                    ++bracketFlag;
                if (temp_ch == '}')
                    --bracketFlag;

                // flag = 0，则遇到 '\"' 改为 1；
                // flag = 1，则遇到 '\"' 改为 0；
                // 回到 0 值，说明括号结束
                if (temp_ch == '\"')
                {
                    if (quotationFlag == 0)
                        quotationFlag = 1;
                    else
                        quotationFlag = 0;
                }
                    
                ++i_endFieldValue;
            }

            auto len_fieldValue = i_endFieldValue - i_beginFieldValue;
            BibString fieldValue(str_BibEntryBody, i_beginFieldValue, len_fieldValue);

            // DEBUG
            //strcpy(buffer3, fieldValue.c_str());
            // DEBUG

            // 删除首尾空白字符
            fieldValue = deleteLeftRightSpace(fieldValue);

            // 删除首尾括号、引号
            if (!fieldValue.empty())
                // 下标运算要求 fieldValu 非空
                if (fieldValue[0] == '{' || fieldValue[0] == '\"')
                {
                    fieldValue.erase(0, 1);
                    fieldValue.erase(fieldValue.length() - 1 , 1);
                }

            //**********  **********//

            // TODO: 20170129 "-1" 用来报错
            int fieldNameID = -1;

            // 遍历 map_BibField，找到与字符串对应的类型名
            for (auto iter = map_BibField.begin(); iter != map_BibField.end(); ++iter)
                if (fieldName == iter->second)
                    fieldNameID = iter->first;
            
            switch (fieldNameID)
            {
                case $_Address:
                    break;
                case $_Author:
                    fields.author = Field::Author(fieldValue);
                    break;
                case $_BookTitle:
                    break;
                case $_Chapter:
                    break;
                case $_CrossRef:
                    break;
                case $_Edition:
                    break;
                case $_Editor:
                    break;
                case $_HowPublished:
                    break;
                case $_Institution:
                    break;
                case $_Month:
                    break;
                case $_Note:
                    break;
                case $_Number:
                    break;
                case $_Organization:
                    break;
                case $_Pages:
                    break;
                case $_Publisher:
                    break;
                case $_School:
                    break;
                case $_Series:
                    break;
                case $_Title:
                    fields.title = Field::Title(fieldValue);
                    break;
                case $_Type:
                    break;
                case $_Volume:
                    break;
                case $_Year:
                    break;

                default:
                    break;
            }

            // DEBUG
            strcpy(buffer3, fields.author.xxx.c_str());
            strcpy(buffer4, fields.title.xxx.c_str());
            // DEBUG

            // 移动 pos_begin 至新位置
            pos_begin = i_endFieldValue + 1;
        }

        return BibFieldSet();
    }
}
