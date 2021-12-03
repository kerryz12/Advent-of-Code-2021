#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<int> input;
string line;
ifstream file("day1.txt");

int part1();
int part2();

int main(void) {

    while(getline(file, line)) {
        input.push_back(stoi(line));
    }

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    int prev = input[0];
    int counter = 0;

    for (int i : input) {
        if (i > prev) counter++;
        prev = i;
    }

    return counter;
}

int part2() {
    int prev = input[0] + input[1] + input[2];
    int counter = 0;
    int curr = 0;

    for (int i = 1; i < input.size(); ++i) {
        curr = (input[i] + input[i + 1] + input[i + 2]);

        if (curr > prev) {
            counter++;
        }

        prev = curr;
    }

    return counter;
}