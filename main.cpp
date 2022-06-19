/**
 * See leetCode problem description here: https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
 * The tricky part to this problem is that leetCode will supply extremely large numbers that are hard for standard data types to handle
 * The way around this is through second for loop which identifies the larger number by checking the value of each char one by one 
**/


#include <iostream>
using namespace std;

    string removeDigit(string number, char digit) {
        string final = "0";
        string result;
        for (int i = 0; i < number.length(); i++) {
            if (number.at(i) == digit) {
                if (i == 0) {
                    result = number.substr(1);
                } else if (i == number.length() - 1) {
                    result = number.substr(0, number.length()-1);
                } else {
                    result = number.substr(0,i) + number.substr(i+1);
                }
                
                if (final == "0") {
                    final = result;
                } else {
                    for (int i = 0; i < result.length(); i++) {
                        if (result.at(i) > final.at(i)) {
                            final = result;
                            i = result.length();
                        } else if (result.at(i) < final.at(i)) {
                            i = result.length();
                        }
                    }
                }
            }
        }
        return final;
        
    }

int main() {
    
    string result = removeDigit("1231",'1');

    cout<<result<<endl;

    return 0;
    
}
