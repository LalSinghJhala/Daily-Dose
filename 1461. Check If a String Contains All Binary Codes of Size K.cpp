#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;

        int codes = pow(2, k);

        for(int i = k; i <= s.size(); i++) {
            string str = s.substr(i-k, k);
            if(!st.count(str)) {
                st.insert(str);
                codes--;
                
            }
            if(codes == 0) {
                return true;
                }
        }
        return st.size() == pow(2, k);
    }
};