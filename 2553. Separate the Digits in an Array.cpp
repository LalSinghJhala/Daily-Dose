#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int num : nums){
            vector<int> arr;
            while(num > 0) {
                int last = num % 10;
                arr.push_back(last);
                num = num/10;
            }
            reverse(arr.begin(), arr.end());
            for(int i : arr) {
                res.push_back(i);
            }
        }
        return res;
    }
};