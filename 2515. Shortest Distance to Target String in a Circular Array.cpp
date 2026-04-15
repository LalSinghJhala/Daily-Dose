#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int straightDis = abs(i-startIndex);
                int cirDis = n - straightDis;
                ans = min({ans,straightDis, cirDis});
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};