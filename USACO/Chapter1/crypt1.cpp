
/*
ID: msarkar4
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("crypt1.in");
ofstream fout ("crypt1.out");

int n;
int digits[10];
bool is_digit[10];

bool is_valid(int num) {
    while(num) {
        if(!is_digit[num%10])
            return false;

        num /= 10;
    }
    return true;
}

int main() {
    fin >> n;
    for(int i=0; i<n; i++) {
        fin >> digits[i];
        is_digit[digits[i]] = true;
    }

    // First create all possible two digit and three digit numbers out of the input digits.
    int num2s[100], n2count = 0;
    int num3s[1000], n3count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int num2 = digits[i] * 10 + digits[j];
            num2s[n2count++] = num2;
            
            for(int k=0; k<n; k++)
                num3s[n3count++] = num2 * 10 + digits[k];
        }
    }

    // Now check multiplication between all possible 2 digit and 3 digit numbers thus generated
    int valid = 0;
    for(int i=0; i<n3count; i++) {
        int num3 = num3s[i];
        for(int j=0; j<n2count; j++) {
            int num2 =  num2s[j];

            // partial multiplication results
            int part1 = num3 * (num2 % 10);
            int part2 = num3 * (num2 / 10);

            // They should be of three digits, and must contain the input digits
            if(part1 < 100 || part1 > 999 || part2 < 100 || part2 > 999 || !is_valid(part1) || !is_valid(part2))
                continue;

            // final multiplication should be of 4 digits and must contain the input digits 
            int mult = num3 * num2;
            if(mult >= 1000 && mult <= 9999 && is_valid(mult))
                valid++;
        }
    }

    fout << valid << endl;
	return 0;
}
