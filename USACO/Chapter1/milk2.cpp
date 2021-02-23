
/*
ID: msarkar4
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("milk2.in");
ofstream fout ("milk2.out");

int n;
vector<pair<int, int> > timings;

int main() {
    fin >> n;
    while(n--) {
        int start, end;
        fin >> start >> end;
        timings.push_back(make_pair(start, end));
    }

    sort(timings.begin(), timings.end());

    vector<pair<int, int> >::iterator it = timings.begin();
    int start = it->first, end = it->second;
    int max_milking = end - start, max_idle = 0;

    for(++it; it != timings.end(); ++it) {
        // if the next farmer starts prior to end of any previous farmer, start will not change, only end will increase
        if(it->first <= end) {
            if(it->second > end) {
                end = it->second;
                if(end - start > max_milking)
                    max_milking = end - start;
            }
        }
        else {
            // there is a gap between starting of current farmer and last end of previous farmers
            if(it->first - end > max_idle)
                max_idle = it->first - end;

            start = it->first;
            end = it->second;
        }
    }

    fout << max_milking << " " << max_idle << endl;
	return 0;
}
