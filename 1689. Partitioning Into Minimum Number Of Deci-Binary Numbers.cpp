#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for(char ch : n) {
            if(ch -'0' > maxDigit) {
                maxDigit = ch -'0';
            }
        }
        return maxDigit;
    }
};