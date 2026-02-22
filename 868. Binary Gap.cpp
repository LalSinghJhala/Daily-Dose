#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    string binaryOfNumber(int n) {
        string str = "";
        while(n > 0) {
            str.push_back(n%2 + '0');
            n/=2;
        }
        reverse(str.begin(), str.end());
        return str;
    }

    int binaryGap(int n) {
        string str = binaryOfNumber(n);
        int prev = -1;
        int maxDist = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '1') {
                if(prev != -1) {
                maxDist = max(maxDist, i - prev);
                }
            prev = i; 
            }
        }
        return maxDist;
    }
};