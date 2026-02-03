#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIncreasing(vector<int>& nums, int l, int r) {
        for (int i = l + 1; i <= r; i++) {
            if (nums[i - 1] >= nums[i]) return false;
        }
        return true;
    }

    bool isDecreasing(vector<int>& nums, int l, int r) {
        for (int i = l + 1; i <= r; i++) {
            if (nums[i - 1] <= nums[i]) return false;
        }
        return true;
    }

    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        for (int i = 1; i <= n - 3; i++) {
            for (int j = i + 1; j <= n - 2; j++) {
                if (isIncreasing(nums, 0, i) &&
                    isDecreasing(nums, i, j) &&
                    isIncreasing(nums, j, n - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
