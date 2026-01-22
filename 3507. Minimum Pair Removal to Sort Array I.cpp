#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSorted(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] > nums[i] ) return false;
        }
        return true;
    }

    int minPairSum(vector<int>& nums) {
        int indexofMin = 0;
        int minimumPairSum = INT_MAX;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] + nums[i+1] < minimumPairSum) {
                minimumPairSum = nums[i] + nums[i+1];
                indexofMin = i;
            }
        }
        return indexofMin;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
       while(!isSorted(nums)) {
            int index = minPairSum(nums);
            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);
            operations++;
       }
       return operations;
    }
};