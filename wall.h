#include <unordered_map>
#include <map>
#include <list>

using namespace std;

class Wall
{
private:

public:
    Wall();

    vector<unordered_map<string, string>> insertHash(string);
    vector<string> solveHashVec(vector<string>, unordered_map<string, string>, unordered_map<string, string>);
    list<string> solveHashList(list<string>, unordered_map<string, string>, unordered_map<string, string>);

    map<string, string> insertMap(string);
    vector<string> solveMapVec(vector<string>, map<string, string>);
    list<string> solveMapList(list<string>, map<string, string>);
};