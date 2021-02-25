
/*
ID: msarkar4
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("ariprog.in");
ofstream fout ("ariprog.out");

int m, n;
set<int> bisquares;
bool is_bisquare[2*250*250 + 1];            // With M <= 250, and p,q <= M, maximum possible bisquare is 250^2 + 250^2
vector<pair<int, int> > solutions;

int main() {
    fin >> n >> m;

    // first find all possible bisquares
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=m; j++) {
            int bisquare = i*i + j*j;
            bisquares.insert(bisquare);
            is_bisquare[bisquare] = true;
        }
    }

    // now search for possible APs of length n. An AP must start at some bisquare.
    for(set<int>::iterator it=bisquares.begin(); it != bisquares.end(); ++it) {
        int start = *it;
        // Now, maximum possible number at the end of AP is 2*m*m. If d be the difference among the elements of the AP, 
        // start + (n-1)*d <= 2*m*m; => d <= (2*m*m - start) / (n-1). Thus we will search for all possible differences
        // upto d, starting from 'start' and will check whether all n elements belong to the set of bisquares
        int maxd = (2*m*m - start) / (n-1);
        for(int d = 1; d <= maxd; d++) {
            bool is_valid = true;
            int a = start;
            // now starting with 'a' and difference 'd', check next (n-1) numbers of the AP, whether they are bisquare.
            for(int i = 1; i <= n-1; i++) {
                a += d;
                if(!is_bisquare[a]) {
                    is_valid = false;
                    break;
                }
            }

            if(is_valid)
                solutions.push_back(make_pair(d, start));
        } 
    }

    sort(solutions.begin(), solutions.end());

    for(vector<pair<int, int> >::iterator it=solutions.begin(); it != solutions.end(); ++it)
        fout << it->second << " " << it->first << endl;

    if(solutions.empty())
        fout << "NONE\n";
    return 0;
}
