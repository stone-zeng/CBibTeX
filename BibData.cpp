#include <string>
#include <fstream>
#include <iostream>
#include "MyFunctions.h"
#include "BibString.h"
#include "BibData.h"

using namespace std;

namespace CBibTeX
{
    BibData::BibData()
    {}

    BibData::BibData(const BibString& fileName)
    {
        ifstream inputFile(fileName, fstream::in);

        if (inputFile)
        {
            char charTemp(0);
            while (inputFile.get(charTemp))
                str_BibData += charTemp;
        }
        else
        {
            // TODO: 20160806  use C++ throw and catch.
            cerr << "Error: Cannot found the input file " << fileName << ".\n";
            exit(1);
        }

        inputFile.close();
    }

    void BibData::deleteComment()
    {
        auto pos_beginComment = findCharacter(str_BibData, '%');
        auto pos_endComment = str_BibData.find('\n', pos_beginComment);
        do
        {
            if (pos_endComment > pos_beginComment)
                str_BibData.erase(pos_beginComment, pos_endComment - pos_beginComment);
            pos_beginComment = findCharacter(str_BibData, '%');
            pos_endComment = str_BibData.find('\n', pos_beginComment);
        } while (pos_beginComment != str_BibData.npos);

    }

    void BibData::getBibEntryList()
    {
        // TODO: 20170127  类型名需要统一
        BibString::size_type pos_begin = 0;
        BibString::size_type pos_end = str_BibData.length();

        while (pos_begin != str_BibData.npos && pos_begin < pos_end)
        {
            // 查找 Bib 条目开始之标记 '@'
            auto pos_BibEntryMarker = findCharacter(str_BibData, '@', pos_begin);

            // 若未找到 '@'，则跳出循环
            if (pos_BibEntryMarker == str_BibData.npos)
                break;

            // TODO: 20170127  圆括号
            // 由大括号确定 Bib 条目主体
            auto pos_beginBibEntryBody
                = findCharacter(str_BibData, '{', pos_BibEntryMarker);
            auto pos_endBibEntryBody = pos_beginBibEntryBody;

            // 遇到 '{' 则 +1，遇到 '}' 则 -1；
            // 回到 0 值，说明括号结束
            int bracketFlag = 0;

            do
            {
                //TODO: 需要考虑 '\{' 和 '\}'
                if (str_BibData[pos_endBibEntryBody] == '{')
                    ++bracketFlag;
                if (str_BibData[pos_endBibEntryBody] == '}')
                    --bracketFlag;

                ++pos_endBibEntryBody;
            } while (bracketFlag != 0);

            // BibEntryType 长度：'@' 与 '{' 之间，不含符号本身
            auto len_BibEntryType = pos_beginBibEntryBody - pos_BibEntryMarker - 1;
            // BibEntryBody 长度：'{' 与 '}' 之间，不含括号本身
            auto len_BibEntryBody = pos_endBibEntryBody - pos_beginBibEntryBody - 1;

            // 获取 Bib 条目
            BibString str_BibEntryType(str_BibData, pos_BibEntryMarker + 1, len_BibEntryType);
            BibString str_BibEntryBody(str_BibData, pos_beginBibEntryBody + 1, len_BibEntryBody);

            BibEntry entry(str_BibEntryType, str_BibEntryBody);

            // DEBUG
            //char buffer1[10] = {0};
            char buffer2[1000] = { 0 };
            auto buffer1 = entry.type;
            strcpy(buffer2, entry.key.c_str());
            // DEBUG

            // 追加该条目至 vec_bibEntryList 末尾
            vec_bibEntryList.push_back(entry);

            // 移动 pos_begin 至新位置
            pos_begin = pos_endBibEntryBody;
        }
    }
}
