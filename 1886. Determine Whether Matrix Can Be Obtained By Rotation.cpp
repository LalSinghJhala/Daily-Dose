#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> rotatMatrxBy90(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[j][i] = mat[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            reverse(temp[i].begin(), temp[i].end());
        }
        return temp;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
       int n = mat.size();
       vector<vector<int>> temp = mat;
       for(int i = 1; i <=4; i++) {
            if(temp == target) {
                return true;
            }
            temp = rotatMatrxBy90(temp);
       }
        return false;
    }
};