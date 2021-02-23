
/*
ID: msarkar4
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

ifstream fin ("gift1.in");
ofstream fout ("gift1.out");

vector<string> names (11);
map<string, int> amount;

int main() {
    int n;
    fin >> n;

    for(int i=0; i<n; i++) {
        fin >> names[i];
        amount[names[i]] = 0;
    }

    for(int i=0; i<n; i++) {
        string giver;
        int amt, fc;

        fin >> giver >> amt >> fc;
        if(fc) {
            int phead = amt/fc;                  // amount per head
            amount[giver] -= (phead * fc);

            while(fc--) {
                string receiver;
                fin >> receiver;
                amount[receiver] += phead;
            }
        }
    }

    for(int i=0; i<n; i++)
        fout << names[i] << " "<< amount[names[i]] << endl;
	return 0;
}
