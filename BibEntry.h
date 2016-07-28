#ifndef _BIBENTRY_H_
#define _BIBENTRY_H_

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

class BibEntry
{
public:
	BibEntry();
	BibEntryType type;
};

#endif