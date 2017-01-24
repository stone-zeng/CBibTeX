#include <string>
#include <fstream>
#include <iostream>
#include "MyFunctions.h"
#include "BibString.h"
#include "BibData.h"

using namespace std;

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

BibString::size_type BibData::getOneBibEntry(const BibString::size_type& pos_begin)
{
    // Search for '@' as the begin marker of BibEntry.
    auto pos_beginBibEntry = findCharacter(str_BibData, '@', pos_begin);

    // Test for end position.
    if (pos_beginBibEntry == str_BibData.npos)
        return str_BibData.npos;
    else
    {
        // The characters in '{}' will become the BibEntry body.

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

        // Get the length of BibEntryType (from '@' to '{'-1)
        //               and BibEntryBody (from '{' to '}').

        auto len_BibEntryType = pos_beginBibEntryBody - pos_beginBibEntry;
        auto len_BibEntryBody = pos_endBibEntryBody - pos_beginBibEntryBody;

        // Get one Bib entry.

        BibString str_BibEntryType(str_BibData, pos_beginBibEntry, len_BibEntryType);
        BibString str_BibEntryBody(str_BibData, pos_beginBibEntryBody, len_BibEntryBody);
        
        BibEntry oneEntry(str_BibEntryType, str_BibEntryBody);

        // Append this Bib entry to the end of vec_bibEntryList.

        //char s[1000] = { 0 };
        //strcpy(s, str_BibEntryBody.c_str());
        //cout << str_BibEntryBody.c_str() << endl;

        vec_bibEntryList.push_back(oneEntry);

        // Move the iterator.
        return pos_beginBibEntryBody + 1;
    }
}

void BibData::getBibEntryList()
{
    BibString::size_type pos_begin = 0;

    while (pos_begin != str_BibData.npos && pos_begin < str_BibData.length())
        pos_begin = getOneBibEntry(pos_begin);
}
