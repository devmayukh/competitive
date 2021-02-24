
/*
ID: msarkar4
LANG: C++
TASK: combo
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("combo.in");
ofstream fout ("combo.out");

int n;
int f1, f2, f3;
int m1, m2, m3;
int valid;
// hash of a lock triplet. For lock (l1, l2, l3), the hash will be 101*101*l1 + 101*l2 + l3, as maximum possible value 
// of a lock is 100.
bool lhash[1030301];            

#define hash(l1, l2, l3)                    (101 * 101 * l1 + 101 * l2 + l3)

// map the lock value within 1 and n
int map(int lock) {
    if(lock < 1)
        return map(n + lock);
    if(lock > n)
        return map(lock - n);
    return lock;
}

void get_lock_count(int l1, int l2, int l3) {
    for(int i=l1-2; i<=l1+2; i++) {
        for(int j=l2-2; j<=l2+2; j++) {
            for(int k=l3-2; k<=l3+2; k++) {
                int h = hash(map(i), map(j), map(k));
                if(!lhash[h]) {
                    lhash[h] = true;
                    valid++;
                }
            }
        }
    }
}

int main() {
    fin >> n >> f1 >> f2 >> f3 >> m1 >> m2 >> m3;
    get_lock_count(f1, f2, f3);
    get_lock_count(m1, m2, m3);
    
    fout << valid << endl;
	return 0;
}
