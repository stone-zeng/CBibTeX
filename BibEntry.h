#ifndef _BIB_ENTRY_H_
#define _BIB_ENTRY_H_

#include <map>
#include <string>
#include "BibFields.h"
#include "BibString.h"

namespace CBibTeX
{
    enum BibEntryType
    {
        Article,
        Book,
        Booklet,
        Conference,
        Inbook,
        Incollection,
        Inproceedings,
        Manual,
        Mastersthesis,
        Misc,
        Phdthesis,
        Proceedings,
        Techreport,
        Unpublished
    };

    const std::map<BibEntryType, BibString> map_BibEntry = {
        { Article,         "ARTICLE" },
        { Book,            "BOOK" },
        { Booklet,         "BOOKLET" },
        { Conference,      "CONFERENCE" },
        { Inbook,          "INBOOK" },
        { Incollection,    "INCOLLECTION" },
        { Inproceedings,   "INPROCEEDINGS" },
        { Manual,          "MANUAL" },
        { Mastersthesis,   "MASTERSTHESIS" },
        { Misc,            "MISC" },
        { Phdthesis,       "PHDTHESIS" },
        { Proceedings,     "PROCEEDINGS" },
        { Techreport,      "TECHREPORT" },
        { Unpublished,     "UNPUBLISHED" }
    };

    class BibEntry
    {
    private:
        //BibString str_BibEntry_Data;

        // 获取 Bib 条目
        BibEntryType getType(const BibString& str_BibEntryType);
        BibString getKey(const BibString& str_BibEntryBody);
        BibFieldSet getFields(const BibString& str_BibEntryBody);

    public:
        BibEntry();
        // 参数：条目类型，条目主体
        // 二者分开的原因：减少循环次数 -> 见 BibData.cpp :: getBibEntryList()
        BibEntry(const BibString& str_BibEntryType, const BibString& str_BibEntryBody);

        //void initialize(const BibString& str_BibEntryType, const BibString& str_BibEntryBody);

        BibEntryType type;
        BibString key;
        BibFieldSet fields;

        //typedef std::string Bib_Type_Key;
        //
        //typedef std::string Bib_Type_Address;
        //typedef std::string Bib_Type_Author;
        //typedef std::string Bib_Type_BookTitle;
        //typedef std::string Bib_Type_Chapter;
        //typedef std::string Bib_Type_CrossRef;
        //typedef std::string Bib_Type_Edition;
        //typedef std::string Bib_Type_Editor;
        //typedef std::string Bib_Type_HowPublished;
        //typedef std::string Bib_Type_Institution;
        //typedef std::string Bib_Type_Month;
        //typedef std::string Bib_Type_Note;
        //typedef std::string Bib_Type_Number;
        //typedef std::string Bib_Type_Organization;
        //typedef std::string Bib_Type_Pages;
        //typedef std::string Bib_Type_Publisher;
        //typedef std::string Bib_Type_School;
        //typedef std::string Bib_Type_Series;
        //typedef std::string Bib_Type_Title;
        //typedef std::string Bib_Type_Type;
        //typedef std::string Bib_Type_Volume;
        //typedef int Bib_Type_Year;
    };
}

#endif