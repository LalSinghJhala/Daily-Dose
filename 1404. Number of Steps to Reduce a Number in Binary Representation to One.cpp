#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
       int steps = 0;
       int carry = 0;
       int n = s.size();
       for(int i = n-1; i > 0; i--) {
        int bit = (s[i] - '0') + carry;
        if(bit % 2 == 1) {
            carry = 1;
            steps += 2;
        }
        else {
                steps += 1;
            }
       }
            if(carry) {
                steps++;
            }

       return steps;
    }


};







/*


method -1 '


class Solution {
public:

    void addOne(string& s) {
        int i = s.length()-1;
        while(i >=0 && s[i] != '0') {
            s[i] = '0';
            i--;
        }
        if(i < 0) {
            s = '1' + s;
        }
        else {
            s[i] = '1';
        }
        
    }


    int numSteps(string s) {
        int op = 0;
        while(s.length() > 1) {
            int n = s.length();
            if(s[n-1] == '0') {
                s.pop_back();
            }
            else {
                addOne(s);
            }
            op++;
        }

        return op;
    }
};





**/

/**

        this method will give you runtime error 


 bool isEven(int n) {
        return n%2 == 0;
    }
    bool isOdd(int n) {
        return n%2 != 0;
    }




 int numSteps(string s) {
        int count = 0;
        int number = stoi(s, nullptr, 2);
        if(number <= 1) {
            return 0;
        }
        while(number > 1) {
            if(isEven(number)) {
                number = number/2;
                count++;
            }
            else if(isOdd(number)) {
                number = number + 1;
                count++;
            }
        }
        return count;
    }
};







**/



