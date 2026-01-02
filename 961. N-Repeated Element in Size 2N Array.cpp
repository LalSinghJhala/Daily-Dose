#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int sizee = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < sizee; i++) {
            mpp[nums[i]]++;
        }
        int n = sizee/2;
        for(auto it : mpp) {
            if(it.second == n) {
                return it.first;
            }
        }
        return -1;
    }
};