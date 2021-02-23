
/*
ID: msarkar4
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

ifstream fdata ("dict.txt");
ifstream fin ("namenum.in");
ofstream fout ("namenum.out");

int num_map[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
map<string, string> name_map;

void init() {
    string name;
    while(fdata >> name) {
        string num = "";
        for(int i=0; i < (int)name.length(); i++)
            num += (char)(num_map[name[i] - 'A'] + '0');
        name_map[name] = num;
    }
}

int main() {
    init();
    
    string number;
    fin >> number;
    bool found = false;
    for(map<string, string>::iterator it = name_map.begin(); it != name_map.end(); ++it) {
        if(it->second == number) {
            found = true;
            fout << it->first << endl;
        }
    }

    if(!found)
        fout << "NONE\n";
	return 0;
}
