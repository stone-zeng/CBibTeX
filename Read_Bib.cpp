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

    QueryPerformanceCounter(&beginTime);
    //BibData test("Test_Bib_Data/tugboat.bib");
    //BibData test("Test_Bib_Data/Test_NoCJK.bib");
    BibData test("Test_Bib_Data/biblatex-ieee.bib");

    //for (auto i : test.data)
    //	cout << i;
    //cout << endl;
    //cout << test.data.length() << endl;
    QueryPerformanceCounter(&endTime);
    cout << "Time(read)= " << (double) ((endTime.QuadPart - beginTime.QuadPart) * 1000. / freq.QuadPart) << " ms." << endl << endl;

    QueryPerformanceCounter(&beginTime);
    test.deleteComment();
    QueryPerformanceCounter(&endTime);
    cout << "Time(delete comment)= " << (double) ((endTime.QuadPart - beginTime.QuadPart) * 1000. / freq.QuadPart) << " ms."
        << endl << endl;


    QueryPerformanceCounter(&beginTime);
    test.getBibEntryList();
    QueryPerformanceCounter(&endTime);
    cout << "Time(get Bib entry)= " << (double) ((endTime.QuadPart - beginTime.QuadPart) * 1000. / freq.QuadPart) << " ms."
        << endl << endl;

    for (auto i : test.vec_bibEntryList)
        cout << i.key << endl;
}
