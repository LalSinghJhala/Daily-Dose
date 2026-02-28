#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
     int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        long result = 0;
        int digits = 0;
        for(int i = 1; i <= n; i++) {
            if( (i & (i-1)) == 0) {
                digits++;
            }
            result = ((result << digits)%M + i)%M; 
        }
        return result;
    }
};







/*

 int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        long result = 0;
        for(int i = 1; i <= n; i++) {
            int digits = log2(i) + 1;
            result = ((result << digits)%M + i)%M; 
        }
        return result;
    }

*/