
/*
ID: msarkar4
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin ("palsquare.in");
ofstream fout ("palsquare.out");

string convert(int num, int base) {
    string out = "";
    while(num) {
        int rem = num%base;
        if(rem < 10)
            out = (char)(rem + '0') + out;
        else
            out = (char)(rem - 10 + 'A') + out;
        
        num /= base;
    }
    return out;
}

bool is_palindrome(string num) {
    for(int i=0, j = num.length() - 1; i < j; i++, j--) {
        if(num[i] != num[j])
            return false;
    }
    return true;
}

int main() {
    int b;
    fin >> b;

    for(int i=1; i<=300; i++) {
        string square = convert(i*i , b);
        if(is_palindrome(square))
            fout << convert(i, b) << " " << square << endl;
    }
	return 0;
}
