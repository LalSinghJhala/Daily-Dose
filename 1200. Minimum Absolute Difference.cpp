#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findMinimumAbsoulteValue(vector<int>& arr) {
        int miniAbsVal = INT_MAX;
        for(int i = 1; i < arr.size(); i++) {
            if(abs(arr[i-1] - arr[i]) < miniAbsVal) {
                miniAbsVal = abs(arr[i-1] - arr[i]);
            }
        }
        return miniAbsVal;
    }

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int minimumAbsoulteValue = findMinimumAbsoulteValue(arr);
        for(int i = 1 ; i < arr.size(); i++) {
            vector<int> ans;
            if(abs(arr[i] - arr[i-1]) == minimumAbsoulteValue) {
                ans.push_back(arr[i-1]);
                ans.push_back(arr[i]);
            }
            if(ans.size() != 0) {
            res.push_back(ans);
            }
        }
        return res;
    }

};