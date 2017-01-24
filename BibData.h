#ifndef _BIB_DATA_H_
#define _BIB_DATA_H_

#include <vector>
#include "BibString.h"
#include "BibEntry.h"

// Get and handle Bib database.
class BibData
{
public:
    BibData();
    BibData(const BibString& fileName);

    // Original Bib data in string format.
    BibString str_BibData;

    // Bib entry list in a BibEntry vector.
    std::vector<BibEntry> vec_bibEntryList;

    void deleteComment();
    BibString::size_type getOneBibEntry(const BibString::size_type& pos_begin);
    void getBibEntryList();
};

#endif