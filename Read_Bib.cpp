#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "BibData.h"
using namespace std;

int main()
{
    /**********For check time*********/
    LARGE_INTEGER freq;
    LARGE_INTEGER beginTime;
    LARGE_INTEGER endTime;
    QueryPerformanceFrequency(&freq);

    //string fileName("Test_NoCJK.bib");
    ////ifstream inputFile(fileName.c_str(), fstream::in);
    //ifstream inputFile("Test_NoCJK.bib", fstream::in);

    //if (inputFile)
    //{
    //	cerr << "Error: Cannot found the input file " << fileName << ".\n";
    //	exit(1);
    //}


    QueryPerformanceCounter(&beginTime);
    //BibData test("tugboat.bib");
    BibData test("Test_Bib_Data/Test_NoCJK.bib");

    //for (auto i : test.data)
    //	cout << i;
    //cout << endl;
    //cout << test.data.length() << endl;
    QueryPerformanceCounter(&endTime);
    cout << "Time(read)= " << (double) ((endTime.QuadPart - beginTime.QuadPart) * 1000. / freq.QuadPart) << " ms." << endl << endl;


    //cout << test.data.find('%') << endl;
    //cout << test.data.find("%%") << endl;
    //cout << test.data.find("%%%") << endl;


    QueryPerformanceCounter(&beginTime);
    test.deleteComment();
    QueryPerformanceCounter(&endTime);
    cout << "Time(delete comment)= " << (double) ((endTime.QuadPart - beginTime.QuadPart) * 1000. / freq.QuadPart) << " ms."
        << endl << endl;


    //ofstream out("deleteComment.bib");
    //QueryPerformanceCounter(&beginTime);
    //for (auto i : test.data)
    //	out << i;
    //out << endl;
    //cout << test.data.length() << endl;
    //QueryPerformanceCounter(&endTime);
    //cout << "Time= " << (double) ((endTime.QuadPart - beginTime.QuadPart) * 1000. / freq.QuadPart) << " ms." << endl << endl;
    //out.close();


    QueryPerformanceCounter(&beginTime);
    test.getBibEntryList();
    QueryPerformanceCounter(&endTime);
    cout << "Time(get Bib entry)= " << (double) ((endTime.QuadPart - beginTime.QuadPart) * 1000. / freq.QuadPart) << " ms."
        << endl << endl;
}