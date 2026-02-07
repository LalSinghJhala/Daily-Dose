#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;
        int ans = 0;

        for(char c : s) {
            if(c == 'b') {
                b_count++;
            } else { // c == 'a'
                ans = min(ans + 1, b_count);
            }
        }
        return ans;
    }
};
