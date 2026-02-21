#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPrime(int n) {
        if(n < 2) {
            return false;
        }

        for(int i = 2; i * i <= n; i++) {
            if(n%i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if(isPrime(setBits)) {
                ans++;
            }
        }
        return ans;
    }
};










/*

string giveMeBinaryString(int i) {
        string ans = "";
        while(i > 0) {
            int rem = i % 2;
            ans.push_back(rem + '0');
            i = i/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int countSetBits(string str) {
        int count = 0;
        for(char ch : str) {
            if(ch == '1') {
                count ++;
            }
        }
        return count;
    }

    bool isPrime(int n) {
        int count = 0;
        for(int i = 1; i <=n; i++) {
            if((n%i) == 0) {
                count++;
            }
        }
        if(count == 2) {
            return true;
        }
        return false;
    }

*/