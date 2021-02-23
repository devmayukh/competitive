
/*
ID: msarkar4
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin ("ride.in");
ofstream fout ("ride.out");

int get_value (string name) {
    int value = 1;
    for(int i = 0; i < (int)name.length(); i++)
        value = (value * (name[i] - 'A' + 1)) % 47;

    return value;
}

int main() {
    string comet, group;
    fin >> comet >> group;

    if(get_value(comet) == get_value(group))
        fout << "GO\n";
    else
        fout << "STAY\n";
	return 0;
}
