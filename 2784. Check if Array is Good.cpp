#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num : nums) {
            mpp[num]++;
        }
        int maximum = *max_element(nums.begin(), nums.end());
        for(auto it : mpp) {
            if(it.first == maximum) {
                continue;
            }
            else if(it.second > 1) {
                return false;
            }
        }
        if(nums.size() == maximum+1 && mpp[maximum] == 2) {
        return true;
        }
        return false;
    }
};