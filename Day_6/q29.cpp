// Print all duplicate characters in a string

#include<iostream>
#include<vector>
using namespace std;

void printDups(string &s) {
    vector<int> freq(256, 0);
    for(char c : s)
        freq[c]++;

    for(int i = 0; i<256; i++) {
        if(freq[i] >= 2) {
            cout << (char)i << ": " << freq[i] << endl;
        }
    }
}

int main() {
    string s = "adsgasfdsvklgukv";
    printDups(s);
    return 0;
}