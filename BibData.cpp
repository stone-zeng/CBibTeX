#include <string>
#include <fstream>
#include <iostream>
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
			data += charTemp;
	}
	else
	{
		//TODO: 20160806  use C++ throw and catch
		cerr << "Error: Cannot found the input file " << fileName << ".\n";
		exit(1);
	}
	inputFile.close();
}

string::size_type findBeginComment(const string& s)
{
	auto pos_beginComment = 0;

	do
	{
		pos_beginComment = s.find('%', pos_beginComment + 1);
	} while (pos_beginComment != 0 && pos_beginComment != s.npos
		&& s[pos_beginComment - 1] == '\\');

	return pos_beginComment;
}

void BibData::deleteComment()
{
	auto pos_beginComment = findBeginComment(data);
	auto pos_endComment = data.find('\n', pos_beginComment);
	do
	{
		data.erase(pos_beginComment, pos_endComment - pos_beginComment);
		pos_beginComment = findBeginComment(data);
		pos_endComment = data.find('\n', pos_beginComment);
	} while (pos_beginComment != data.npos);
	
}

//BibData::BibData(const char*& fileName)
//{
//	ifstream inputFile(fileName, fstream::in);
//	if (inputFile)
//	{
//		cerr << "Error: Cannot found the input file " << fileName << ".\n";
//		exit(1);
//	}
//	else
//	{
//		char charTemp(0);
//		while (inputFile.get(charTemp))
//			data += charTemp;
//	}
//}
//
//ifstream inputFile(fileName, fstream::in);
//if (!inputFile)
//{
//	cerr << "Error: Cannot found the input file " << fileName << ".\n";
//	exit(1);
//}
