
/*
ID: msarkar4
LANG: C++
TASK: skidesign
*/

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

ifstream fin ("skidesign.in");
ofstream fout ("skidesign.out");

int n;
int hills[1001];

int main() {
    fin >> n;
    int minh = 101, maxh = 0;
    for(int i=0; i<n; i++) {
        fin >> hills[i];
        if(hills[i] < minh)
            minh = hills[i];
        if(hills[i] > maxh)
            maxh = hills[i];
    }
    
    int min_cost = INT_MAX; 
    for(int low = minh; low <= maxh-17; low++) {
        // After modifying heights, low will be the height of the lowest hill
        int high = low + 17;                // height of the highest hill
        int cost = 0;
        for(int i=0; i<n; i++) {
            // for each hill, if it is lower than 'low', increase it to 'low', and if it is higher that 'high', reduce
            // it to 'high'
            if(hills[i] < low)
                cost += ((low - hills[i]) * (low - hills[i]));
            else if(hills[i] > high)
                cost += ((hills[i] - high) * (hills[i] - high));
        }
        if(cost < min_cost)
            min_cost = cost;
    }

    fout << min_cost << endl;
	return 0;
}
