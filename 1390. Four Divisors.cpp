#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0; 
        for(int i =  0; i < nums.size(); i++) {
            int sum = 0;
            int count = 0; 
            for(int j = 1; j *j <= nums[i]; j++) {
                if(nums[i] % j == 0) {
                    int d1 = j; 
                    int d2 = nums[i] / j;
                    if(d1 == d2) {
                        count ++;
                        sum += j;
                    }
                    else {
                        count += 2;
                        sum += d1 + d2;
                    }
                }
                if(count > 4) break;
            }

            if(count == 4) {
                totalSum += sum;
            }

        }
        return totalSum;

    }
};


/*  TLE 

int Totalsum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0; int count = 0;
            for(int j = 1; j <= nums[i]; j++) {
                if(nums[i] % j == 0) {
                    count ++;
                    sum += j;
                }   
            }
             if(count == 4) {
                    Totalsum += sum;
                    
                }
        }
        return Totalsum;


        */