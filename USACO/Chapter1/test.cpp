
/*
ID: msarkar4
LANG: C++
TASK: test
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("test.in");
ofstream fout ("test.out");

int main() {
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
	return 0;
}
