#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int totalApple = 0;
        for(int i = 0; i < n; i++) {
            totalApple+=apple[i];
        }
        sort(capacity.begin(), capacity.end());
        int count = 0;
        int m = capacity.size();
        for(int i = m-1; i>=0; i--) {
            totalApple = totalApple-capacity[i];
            count++;
            if(totalApple <= 0) {
                break;
            }
        }
        return count;
     }
};