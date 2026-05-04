#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> transpose(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                transpose[i][j] = matrix[j][i];
            }
        }
        for(int i = 0; i < transpose.size(); i++) {
            reverse(transpose[i].begin(), transpose[i].end());
        }
        for(int i = 0; i < transpose.size(); i++) {
            for(int j = 0; j < transpose[0].size(); j++) {
                matrix[i][j] = transpose[i][j];
            }
        }
        return;
    }
};