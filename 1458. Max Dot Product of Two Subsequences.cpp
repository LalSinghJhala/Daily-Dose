#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        vector<int> nextRow(m + 1, INT_MIN);
        vector<int> currRow(m + 1, INT_MIN);

        for (int i = n - 1; i >= 0; i--) {
            // reset current row
            fill(currRow.begin(), currRow.end(), INT_MIN);

            for (int j = m - 1; j >= 0; j--) {
                int take = nums1[i] * nums2[j];
                if (nextRow[j + 1] > 0)
                    take += nextRow[j + 1];

                int skip1 = nextRow[j];
                int skip2 = currRow[j + 1];

                currRow[j] = max({take, skip1, skip2});
            }

            nextRow = currRow;
        }

        return nextRow[0];
    }
};