#include <string>
#include <fstream>
#include <iostream>
#include "MyFunctions.h"
#include "BibData.h"

using namespace std;

BibData::BibData()
{}

BibData::BibData(const string& fileName)
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
        //TODO: 20160806  use C++ throw and catch
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

string::size_type BibData::getBibEntry(const string::size_type& pos_begin)
{
    auto pos_beginBibEntry = findCharacter(str_BibData, '@', pos_begin);

    if (pos_beginBibEntry == str_BibData.npos)
        return str_BibData.npos;
    else
    {
        auto pos_beginBibEntryBody
            = findCharacter(str_BibData, '{', pos_beginBibEntry);
        auto pos_endBibEntryBody = pos_beginBibEntryBody;

        int bracketFlag = 0;

        do
        {
            if (str_BibData[pos_endBibEntryBody] == '{')
                ++bracketFlag;
            if (str_BibData[pos_endBibEntryBody] == '}')
                --bracketFlag;

            ++pos_endBibEntryBody;
        } while (bracketFlag != 0);


        auto len_BibEntryType = pos_beginBibEntryBody - pos_beginBibEntry;
        auto len_BibEntryBody = pos_endBibEntryBody - pos_beginBibEntryBody;

        string str_BibEntryType(str_BibData, pos_beginBibEntry, pos_beginBibEntryBody - pos_beginBibEntry);
        string str_BibEntryBody(str_BibData, pos_beginBibEntryBody, len_BibEntryBody);
        
        BibEntry temp(str_BibEntryType, str_BibEntryBody);

        vec_bibEntryList.push_back(temp);

        return pos_beginBibEntryBody + 1;
    }
}

void BibData::getBibEntryList()
{
    string::size_type pos_begin = 0;

    while (pos_begin != str_BibData.npos && pos_begin < str_BibData.length())
    {
        pos_begin = getBibEntry(pos_begin);
    }
}
