#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void rotateLeft(vector<int>& row) {
       int first = row[0];
       for(int i = 0; i < row.size()-1; i++) {
            row[i] = row[i+1];
       }
       row[row.size()-1] = first;
    }

    void rotateRight(vector<int>& row) {
        int last = row[row.size()-1];
        for(int i = row.size()-1; i > 0; i--) {
            row[i] = row[i-1];
        }
        row[0] = last;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> temp = mat;
        int shifts = k % n; 
        for(int q = 0; q < shifts; q++) {
            for(int i = 0; i < m; i++) {
                    if(i == 0 || i%2 == 0) {
                        rotateLeft(temp[i]);    
                    }
                    else {
                        rotateRight(temp[i]);
                    }  
            }
        }
        return temp == mat;
    }
};







/*00
class Solution {
public:

    void rotateLeft(vector<int>& row) {
        vector<int> temp2;
        for(int i = 1; i < row.size(); i++) {
            temp2.push_back(row[i]);
        }
        temp2.push_back(row[0]);
        row = temp2;
    }

    void rotateRight(vector<int>& row) {
        vector<int> temp2;
        temp2.push_back(row[row.size()-1]);
        for(int i = 0; i < row.size()-1; i++) {
            temp2.push_back(row[i]);
        }
        row = temp2;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> temp = mat;
        for(int q = 0; q < k; q++) {
            for(int i = 0; i < m; i++) {
                    if(i == 0 || i%2 == 0) {
                        rotateLeft(temp[i]);    
                    }
                    else {
                        rotateRight(temp[i]);
                    }  
            }
        }
        return temp == mat;
    }
};

*/