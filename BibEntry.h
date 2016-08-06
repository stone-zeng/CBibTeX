#ifndef _BIB_ENTRY_H_
#define _BIB_ENTRY_H_

#include <string>

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

typedef std::string Bib_Type_Key;

typedef std::string Bib_Type_Address;
typedef std::string Bib_Type_Author;
typedef std::string Bib_Type_BookTitle;
typedef std::string Bib_Type_Chapter;
typedef std::string Bib_Type_CrossRef;
typedef std::string Bib_Type_Edition;
typedef std::string Bib_Type_Editor;
typedef std::string Bib_Type_HowPublished;
typedef std::string Bib_Type_Institution;
typedef std::string Bib_Type_Month;
typedef std::string Bib_Type_Note;
typedef std::string Bib_Type_Number;
typedef std::string Bib_Type_Organization;
typedef std::string Bib_Type_Pages;
typedef std::string Bib_Type_Publisher;
typedef std::string Bib_Type_School;
typedef std::string Bib_Type_Series;
typedef std::string Bib_Type_Title;
typedef std::string Bib_Type_Type;
typedef std::string Bib_Type_Volume;
typedef int Bib_Type_Year;

class BibEntry
{
public:
	BibEntry();
	BibEntryType type;
	Bib_Type_Key key;

	Bib_Type_Author author;
	Bib_Type_Title title;
	Bib_Type_Year year;
	Bib_Type_Publisher publisher;
};

#endif