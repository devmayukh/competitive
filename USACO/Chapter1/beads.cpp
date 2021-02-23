
/*
ID: msarkar4
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin ("beads.in");
ofstream fout ("beads.out");

int n;
string necklace;

// maximum run of beads from a particular index. if dir is true, searching in right direction, otherwise searching in
// left direction. In the right direction, searching from next bead will be made, otherwise while searching in both
// left and right direction, current index will be included twice
int get_run(int index, bool dir) {
    if(dir)
        index++;

    int length = 0;
    while(necklace[index] == 'w') {
        length++;
        if((dir && ++index == 2*n) || (!dir && --index == -1))
            return length;
    }

    char color = necklace[index];
    while(necklace[index] == color || necklace[index] == 'w')
    {
        length++;
        if((dir && ++index == 2*n) || (!dir && --index == -1))
            return length;
    }
    
    return (length > n)?n:length;
}

int main() {
    fin >> n >> necklace;

    necklace += necklace;                       // attach the string with itself. now it is of length 2n
    int max_len = 0;
    for(int i=0; i<n; i++) {
        int len = get_run(i, false) + get_run(i, true);
        if(len > n)
            len = n;
        max_len = (len > max_len)?len:max_len;
    }

    fout << max_len << endl;
	return 0;
}
