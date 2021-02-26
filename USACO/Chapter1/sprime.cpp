
/*
ID: msarkar4
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("sprime.in");
ofstream fout ("sprime.out");

int n;
vector<int> sprimes;

bool is_prime(int num) {
    if(num < 4)
        return (num > 1);
    if(num%2 == 0 || num%3 == 0)
        return false;

    for(int i=5; i*i <= num; i+=6) {
        if(num%i == 0 || num%(i+2) == 0)
            return false;
    }
    return true;
}

// Perform DFS to generate superprimes. Check if num is prime. If it is not, this number cannot generate superprime in
// any way. Otherwise, attach another odd digit (1, 3, 7 or 9) after this and recursively invoke get_sprime (Attaching
// 5 never gives a prime, unless it generates only 5 itself).
void get_sprime(int num, int digit) {
    if(!is_prime(num))
        return;
    if(digit == n) {
        sprimes.push_back(num);
        return;
    }

    get_sprime(10*num + 1, digit + 1);
    get_sprime(10*num + 3, digit + 1);
    get_sprime(10*num + 7, digit + 1);
    get_sprime(10*num + 9, digit + 1);
}

int main() {
    fin >> n;

    // while invoking get_sprime recursive procedure with single digit, we need to send primes as the possible option,
    // because only they can generate possible superprimes
    get_sprime(2, 1);
    get_sprime(3, 1);
    get_sprime(5, 1);
    get_sprime(7, 1);

    for(vector<int>::iterator it = sprimes.begin(); it != sprimes.end(); ++it)
        fout << *it << endl;
	
    return 0;
}
