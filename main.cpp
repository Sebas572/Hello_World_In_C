/**
 * Compiler command
 * g++ main.cpp -std=c++14 -pthread
 * 
*/

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <vector>
#include "timercpp.h"

using std::this_thread::sleep_for;
using namespace std;

int laps = 0;

string ReplaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

int main() {
    if(laps*2 >= 120) laps = -116;
    Timer t;

    string H_string[6] = {"[]    []  [][][][]  []        []          [][][]        []      []      []    [][][]   [][][]    []        [][][]    []\n","[]    []  []        []        []        []      []      []      []      []  []      [] []   []   []        []    []  []\n","[][][][]  [][][][]  []        []        []      []        []  []  []  []    []      [] [][][]    []        []    []  []\n","[]    []  []        []        []        []      []         [][]    [][]     []      [] []  []    []        []    []    \n","[]    []  [][][][]  [][][][]  [][][][]    [][][]            []      []        [][][]   []    []  [][][][]  [][][]    []\n", "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"};
    if(laps < 0) {
        for(string &element : H_string) {
            string slice (element.begin() - laps, element.end());
            element = slice;
        }
    }else {
        if(laps*2 >= 2) {
            for(string &element : H_string) {
                string slice (element.begin(), element.end()-(((laps*2)-3)));
                element = slice + "\n";
            }
        }
        vector<char> _space(laps*2, ' ');
        string space (_space.begin(), _space.end());

        for(string &element : H_string) {
            element = space + element;
        }
    }

    string animation = "";
    int index = 0;
    for(string element : H_string) {
        string code = "\e[1;34m";
        if(index == 5) code = "\e[1;32m";
        animation += code + element.c_str();
        index++;
    }

    system("clear");
    cout << "\e[1;34m" << animation << endl;
    laps++;
    
    sleep_for(300ms);
    main();
}