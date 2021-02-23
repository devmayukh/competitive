
/*
ID: msarkar4
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("dualpal.in");
ofstream fout ("dualpal.out");

string convert(int num, int base) {
    string out = "";
    while(num) {
        out = (char)(num%base + '0') + out;
        num /= base;
    }
    return out;
}

bool is_palindrome(string num) {
    for(int i=0, j=num.length()-1; i<j; i++, j--) {
        if(num[i] != num[j])
            return false;
    }
    return true;
}

int main() {
    int n, s;
    fin >> n >> s;

    for(s++; n; s++) {
        int pcount = 0;
        for(int i=2; i <= 10; i++) {
            if(is_palindrome(convert(s, i)))
                pcount++;

            if(pcount == 2) {
                fout << s << endl;
                n--;
                break;
            }
        }
    }
	return 0;
}
