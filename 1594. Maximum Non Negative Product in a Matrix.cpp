#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        const int mod = 1e9 + 7;

        vector<vector<long long>> maxDp(m, vector<long long>(n));
        vector<vector<long long>> minDp(m, vector<long long>(n));

        maxDp[0][0] = minDp[0][0] = grid[0][0];

        // fill first column
        for(int i = 1; i < m; i++) {
            maxDp[i][0] = maxDp[i-1][0] * grid[i][0];
            minDp[i][0] = minDp[i-1][0] * grid[i][0];
        }

        // fill first row
        for(int j = 1; j < n; j++) {
            maxDp[0][j] = maxDp[0][j-1] * grid[0][j];
            minDp[0][j] = minDp[0][j-1] * grid[0][j];
        }

        // fill rest
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                long long val = grid[i][j];
                long long a = maxDp[i-1][j] * val;
                long long b = minDp[i-1][j] * val;
                long long c = maxDp[i][j-1] * val;
                long long d = minDp[i][j-1] * val;

                maxDp[i][j] = max({a, b, c, d});
                minDp[i][j] = min({a, b, c, d});
            }
        }

        if(maxDp[m-1][n-1] < 0) return -1;
        return maxDp[m-1][n-1] % mod;
    
    }
};


/*
    TLE because we use recursion approach the time complexity is 2^(m+n);


    class Solution {
public: 
    long long  ans = LLONG_MIN;
    const int mod = 1e9 + 7;
    
    void solve(int i, int j, vector<vector<int>>& grid, long long prod) {
        prod *= grid[i][j];
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j == n-1 ) {
            ans = max(ans, prod);
            return;
        }
        // move down
        if(i+1 < m) {
            solve(i+1, j, grid, prod);
        }
        if(j+1 < n) {
            solve(i, j+1, grid, prod);
        }
    }

    int maxProductPath(vector<vector<int>>& grid) {
        solve(0, 0, grid, 1);
        if(ans < 0 ) {
            return -1;
        }
        else {
        return ans % mod;
        }
    }
};


*/