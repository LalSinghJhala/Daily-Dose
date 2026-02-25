#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        
        vector<pair<int, int>> binaryAndNum;
        


        for(int i = 0; i < n; i++) {
            binaryAndNum.push_back({__builtin_popcount(arr[i]), arr[i]});
        }


    sort(binaryAndNum.begin(), binaryAndNum.end());

    vector<int> ans ;
    for(int i = 0; i < n; i++) {
        ans.push_back(binaryAndNum[i].second);
    }  

    return ans;

    }
};