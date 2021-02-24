
/*
ID: msarkar4
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("barn1.in");
ofstream fout ("barn1.out");

int m, s, c;
int occupied[201];

int main() {
    fin >> m >> s >> c;
    for(int i=0; i<c; i++)
        fin >> occupied[i];

    // if we already have more boards than occupied stalls, we will simply cover each cow individually
    if(m >= c) {
        fout << c << endl;
        return 0;
    }
    sort(occupied, occupied+c);

    int gaps[c];                      // length of gaps between consecutive occupied stalls
    for(int i=0; i<c-1; i++)
        gaps[i] = occupied[i+1] - occupied[i] - 1; 

    sort(gaps, gaps+c-1);               // sort the gaps according to their length
    
    // there will be (m-1) gaps between m boards. So, to minimize the total length of boards, let these (m-1) gaps be
    // the largest (m-1) of the gaps between occupied blocks
    int total_gap = 0;
    for(int i=0, j=c-2; i<m-1; i++, j--)
        total_gap += gaps[j];

    // this total_gap will remain uncovered, and from first occupied stall to last occupied stall, there are total of
    // (last-first+1) stalls. thus, total blocked stall will be (last-first+1) - total_gap
    fout << (occupied[c-1] - occupied[0] + 1) - total_gap << endl;

    return 0;
}
