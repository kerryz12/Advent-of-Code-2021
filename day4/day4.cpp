#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> input;
string line;
ifstream file("day4.txt");

int part1();
int part2();
vector<string> split(string str, string sep);

int main(void) {

    while(getline(file, line)) {
        input.push_back(line);
    }

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    vector<string> chosen_s = split(input[0], ",");
    vector<int> chosen;

    vector<vector<vector<int>>> boards;
    string temp_s;
    vector<string> temp_sv;
    vector<int> temp;
    int flag_x = 1;
    int flag_y = 1;
    int sum = 0;

    for(int i = 0; i < (input.size() - 1) / 6; ++i) {
        vector<vector<int>> new_vec;

        for(int j = 0; j < 5; ++j) {
            temp.clear();
            temp_s = input[i * 6 + 2 + j];
            temp_sv = split(temp_s, " ");
            for(string s : temp_sv) temp.push_back(stoi(s));

            new_vec.push_back(temp);
        }

        boards.push_back(new_vec);
    }

    for(string s : chosen_s) chosen.push_back(stoi(s));

    for(int c = 0; c < chosen.size(); ++c) {
        for(int i = 0; i < (input.size() - 1) / 6; ++i) {
            for(int j = 0; j < 5; ++j) {
                for(int k = 0; k < 5; ++k) {
                    if(boards[i][j][k] == chosen[c]) boards[i][j][k] = -1;
                }
            }

            for(int j = 0; j < 5; ++j) {
                for(int k = 0; k < 5; ++k) {
                    if(boards[i][j][k] != -1) { flag_x = 0; }
                    if(boards[i][k][j] != -1) { flag_y = 0; }
                }
                
                if (flag_x || flag_y) {
                    for(int j = 0; j < 5; ++j) {
                        for(int k = 0; k < 5; ++k) {
                            if(boards[i][j][k] != -1) sum += boards[i][j][k];
                        }
                    }

                    return sum * chosen[c];
                }

            flag_x = 1;
            flag_y = 1;
            }
        }
    }

    return -1;
}

int part2() {
    vector<string> chosen_s = split(input[0], ",");
    vector<int> chosen;

    vector<vector<vector<int>>> boards;
    string temp_s;
    vector<string> temp_sv;
    vector<int> temp;
    int flag_x = 1;
    int flag_y = 1;
    int sum = 0;
    vector<int> board_ints;
    int last_board;

    for(int i = 0; i < (input.size() - 1) / 6; ++i) {
        board_ints.push_back(i);
    }

    for(int i = 0; i < (input.size() - 1) / 6; ++i) {
        vector<vector<int>> new_vec;

        for(int j = 0; j < 5; ++j) {
            temp.clear();
            temp_s = input[i * 6 + 2 + j];
            temp_sv = split(temp_s, " ");
            for(string s : temp_sv) temp.push_back(stoi(s));

            new_vec.push_back(temp);
        }

        boards.push_back(new_vec);
    }

    for(string s : chosen_s) chosen.push_back(stoi(s));

    for(int c = 0; c < chosen.size(); ++c) {
        for(int i = 0; i < (input.size() - 1) / 6; ++i) {
            for(int j = 0; j < 5; ++j) {
                for(int k = 0; k < 5; ++k) {
                    if(boards[i][j][k] == chosen[c]) boards[i][j][k] = -1;
                }
            }

            for(int j = 0; j < 5; ++j) {
                for(int k = 0; k < 5; ++k) {
                    if(boards[i][j][k] != -1) { flag_x = 0; }
                    if(boards[i][k][j] != -1) { flag_y = 0; }
                }
                
                if (flag_x || flag_y) {
                    if(board_ints.size() == 1) last_board = board_ints[0];

                    if(board_ints.size() == 0) {
                        for(int j = 0; j < 5; ++j) {
                            for(int k = 0; k < 5; ++k) {
                                if(boards[last_board][j][k] != -1) sum += boards[last_board][j][k];
                            }
                        }

                        return sum * chosen[c];
                    }

                    board_ints.erase(remove(board_ints.begin(), board_ints.end(), i), board_ints.end());
                }

            flag_x = 1;
            flag_y = 1;
            }
        }
    }

    return -1;
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