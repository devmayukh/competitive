
/*
ID: msarkar4
LANG: C++
TASK: pprime
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("pprime.in");
ofstream fout ("pprime.out");

int a, b;

// The idea is to generate all palindromes between a and b, and to check whether those palindromes are primes.
// No palindromes of even length can be prime except 11, as they are divisible by 11. So, we will search only for
// odd-length palindromes. Moreover, as any prime (except 2) is odd, the last digit (and first digit) must be odd.
bool is_prime(int num) {
    if(num%2 == 0 || num%3 == 0)
        return false;

    for(int i = 5; i*i <= num; i += 6) {
        if(num%i == 0 || num%(i+2) == 0)
            return false;
    }
    return true;
}

int next_7dig_pprime(int num) {
    int d1 = num/1000000;     
    if(!(d1 & 1))       d1++;

    for(; d1 <= 9; d1 += 2) {
        for(int d2=0; d2 <= 9; d2++) {
            for(int d3=0; d3 <= 9; d3++) {
                for(int d4=0; d4 <= 9; d4++) {
                    int next = d1*1000000 + d2*100000 + d3*10000 + d4*1000 + d3*100 + d2*10 + d1;
                    if(next >= num && is_prime(next))
                        return next;
                }
            }
        }
    }
    return -1;          // as b can be at max of 8 digits, there is no need to search for palindromes with 9 digits
}

int next_5dig_pprime(int num) {
    int d1 = num/10000;     
    if(!(d1 & 1))       d1++;

    for(; d1 <= 9; d1 += 2) {
        for(int d2=0; d2 <= 9; d2++) {
            for(int d3=0; d3 <= 9; d3++) {
                int next = d1*10000 + d2*1000 + d3*100 + d2*10 + d1;
                if(next >= num && is_prime(next))
                    return next;
            }
        }
    }
    return next_7dig_pprime(num);
}

int next_3dig_pprime(int num) {
    int d1 = num/100;       // first digit of num. The next palindrome must have either this digit or higher first digit.
    if(!(d1 & 1))       d1++;

    for(; d1 <= 9; d1 += 2) {
        for(int d2=0; d2 <= 9; d2++) {
            int next = d1*100 + d2*10 + d1;
            if(next >= num && is_prime(next))
                return next;
        }
    }
    return next_5dig_pprime(num);
}

// get next prime palindrome greater than or equal to num 
int get_next_pprime(int num) {
    if(num <= 5)
        return 5;
    if(num <= 7)
        return 7;
    if(num <= 11)
        return 11;

    return next_3dig_pprime(num);
}

int main() {
    fin >> a >> b; 

    while(1) {
        int next = get_next_pprime(a);
        if(next > b || next == -1)
            break;

        fout << next << endl;
        a = next + 1;
    }
    return 0;
}
