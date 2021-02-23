
/*
ID: msarkar4
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("friday.in");
ofstream fout ("friday.out");

int n;
// number of days on 13th. Index 0 <- Sat, 1 <- Sun, 2 <- Mon, ... 6 <- Fri
int friday[7];
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};        // days in each month

bool is_leapyear (int year) {
   return !(year%100)?!(year%400):!(year%4);
}

int main() {
    fin >> n;
	
    // January 1, 1900 was Monday, Thus, Jan 8 and Jan 15 was Monday as well. Thus, Jan 13, 1900 was Saturday
    friday[0] = 1;
    int prev = 0;

    int year = 1900;
    int month = 1;
    while(true) {
        int day = (is_leapyear(year) && month == 2)?29:days[month];     // day to add for next 13th
        prev = (prev + day) % 7;                    // day on which current friday is falling
        friday[prev]++;

        month++;
        if(month == 12 && year == 1900+n-1)
            break;

        if(month == 13) {
            year++;
            month = 1;
        }
    }

    fout << friday[0];
    for(int i=1; i<7; i++)
        fout << " " << friday[i];
    fout << endl;
    return 0;
}
