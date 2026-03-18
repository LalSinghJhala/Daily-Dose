#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countSubmatrices(vector<vector<int>>& grid, int k) {
       
        int m = grid.size();
        int n = grid[0].size();

        // prefix sum
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i > 0) grid[i][j] += grid[i-1][j];
                if(j > 0) grid[i][j] += grid[i][j-1];
                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
            }
        }

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] <= k) count++;
            }
        }

        return count;
         
    }
};


/*

    int sumRegion(vector<vector<int>>& grid, int m, int n) {
        int sum = 0;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                sum += grid[i][j];
            }
        }
        return sum;
    }



     int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // bottom coordinates;
                int sum = sumRegion(grid, i , j );
                if(sum <= k ) {
                    count++;
                }
            }
        }
        return count;
         
    }

*/