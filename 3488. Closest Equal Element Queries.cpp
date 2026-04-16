#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i <n; i++) {
            mpp[nums[i]].push_back(i);
        }
        vector<int> result;
        for(int qi : queries ) {
            int element = nums[qi];
            vector<int>& vec = mpp[element];

            int sz = vec.size();
            
            // no more occurence of this element;
            if(sz == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(vec), end(vec), qi) - begin(vec);
            int res = INT_MAX;

            // right neighbout => pos+1;
            int right = vec[(pos+1)%sz];
            int d = abs(qi - right);
            int circularDist = n-d;
            res = min({res, d, circularDist});

            // left neighbout => pos-1;
            int left = vec[(pos-1+sz)%sz];
             d = abs(qi - left);
            circularDist = n-d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }
        return result;
    }
};






/*
        TLE  O(n^2);

 class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans;

        for(int qi = 0; qi < queries.size(); qi++) {

            int idx = queries[qi];      // actual index in nums
            int target = nums[idx];
            int minDis = INT_MAX;

            for(int j = 0; j < n; j++) {

                if(j == idx) continue;   // skip same index

                if(nums[j] == target) {

                    int straightDis = abs(j - idx);
                    int circularDis = n - straightDis;

                    int best = min(straightDis, circularDis);
                    minDis = min(minDis, best);
                }
            }

            if(minDis == INT_MAX)
                ans.push_back(-1);
            else
                ans.push_back(minDis);
        }

        return ans;
    }
};

*/