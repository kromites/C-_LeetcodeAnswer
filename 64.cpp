/*
    题目：64. 最小路径和
    链接：https://leetcode-cn.com/problems/minimum-path-sum/
    时间：2020-7-9        
    BY Kromite

    解题技巧： 此题是动态规划基础题，状态转移方程很好找，和62有点像，要画图模拟，适合理解动态规划理论
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)
                    dp[i][j] = grid[0][0];
                else if(i==0)
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(j==0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else    
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};


int main(){
    cout << "please input the rows and columns of two-dimensional array" << endl;
    int m,n;
    cin>> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "please input the numbers in two-dimensional array" << endl;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>> grid[i][j];
    
    Solution solution;
    cout << "the min path sum is: " << solution.minPathSum(grid) <<endl;
    system("pause");
    return 0;
}