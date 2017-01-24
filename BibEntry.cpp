#include <cctype>
#include "BibString.h"
#include "BibEntry.h"
#include "MyFunctions.h"

namespace CBibTeX
{
    BibEntry::BibEntry()
    {}

    BibEntry::BibEntry(const BibString& str_BibEntryType, const BibString& str_BibEntryBody)
    {
        initialize(str_BibEntryType, str_BibEntryBody);
        //type = getType(str_BibEntryType);
        //key = getKey(str_BibEntryBody);
        //fields = getFields(str_BibEntryBody);
    }

    void CBibTeX::BibEntry::initialize(const BibString & str_BibEntryType, const BibString & str_BibEntryBody)
    {
        type = getType(str_BibEntryType);
        key = getKey(str_BibEntryBody);
        fields = getFields(str_BibEntryBody);
    }

    BibEntryType BibEntry::getType(const BibString& str_BibEntryType)
    {
        BibString temp_str_BibEntryType(str_BibEntryType, 1);

        for (auto& ch : temp_str_BibEntryType)
            ch = toupper(ch);

        // TODO: 20170124  remove space.

        for (auto iter = map_BibEntry.begin(); iter != map_BibEntry.end(); ++iter)
        {
            if (temp_str_BibEntryType == iter->second)
                return iter->first;
        }

        // TODO: 20170124  need to return an error.
        return BibEntryType(-1);
    }

    BibString BibEntry::getKey(const BibString& str_BibEntryBody)
    {
        auto pos_beginKey = 1;
        auto pos_endKey = findCharacter(str_BibEntryBody, ',');

        auto len_Key = pos_endKey - pos_beginKey;

        return BibString(str_BibEntryBody, pos_beginKey, len_Key);
    }

    BibFieldSet BibEntry::getFields(const BibString& str_BibEntryBody)
    {
        return BibFieldSet();
    }
}
