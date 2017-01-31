#ifndef _BIB_ENTRY_H_
#define _BIB_ENTRY_H_

#include <map>
#include <string>
#include "BibFields.h"
#include "BibString.h"

namespace CBibTeX
{
    enum enum_BibEntry
    {
        $_Article,
        $_Book,
        $_Booklet,
        $_Conference,
        $_Inbook,
        $_Incollection,
        $_Inproceedings,
        $_Manual,
        $_Mastersthesis,
        $_Misc,
        $_Phdthesis,
        $_Proceedings,
        $_Techreport,
        $_Unpublished
    };

    const std::map<enum_BibEntry, BibString> map_BibEntry =
    {
        { $_Article,           "ARTICLE" },
        { $_Book,              "BOOK" },
        { $_Booklet,           "BOOKLET" },
        { $_Conference,        "CONFERENCE" },
        { $_Inbook,            "INBOOK" },
        { $_Incollection,      "INCOLLECTION" },
        { $_Inproceedings,     "INPROCEEDINGS" },
        { $_Manual,            "MANUAL" },
        { $_Mastersthesis,     "MASTERSTHESIS" },
        { $_Misc,              "MISC" },
        { $_Phdthesis,         "PHDTHESIS" },
        { $_Proceedings,       "PROCEEDINGS" },
        { $_Techreport,        "TECHREPORT" },
        { $_Unpublished,       "UNPUBLISHED" }
    };


    enum enum_BibField
    {
        $_Address,
        $_Author,
        $_BookTitle,
        $_Chapter,
        $_CrossRef,
        $_Edition,
        $_Editor,
        $_HowPublished,
        $_Institution,
        $_Month,
        $_Note,
        $_Number,
        $_Organization,
        $_Pages,
        $_Publisher,
        $_School,
        $_Series,
        $_Title,
        $_Type,
        $_Volume,
        $_Year,
    };

    const std::map<enum_BibField, BibString> map_BibField =
    {
        { $_Address,           "ADDRESS" },
        { $_Author,            "AUTHOR" },
        { $_BookTitle,         "BOOKTITLE" },
        { $_Chapter,           "CHAPTER" },
        { $_CrossRef,          "CROSSREF" },
        { $_Edition,           "EDITION" },
        { $_Editor,            "EDITOR" },
        { $_HowPublished,      "HOWPUBLISHED" },
        { $_Institution,       "INSTITUTION" },
        { $_Month,             "MONTH" },
        { $_Note,              "NOTE" },
        { $_Number,            "NUMBER" },
        { $_Organization,      "ORGANIZATION" },
        { $_Pages,             "PAGES" },
        { $_Publisher,         "PUBLISHER" },
        { $_School,            "SCHOOL" },
        { $_Series,            "SERIES" },
        { $_Title,             "TITLE" },
        { $_Type,              "TYPE" },
        { $_Volume,            "VOLUME" },
        { $_Year,              "YEAR" }
    };


    class BibEntry
    {
    private:
        // 获取 Bib 条目
        void getType(const BibString& str_BibEntryType);
        void getKey(const BibString& str_BibEntryBody);
        void getFields(const BibString& str_BibEntryBody);

    public:
        BibEntry() = default;
        // 参数：条目类型，条目主体
        // 二者分开的原因：减少循环次数 -> 见 BibData.cpp :: getBibEntryList()
        BibEntry(const BibString& str_BibEntryType, const BibString& str_BibEntryBody);

        enum_BibEntry type;
        BibString key;
        BibFields fields;
    };
}

#endif