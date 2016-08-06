#ifndef _BIB_DATA_H_
#define _BIB_DATA_H_

#include <string>

class BibData
{
public:
	std::string data;
	BibData();

public:
	BibData(const std::string& fileName);

public:
	void deleteComment();
};

#endif