/*
    题目：70. 爬楼梯
    链接：https://leetcode-cn.com/problems/climbing-stairs/
    时间：2020-7-7        
    BY Kromite

    解题技巧： 此题是dp入门题目，dp的本质把握住： 时间换空间
                               dp的使用条件：   连续，dp[i]的状态只与dp[0]-dp[i-1]有关
                               dp的关键：   找到状态转移方程 即dp[i]与dp[0]-dp[i-1]的关系
*/
#include <vector>

using namespace std;

class Solution{
public:
// 1. 常规dp，空间为O(n)
    int climbStairs1(int n){
        vector<int> dp(n+1);
        if(n<=2)    return n;
        dp[1] = 1, dp[2] = 2;
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
// 2. 常数级dp
    int climbStairs2(int n){
        int a1, a2, a3;
        if(n==1)    return 1;
        a1 = 1, a2 = 2;
        for(int i=3; i<=n; i++){
            a3 = a1+a2;
            a1 = a2;
            a2 = a3;
        }
        return a2;
    }
};  