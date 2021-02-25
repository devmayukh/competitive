
/*
ID: msarkar4
LANG: C++
TASK: milk3 
*/

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

ifstream fin ("milk3.in");
ofstream fout ("milk3.out");

int capA, capB, capC;               // capacities of the buckets A, B and C
int amtA, amtB, amtC;               // current amount of milk in buckets A, B and C
set<int> solutions;     
// Each of buckets has maximum cap of 20, just the hash can be chosen as 21*21*A + 21*B + C
bool is_visited[9261];          // with A = B = C = 20, 21*21*A + 21*B + C = 9260

#define hash(a, b, c)               (21 * 21 * a + 21 * b + c)

// pour milk from src to dest bucket. asrc <- amount in src, adest <- amount in dest, cdest <- capacity of dest
void pour(int *asrc, int *adest, int cdest) {
    // after pouring milk from src to dest, total milk in dest = amount in source + amount that was already in dest
    if(*asrc + *adest > cdest) {            // cannot pour complete milk from src
        *asrc = (*asrc + *adest) - cdest;   // amount that will stay in src
        *adest = cdest;                     // dest will be filled up completely        
    }
    else {                                  // pour complete milk in dest
        *adest += *asrc;
        *asrc = 0;
    }
}

// curr variables represent current amount of milk in respective buckets
void solve(int currA, int currB, int currC) {
    if(!currA)
        solutions.insert(currC);
    
    int h = hash(currA, currB, currC);
    if(is_visited[h])
        return;

    is_visited[h] = true;

    // now pour milk form one bucket to another in all possible combinations
    int tempA = currA, tempB = currB, tempC = currC;
    // pour from A to B
    pour(&currA, &currB, capB);
    solve(currA, currB, currC);
    currA = tempA; currB = tempB;
    // pour from A to C
    pour(&currA, &currC, capC);
    solve(currA, currB, currC);
    currA = tempA; currC = tempC;
    // pour from B to A
    pour(&currB, &currA, capA);
    solve(currA, currB, currC);
    currA = tempA; currB = tempB;
    // pour from B to C
    pour(&currB, &currC, capC);
    solve(currA, currB, currC);
    currC = tempC; currB = tempB;
    // pour from C to A
    pour(&currC, &currA, capA);
    solve(currA, currB, currC);
    currA = tempA; currC = tempC;
    // pour from C to B
    pour(&currC, &currB, capB);
    solve(currA, currB, currC);
    currC = tempC; currB = tempB;
}

int main() {
    fin >> capA >> capB >> capC;
    amtA = amtB = 0;
    amtC = capC;

    solve(amtA, amtB, amtC);

    set<int>::iterator it = solutions.begin();
    fout << *it;
    for(++it; it != solutions.end(); ++it)
        fout << " " << *it;
    fout << endl;

	return 0;
}
