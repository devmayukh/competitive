
/*
ID: msarkar4
LANG: C++
TASK: transform
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("transform.in");
ofstream fout ("transform.out");

int n;
char input[11][11], output[11][11];

// rotate the pattern by 90 degrees clockwise
void rotate(char input[11][11], char output[11][11]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            output[i][j] = input[n-1-j][i];
    }   
}

// reflect the pattern horizontally
void reflect(char input[11][11], char output[11][11]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            output[i][j] = input[i][n-1-j];
    }   
}

bool is_equal(char input[11][11], char output[11][11]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(output[i][j] != input[i][j])
                return false;
        }   
    }
    return true;
}

// check whether output is a rotation of input. if yes, return the rotation number, otherwise return zero
int is_rotation(char input[11][11], char output[11][11]) {
    char temp[11][11], temp2[11][11];
    rotate(input, temp);
    if(is_equal(temp, output))
        return 1;                       // output is 90 degrees rotation of input

    rotate(temp, temp2);
    if(is_equal(temp2, output))
        return 2;                       // output is 180 degrees rotation of input

    rotate(temp2, temp);
    if(is_equal(temp, output))          // output is 270 degrees rotation of input
        return 3;

    return 0;
}

int main() {
    fin >> n;
    for(int i=0; i<n; i++)
        fin >> input[i];
    for(int i=0; i<n; i++)
        fin >> output[i];

    int rotation;
    if((rotation = is_rotation(input, output)) != 0)
        fout << rotation << endl;
    else {
        char temp[11][11];
        reflect(input, temp);
        if(is_equal(temp, output))
            fout << 4 << endl;
        else if(is_rotation(temp, output))
            fout << 5 << endl;
        else if(is_equal(input, output))
            fout << 6 << endl;
        else
            fout << 7 << endl;
    }
	return 0;
}
