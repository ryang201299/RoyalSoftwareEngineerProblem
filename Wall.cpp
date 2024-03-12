#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <chrono>
#include <utility>
#include <map>
#include <unordered_map>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <list>
#include <string>

#include "wall.h"

using namespace std;

Wall::Wall() {
}

map<string, string> Wall::insertMap(string arg) {

    map<string, string> wall;

    vector<string> fileLines;

    string line;
    ifstream myfile(arg);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            string fileLine = line;
            int len = fileLine.length();
            int x = len - 1;
            int y = x / 2;

            string first = fileLine.substr(0, y);
            string second = fileLine.substr(y + 1, y + y);
            wall[first] = second;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    return wall;
}

vector<unordered_map<string, string>> Wall::insertHash(string arg) {

    unordered_map<string, string> wallNorth;
    unordered_map<string, string> wallSouth;
    vector<unordered_map<string, string>> results;

    string line;
    ifstream myfile(arg);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            string fileLine = line;
            int len = fileLine.length();
            int x = len - 1;
            int y = x / 2;

            string first = fileLine.substr(0, y);
            string second = fileLine.substr(y + 1, y + y);

            wallNorth.insert({ first, second });
            wallSouth.insert({ second, first });
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    results.push_back(wallNorth);
    results.push_back(wallSouth);

    return results;
}

vector<string> Wall::solveHashVec(vector<string> vec, unordered_map<string, string> WallNorth, unordered_map<string, string> WallSouth) { 

    bool match = true;
    bool secondMatch = true;

    std::unordered_map<std::string, string>::const_iterator it = WallNorth.begin();
    string OgChoice = it->first;
    vec.push_back(OgChoice);
    vec.push_back(WallNorth[OgChoice]);
    string choice = OgChoice;

    while (match) {

        it = WallNorth.find(WallNorth[choice]);  

        if (it != WallNorth.end()) {
            vec.push_back(it->second);
            choice = it->first;
        }
        else {
            break;
        }
    }

    while (secondMatch) {
        it = WallSouth.find(OgChoice);

        if (it != WallSouth.end()) {
            vec.insert(vec.begin(), it->second);
            OgChoice = it->second;
        }
        else {
            break;
        }
    }

    for (auto i = vec.begin(); i != vec.end(); ++i) {
          cout << *i << endl;
    }
    return vec;
}

list<string> Wall::solveHashList(list<string> listT, unordered_map<string, string> WallNorth, unordered_map<string, string> WallSouth) {
    bool match = true;
    bool secondMatch = true;

    std::unordered_map<std::string, string>::const_iterator it = WallNorth.begin();
    string OgChoice = it->first;
    listT.push_back(OgChoice);
    listT.push_back(WallNorth[OgChoice]);
    string choice = OgChoice;

    while (match) {

        it = WallNorth.find(WallNorth[choice]);

        if (it != WallNorth.end()) {
            listT.push_back(it->second);
            choice = it->first;
        }
        else {
            break;
        }
    }

    while (secondMatch) {
        it = WallSouth.find(OgChoice);

        if (it != WallSouth.end()) {
            listT.insert(listT.begin(), it->second);
            OgChoice = it->second;
        }
        else {
            break;
        }
    }

    for (auto i = listT.begin(); i != listT.end(); ++i) {
        cout << *i << endl;
    }
    return listT;
}

vector<string> Wall::solveMapVec(vector<string> vec, map<string, string> Wall) {

    map<string, string>::iterator it;

    string choice;
    string OgChoice;

    int count = 0;

    for (it = Wall.begin(); it != Wall.end(); ++it) {
        if (choice == "") {
            choice = it->first;
            OgChoice = choice;
            vec.push_back(choice);
            vec.push_back(Wall[choice]);
            it = Wall.begin();
        }
        if (Wall[choice] == it->first) {
            vec.push_back(it->second);
            if (count >= 1) {
                Wall.erase(choice);
            }
            choice = it->first;
            it = Wall.begin();
            count += 1;
        }
    }

    choice = OgChoice;

    for (it = Wall.begin(); it != Wall.end(); ++it) {
        if (choice == it->second) {
            vec.insert(vec.begin(), it->first);
            choice = it->first;
            it = Wall.begin();
        }
    }

    for (auto i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << endl;
    }
    return vec;
}

list<string> Wall::solveMapList(list<string> listT, map<string, string> Wall) { 
    map<string, string>::iterator it;

    string choice;
    string OgChoice;

    int count = 0;

    for (it = Wall.begin(); it != Wall.end(); ++it) {
        if (choice == "") {
            choice = it->first;
            OgChoice = choice;
            listT.push_back(choice);
            listT.push_back(Wall[choice]);
            it = Wall.begin();
        }
        if (Wall[choice] == it->first) {
            listT.push_back(it->second);
            if (count >= 1) {
            }
            choice = it->first;
            it = Wall.begin();
            count += 1;
        }
    }

    choice = OgChoice;
    for (it = Wall.begin(); it != Wall.end(); ++it) {
        if (choice == it->second) {
            listT.insert(listT.begin(), it->first);
            choice = it->first;
            it = Wall.begin();
        }
    }

    for (auto i = listT.begin(); i != listT.end(); ++i) {
        cout << *i << endl;
    }
    return listT;
} 

int main(int argc, char* argv[]) {

    Wall wallObj;
    vector<string> vec;
    list<string> listT;
    vector<unordered_map<string, string>> resultsVecHash;
    list<unordered_map<string, string>> resultsListHash;

    string arg;

    for (int i = 0; i < argc; ++i) {
        arg = argv[i];
    }

    //uncomment these methods for MAP with Vector --------------------------------------------
    //map<string, string> wall = wallObj.insertMap(arg);
    //vector<string> vecResult = wallObj.solveMapVec(vec, wall);

    //uncomment these methods for MAP with List ----------------------------------------------
    //map<string, string> wall = wallObj.insertMap(arg);
    //list<string> listResult = wallObj.solveMapList(listT, wall);

    //uncomment these methods for UNORDERED_MAP with Vector ----------------------------------
    resultsVecHash = wallObj.insertHash(arg);
    unordered_map<string, string> wallNorth = resultsVecHash[0];
    unordered_map<string, string> wallSouth = resultsVecHash[1];
    vector<string> vecResult = wallObj.solveHashVec(vec, wallNorth, wallSouth);

    //uncomment these methods for UNORDERED_MAP with List ------------------------------------
    /*resultsVecHash = wallObj.insertHash(arg);
    unordered_map<string, string> wallNorth = resultsVecHash[0];
    unordered_map<string, string> wallSouth = resultsVecHash[1];
    list<string> listResult = wallObj.solveHashList(listT, wallNorth, wallSouth);*/

    return 0;
}
