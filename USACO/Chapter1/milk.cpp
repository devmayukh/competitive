
/*
ID: msarkar4
LANG: C++
TASK: milk
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("milk.in");
ofstream fout ("milk.out");

int n, m;
vector<pair<int, int> > farmers;

int main() {
    fin >> n >> m;
    while(m--) {
        int price, amt;
        fin >> price >> amt;
        farmers.push_back(make_pair(price, amt));
    }

    sort(farmers.begin(), farmers.end());

    int price = 0;
    for(vector<pair<int, int> >::iterator it=farmers.begin(); it != farmers.end(); ++it) {
        if(it->second < n) {            // all milk from this farmer can be bought
            price += (it->second * it->first);
            n -= it->second;
        }
        else {                          // buy exactly n amount of milk from this farmer
            price += (n * it->first);
            break;
        }
    }

    fout << price << endl;
	return 0;
}
