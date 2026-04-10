#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
       unordered_map<int, vector<int>> mpp;
       int n = nums.size();
       for(int i = 0; i < n; i++) {
        mpp[nums[i]].push_back(i);
       }
        int ans = 1e9;
        for(auto &it : mpp) {
            vector<int>& arr = it.second;
            if(arr.size() >= 3) {
                for(int i = 0; i+2 < arr.size(); i++) {
                    int dist = 2 * (arr[i+2] - arr[i]);
                    ans = min(ans, dist);
                }
            }
        }

        return ans == 1e9?-1:ans;
    }
};











/*

 O(n^3)

  int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                for(int k = j+1; k < nums.size(); k++) {
                    if(nums[i] == nums[j] && nums[j] ==  nums[k]) {
                        ans = min(ans, abs(i-j) + abs(j-k) + abs(k-i));
                    }
                }
            }
        }
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;



*/