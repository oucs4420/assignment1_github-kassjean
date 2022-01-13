//  Author: Kassady Herriott
//  Assignment: Homework 1
//  Class: CS4420 - Operating Systems
//  Professor: Ostermann
//  Date: 13 January 2022

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    // stream for the files and variables for file name, line counts, bool to
    // check for empty file case
    ifstream testFile;
    string fileName = "";
    int all_lines = 0;
    string line = "";

    // grabs the program name from the first argument
    cout << "program: " << argv[0] << endl;

    // iterates through the arguments given as file names
    for (int arg = 1; arg < argc; ++arg) {
        // sets the file name to the argument given
        fileName = argv[arg];
        testFile.open(fileName);
        // if the file fails to open it outputs the file name and -1
        if (!testFile.is_open()) {
            cout << " " << fileName + ": " << -1 << endl;
        } else {
            // if file opens successfully do this
            while (testFile.peek() != EOF) {
                // adds to total number of lines
                getline(testFile, line);
                all_lines++;
            }
            // outputs the filename and the number of lines associated with it
            cout << " " << fileName + ": " + to_string(all_lines) << endl;
            all_lines = 0;
        }
        // closes files
        testFile.close();
    }
    exit(0);  // this means that the program executed correctly!
}
