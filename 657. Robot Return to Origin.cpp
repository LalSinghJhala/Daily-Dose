#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int ups = 0, downs = 0, lefts = 0, rights = 0;
        
        for(char ch : moves) {
            if(ch == 'U') {
                ups++;
            }
            else if(ch == 'D') {
                downs++;
            }
            else if(ch == 'L') {
                lefts++;
            }
            else {
                rights ++;
            }
        }
        return lefts == rights && ups == downs;
           
    }
};