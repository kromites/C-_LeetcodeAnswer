/*
    题目：62. 不同路径
    链接：https://leetcode-cn.com/problems/unique-paths/
    时间：2020-7-9        
    BY Kromite

    解题技巧： 此题是动态规划基础题，状态转移方程很好找，要画图模拟
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0;i!=m;i++){
            for(int j=0;j!=n;j++){
                if(i==0||j==0)
                    dp[i][j] =1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, char **argv){
    int m = stoi(argv[1]), n = stoi(argv[2]);
    Solution solution;
    cout << solution.uniquePaths(m,n) << endl;

    system("pause");
    return 0;
}