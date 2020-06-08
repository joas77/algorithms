#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "graph.h"

//using namespace std;
using std::cout;
using std::endl;

int main()
{
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    

    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;
    std::cout<<"hola mundo"<<std::endl;
    std::fstream testFile;
    std::string testFilePath = "input_mostlyCycles_1_8.txt";
    testFile.open(testFilePath);
    if(testFile.is_open())
    {
        cout<< "Reading file" << std::endl;
        int length = testFile.tellg();
        char* data = new char[length];
        testFile.read(data, length);

        std::cout << data<<std::endl;
    }
    else
    {
        std::cout<<"Could not read file " << testFilePath << std::endl;
    }
    testFile.close();

}