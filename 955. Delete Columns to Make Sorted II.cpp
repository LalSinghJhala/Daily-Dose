#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deletions = 0;

        vector<bool> sorted(rows - 1, false);

        for (int c = 0; c < cols; c++) {
            bool bad = false;

            // check violation
            for (int r = 0; r < rows - 1; r++) {
                if (!sorted[r] && strs[r][c] > strs[r+1][c]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                deletions++;
                continue;
            }

            // update sorted status
            for (int r = 0; r < rows - 1; r++) {
                if (!sorted[r] && strs[r][c] < strs[r+1][c]) {
                    sorted[r] = true;
                }
            }
        }

        return deletions;
    }
};
