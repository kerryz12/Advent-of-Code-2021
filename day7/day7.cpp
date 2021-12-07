#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day7.txt");

int part1();
int part2();
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
    int fuel = 0;
    int least_fuel = 2147483647;
    vector<string> temp;
    vector<int> crabs;

    temp = split(input[0], ",");
    for(string s : temp) crabs.push_back(stoi(s));

    for(int i = 0; i < crabs.size(); ++i) {
        for(int c : crabs) {
            fuel += (c < i) ? (i - c) : (c - i);
        }
        if(fuel < least_fuel) least_fuel = fuel;
        fuel = 0;
    }

    return least_fuel;
}

int part2() {
    int fuel = 0;
    int least_fuel = 2147483647;
    vector<string> temp;
    vector<int> crabs;

    temp = split(input[0], ",");
    for(string s : temp) crabs.push_back(stoi(s));

    for(int i = 0; i < crabs.size(); ++i) {
        for(int c : crabs) {
            if(c < i) {
                for(int j = 1; j <= (i-c); ++j) {
                    fuel += j;
                }
            }
            else {
                for(int j = 1; j <= (c-i); ++j) {
                    fuel += j;
                }                
            }
        }
        if(fuel < least_fuel) least_fuel = fuel;
        fuel = 0;
    }

    return least_fuel;
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