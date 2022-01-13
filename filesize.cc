//  Author: Kassady Herriott
//  Assignment: Homework 1 Operating Systems
//  Professor: Ostermann
//  Date: 13 January 2022

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1

int main( int argc, char* argv[] )
{
    //stream for the files and variables for file name, line counts, bool to check for empty file case
    ifstream testFile;
    string fileName = "";
    int count = 0;
    int all_lines = 0;
    bool empty;
    string line = "";

    cout << "program: " << argv[0] << endl;

    for (int arg = 1; arg < argc; ++arg){ 
        empty = true;
        fileName = argv[arg];
        testFile.open(fileName);
        //if the file fails to open it outputs -1 
        if (!testFile.is_open()){
            cout << " " << fileName + ": " << -1 << endl; 
        } 
        else{
            //if file opens successfully do this
            while(!testFile.eof()){
                getline(testFile, line);
                //counts total number of lines
                all_lines++;
                //counts number of lines that arent new lines 
                if(line != ""){
                    count++;
                    empty = false;
                }
            }
            if (empty){
                //prints different counts based on empty lines or not
                cout << " " << fileName + ": " + to_string(all_lines) << endl;
            }
            else{
                cout << " " << fileName + ": " + to_string(count) << endl;
            }
            //resets variables 
            count = 0;
            all_lines = 0;
        }
        //closes files 
        testFile.close();
    }
    exit(0); // this means that the program executed correctly!
}
