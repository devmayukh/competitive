
/*
ID: msarkar4
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <fstream>
using namespace std;

#define max(a, b)                       ((a > b)?a:b)

ifstream fin ("numtri.in");
ofstream fout ("numtri.out");

int r;
int triangle[1001][1001];

int main() {
    fin >> r;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=i; j++)
            fin >> triangle[i][j];
    }

    for(int i=2; i<=r; i++) {
        for(int j=1; j<=i; j++) {
            int up = 0, left = 0;
            if(j < i)
                up = triangle[i-1][j];
            if(j > 1)
                left = triangle[i-1][j-1];

            triangle[i][j] += max(up, left);
        }
    }

    int max_sum = triangle[r][1];
    for(int i=2; i<=r; i++)
        max_sum = max(max_sum, triangle[r][i]);

    fout << max_sum << endl;
	return 0;
}
