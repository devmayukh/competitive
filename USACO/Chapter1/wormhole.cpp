
/*
ID: msarkar4
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("wormhole.in");
ofstream fout ("wormhole.out");

int n;
int x[13], y[13];                    // x and y coordinates of the wormholes
int neighbors[13];                   // immediate right neighbor of an wormhole
int pairs[13];                       // pair of an wormhole

int lcount;                         // number of pairings that can create a loop

// populate the immediate right neighbor array for the wormholes
void get_neighbors() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            // determine whether wormhole j is immediate right neighbor of wormhole i
            // certainly their y coordinate must match, and j being on right of i, j's x coordinate > i's x coordinate
            if(j == i || y[j] != y[i] || x[j] <= x[i])
                continue;

            // now j is on right of i, but there should not be another wormhole k in between
            bool has_inbetween = false;
            for(int k=1; k<=n; k++) {
                if(y[k] == y[j] && x[j] > x[k] && x[k] > x[i]) {
                    has_inbetween = true;
                    break;
                }
            }

            if(!has_inbetween) {
                neighbors[i] = j;
                break;
            }
        }
    }
}

// check whether current pairing forms a loop.
bool is_loop() {
    // place Bessie to enter each wormhole one by one, and check whether one of them creates a loop
    for(int i=1; i<=n; i++) {
        // Let us consider wormhole i to be the starting point of Bessie
        bool dir = true;                // going inside the wormhole
        int current = i;
        while(1) {
            if(dir)
                current = pairs[current];
            else
                current = neighbors[current];

            dir = !dir;
            
            // have we reached the starting situation, or a situation where Bessie will come out of the wormholes and
            // will walk indefinitely on right? In first case, it is creating a loop
            if(dir && (current == i))                   // it is creating a loop
                return true;
            if(!dir && !current)        // Bessie will walk indefinitely on right. Check for next starting position
                break;
        }
    }
    return false;
}

// generate all possible pairs and check whether the pairing creates a loop
void pair_and_check() {
    int unpaired = 0;
    for(int i=1; i<=n; i++) {
        if(!pairs[i]) {
            unpaired = i;
            break;
        }
    }

    if(!unpaired) {         // all wormhole has been paired up, check whether the pairing creates a loop
        if(is_loop())
            lcount++;
        return;
    }

    // there is an unpaired wormhole
    for(int i=1; i<=n; i++) {
        if(unpaired != i && !pairs[i]) {             // this is a suitable pair of unpaired wormhole
            pairs[i] = unpaired;
            pairs[unpaired] = i;
            pair_and_check();
            pairs[i] = pairs[unpaired] = 0;
        }
    }
}

int main() {
    fin >> n;
    for(int i=1; i<=n; i++)
        fin >> x[i] >> y[i];

    get_neighbors();
    pair_and_check();

    fout << lcount << endl;
    return 0;
}
