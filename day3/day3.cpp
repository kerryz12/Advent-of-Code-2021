#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> input;
string line;
ifstream file("day3.txt");

int part1();
int part2();
int b2d(long long n);

int main(void) {

    while(getline(file, line)) {
        input.push_back(line);
    }

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    string gamma = "";
    string epsilon = "";
    int zero = 0;
    int one = 0;

    for (int i = 0; i < 12; ++i) {
        for (string s : input) {
            if(s[i] == '0') zero++;
            else one++;
        }
        if (zero > one) {
            epsilon.push_back('0');
            gamma.push_back('1');
        }
        else {
            epsilon.push_back('1');
            gamma.push_back('0');          
        }
        zero = 0; one = 0;
    }

    return b2d(stoll(gamma)) * b2d(stoll(epsilon));
}

int part2() {
    string oxygen = "";
    string co2 = "";
    int zero = 0;
    int one = 0;
    vector<string> keep_o = input;
    vector<string> keep_co2 = input;

    for (int i = 0; i < 12; ++i) {
        if (keep_o.size() == 1) break;
        
        for (string s : keep_o) {
            if(s[i] == '0') zero++;
            else one++;
        }
        
        if (zero == one) {
            for (int j = 0; j < keep_o.size(); ++j) {
                if (keep_o[j][i] == '0') {
                    keep_o.erase(keep_o.begin() + j);
                    j--;
                }
            }           
        }
        else if (zero > one) {
            for (int j = 0; j < keep_o.size(); ++j) {
                if (keep_o[j][i] == '1') {
                    keep_o.erase(keep_o.begin() + j);
                    j--;
                }
            }
        }
        else {
            for (int j = 0; j < keep_o.size(); ++j) {
                if (keep_o[j][i] == '0') {
                    keep_o.erase(keep_o.begin() + j);
                    j--;
                }
            }  
        }
        zero = 0; one = 0;
    }

    for (int i = 0; i < 12; ++i) {
        if (keep_co2.size() == 1) break;

        for (string s : keep_co2) {
            if(s[i] == '0') zero++;
            else one++;
        }
        if (zero == one) {
            for (int j = 0; j < keep_co2.size(); ++j) {
                if (keep_co2[j][i] == '1') {
                    keep_co2.erase(keep_co2.begin() + j);
                    j--;
                }
            }        
        }
        else if (zero > one) {
            for (int j = 0; j < keep_co2.size(); ++j) {
                if (keep_co2[j][i] == '0') {
                    keep_co2.erase(keep_co2.begin() + j);
                    j--;
                }
            }  
        }
        else {
            for (int j = 0; j < keep_co2.size(); ++j) {
                if (keep_co2[j][i] == '1') {
                    keep_co2.erase(keep_co2.begin() + j);
                    j--;
                }
            }         
        }

        zero = 0; one = 0;
    }

    return b2d(stoll(keep_o[0])) * b2d(stoll(keep_co2[0]));
}   

// or just calculate it online/by hand
int b2d(long long n)
{
    long long num = n;
    int dec_value = 0;
    int base = 1;
    long long temp = num;

    while (temp) {
        long long last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}