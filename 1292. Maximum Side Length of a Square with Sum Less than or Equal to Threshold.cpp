#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findSum(int r1, int c1, int r2, int c2, vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = r1; i <= r2; i++) {
            for(int j = c1; j <= c2; j++) {
                sum += mat[i][j];
            }
        }
        return sum;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int bestSide = 0;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                for(int k = 0; i + k < n && j + k < m; k++) {
                    int r2 = i + k;
                    int c2 = j + k;

                    int val = findSum(i, j, r2, c2, mat);
                    if(val <= threshold) {
                        bestSide = max(bestSide, k + 1);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return bestSide;
    }
};
