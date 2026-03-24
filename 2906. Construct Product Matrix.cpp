#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> origGrid;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                origGrid.push_back(grid[i][j]  % mod);
            }
        }

        int size = origGrid.size();
        vector<int> pf(size);
        pf[0] = 1;
        for(int i = 1; i < origGrid.size(); i++) {
            pf[i] = (1LL * pf[i-1] * (origGrid[i-1]) % mod) % mod;
        }

        
        vector<int> sf(size);
        sf[size -1 ] = 1;
        for(int i = size - 2; i >= 0; i--) {
            sf[i] = (1LL * sf[i+1] * (origGrid[i+1]) % mod) % mod;
        }

        vector<int> res(size);
        
        for(int i = 0; i < size; i++) {
            res[i] = (1LL * (pf[i]) % mod * (sf[i]) % mod) % mod;
        }

        vector<vector<int>> ans(m, vector<int> (n));
        int ind = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = res[ind];
                ind++;
            }
        }
        return ans;
    }
};



/*

    TLE 

        class Solution {
public:
    const int mod = 12345;
    int computeTotalProd(vector<vector<int>>& grid,int skip_i, int skip_j) {
        int m = grid.size();
        int n = grid[0].size();
        int prod = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == skip_i && j == skip_j) {
                    continue;
                }
                else {
                    prod = (prod * (grid[i][j] % mod)) % mod;
                }
            }
        }
        return prod;
        
    }

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> prodMat(m, vector<int> (n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                prodMat[i][j] = computeTotalProd(grid, i, j);
            }
        }
        return prodMat;
    }
};


    */