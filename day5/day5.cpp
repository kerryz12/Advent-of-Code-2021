#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day5.txt");

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
    int x1;
    int x2;
    int y1;
    int y2;
    vector<string> xy;
    vector<string> temp;

    vector<vector<int>> grid;
    vector<int> grid_line;

    int count = 0;

    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < 1000; ++j) {
            grid_line.push_back(0);
        }
        grid.push_back(grid_line);
    }

    for(string s : input) {
        xy = split(s, " -> ");
        temp = split(xy[0], ",");
        x1 = stoi(temp[0]);
        y1 = stoi(temp[1]);

        temp = split(xy[1], ",");
        x2 = stoi(temp[0]);
        y2 = stoi(temp[1]);

        if(x1 == x2 || y1 == y2) {
            if(x1 == x2 && y1 == y2) { grid[y1][x1]++; }
            else if(x1 == x2) {
                if(y1 < y2) {
                    for(int y = y1; y <= y2; ++y) {
                        grid[y][x1]++;
                    }
                }
                else {
                    for(int y = y2; y <= y1; ++y) {
                        grid[y][x1]++;
                    }                    
                }
            }
            else {
                if(x1 < x2) {
                    for(int x = x1; x <= x2; ++x) {
                        grid[y1][x]++;
                    }
                }
                else {
                    for(int x = x2; x <= x1; ++x) {
                        grid[y1][x]++;
                    }   
                }
            }
        }
    }

    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < 1000; ++j) {
            if(grid[i][j] >= 2) count++;
        }
    }

    return count;
}

int part2() {
    int x1;
    int x2;
    int y1;
    int y2;
    vector<string> xy;
    vector<string> temp;

    vector<vector<int>> grid;
    vector<int> grid_line;

    int count = 0;

    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < 1000; ++j) {
            grid_line.push_back(0);
        }
        grid.push_back(grid_line);
    }

    for(string s : input) {
        xy = split(s, " -> ");
        temp = split(xy[0], ",");
        x1 = stoi(temp[0]);
        y1 = stoi(temp[1]);

        temp = split(xy[1], ",");
        x2 = stoi(temp[0]);
        y2 = stoi(temp[1]);

        if(x1 == x2 || y1 == y2) {
            if(x1 == x2 && y1 == y2) { grid[y1][x1]++; }
            else if(x1 == x2) {
                if(y1 < y2) {
                    for(int y = y1; y <= y2; ++y) {
                        grid[y][x1]++;
                    }
                }
                else {
                    for(int y = y2; y <= y1; ++y) {
                        grid[y][x1]++;
                    }                    
                }
            }
            else {
                if(x1 < x2) {
                    for(int x = x1; x <= x2; ++x) {
                        grid[y1][x]++;
                    }
                }
                else {
                    for(int x = x2; x <= x1; ++x) {
                        grid[y1][x]++;
                    }   
                }
            }
        }
        else {
            int x = 0;
            int y = 0;

            if(x1 < x2) {
                x = x1;
                if(y1 < y2) {
                    y = y1;
                    while(x <= x2) {
                        grid[y][x]++;
                        x++;
                        y++;
                    }
                }
                else {
                    y = y1;
                    while(y >= y2) {
                        grid[y][x]++;
                        x++;
                        y--;
                    }
                }
            }
            else {
                x = x1;
                if(y1 < y2) {
                    y = y1;
                    while(x >= x2) {
                        grid[y][x]++;
                        x--;
                        y++;
                    }
                }
                else {
                    y = y1;
                    while(y >= y2) {
                        grid[y][x]++;
                        x--;
                        y--;
                    }
                }
            }
        }
    }

    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < 1000; ++j) {
            if(grid[i][j] >= 2) count++;
        }
    }

    return count;
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