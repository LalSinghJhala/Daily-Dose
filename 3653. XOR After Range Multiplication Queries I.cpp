#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int M = 1e9 + 7;
        for(auto q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            while(l <=r) {
                nums[l] = (1LL * nums[l] * v) % M;
                l += k;
            }
        }
        int ans = 0;
        for(int i : nums) {
            ans ^= i;
        }
        return ans;
    }
};