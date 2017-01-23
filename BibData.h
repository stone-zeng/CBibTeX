#ifndef _BIB_DATA_H_
#define _BIB_DATA_H_

#include <vector>
#include <string>
#include "BibEntry.h"

// Get and handle Bib database.
class BibData
{
public:
    BibData();
    BibData(const std::string& fileName);

    // Original Bib data in STL string format.
    std::string str_BibData;
    // Bib entry list in a BibEntry vector.
    std::vector<BibEntry> vec_bibEntryList;

    void deleteComment();
    std::string::size_type getBibEntry(const std::string::size_type& pos_begin);
    void getBibEntryList();
};

#endif