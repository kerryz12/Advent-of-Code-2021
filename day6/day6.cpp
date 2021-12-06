#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day6.txt");

int part1();
unsigned long long part2();
std::vector<std::string> split(std::string str,std::string sep);

int main(void) {

    while(getline(file, line)) {
        input.push_back(line);
    }

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    vector<int> fish;
    vector<string> temp;
    temp = split(input[0], ",");
    int new_fish = 0;

    for(string s : temp) fish.push_back(stoi(s));

    for(int i = 0; i < 80; ++i) {
        new_fish = 0;

        for(int j = 0; j < fish.size(); ++j) {
            if(fish[j] == 0) {
                fish[j] = 6;
                new_fish++;
            }
            else fish[j]--;
        }

        for(int k = 0; k < new_fish; ++k) fish.push_back(8);
    }

    return fish.size();
}

unsigned long long part2() {
    vector<int> fish;
    vector<string> temp;
    temp = split(input[0], ",");
    vector<unsigned long long> fish_counts;
    unsigned long long temp_fish = 0;
    unsigned long long sum = 0;

    for(string s : temp) fish.push_back(stoi(s));

    for (int i = 0; i < 9; ++i) fish_counts.push_back(0);

    for(int f : fish) {
        fish_counts[f]++;
    }

    for(int i = 0; i < 256; ++i) {
        temp_fish = fish_counts[0];
        fish_counts[0] = fish_counts[1];
        fish_counts[1] = fish_counts[2];
        fish_counts[2] = fish_counts[3];
        fish_counts[3] = fish_counts[4];
        fish_counts[4] = fish_counts[5];
        fish_counts[5] = fish_counts[6];
        fish_counts[6] = fish_counts[7] + temp_fish;
        fish_counts[7] = fish_counts[8];
        fish_counts[8] = temp_fish;
    }

    for(int i = 0; i < 9; ++i) {
        sum += fish_counts[i];
    }

    return sum;
}   

std::vector<std::string> split(std::string str,std::string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}