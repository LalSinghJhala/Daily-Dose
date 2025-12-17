#include <bits/stdc++.h>
using namespace std;



struct Data {
    long long profit, buy, sell;
    Data(long long p=0, long long b=0, long long s=0)
        : profit(p), buy(b), sell(s) {}
};

class Solution {
public:
    static long long maximumProfit(vector<int>& prices, int k) {
        if (prices.empty() || k == 0) return 0;

        int n = prices.size();
        vector<vector<Data>> dp(n, vector<Data>(k + 1));

        int x0 = prices[0];
        for (int t = 0; t <= k; t++) {
            dp[0][t] = Data(0, -x0, x0);
        }

        for (int i = 1; i < n; i++) {
            int x = prices[i];
            for (int t = 1; t <= k; t++) {

                long long p = dp[i-1][t].profit;
                long long b = dp[i-1][t].buy;
                long long s = dp[i-1][t].sell;

                long long prevP = dp[i-1][t-1].profit;

                p = max(p, max(b + x, s - x));
                b = max(b, prevP - x);
                s = max(s, prevP + x);

                dp[i][t] = Data(p, b, s);
            }
        }
        return dp[n-1][k].profit;
    }
};