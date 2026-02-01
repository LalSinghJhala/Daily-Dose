#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int cost = nums[0];
        int mini = INT_MAX;
        int secondMini = INT_MAX;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < mini) {
                secondMini = mini;
                mini = nums[i];
            }
            else if(nums[i] < secondMini ) {
                secondMini = nums[i];
            }
        }
        return cost + mini + secondMini;
    }
};