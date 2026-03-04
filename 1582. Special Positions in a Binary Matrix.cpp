#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int special = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1  && rows[i] == 1 && cols[j] == 1) {
                    special++;
                }
            }
        }
        return special;
    }
};