#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> input;
string line;
ifstream file("day2.txt");

int part1();
int part2();

int main(void) {

    while(getline(file, line)) {
        input.push_back(line);
    }

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    int x = 0;
    int y = 0;

    for (string s : input) {
        if(s[0] == 'f') {
            x += (s[8] - '0');
        }
        if (s[0] == 'd') {
            y += (s[5] - '0');
        }
        if(s[0] == 'u') {
            y -= (s[3] - '0');
        }
    }

    return x * y;
}

int part2() {
    int x = 0;
    int y = 0;
    int aim = 0;

    for (string s : input) {
        if(s[0] == 'f') {
            x += (s[8] - '0');
            y += aim * (s[8] - '0');
        }
        if (s[0] == 'd') {
            aim += (s[5] - '0');
        }
        if(s[0] == 'u') {
            aim -= (s[3] - '0');
        }
    }

    return x * y;
}   