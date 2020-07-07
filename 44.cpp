/*
    题目：44. 通配符匹配
    链接：https://leetcode-cn.com/problems/wildcard-matching/
    时间：2020-7-7        
    BY Kromite

    解题技巧： 此题比较困难，但是一般字符串逐个字符比较匹配一般可以使用
        DFS, 前缀和, 动态规划， 一般动态规划用的比较多，空间换时间
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        bool isMatch(string s, string p){
            int m=s.size(), n = p.size();
            vector<vector<bool>> dp(m+1,vector<bool>(n+1));
            dp[0][0] = true;       // 两个都是空字符的话是匹配的

            // p是要匹配的字符，所以要先看p中开头是否有*，确定true
            for(int i=1;i<=n;i++){
                if(p[i-1]=='*')
                    dp[0][i] = true;
                else
                    break;  
            }
            
            // 开始dp
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(p[j-1]=='*')
                        dp[i][j] = dp[i][j-1] | dp[i-1][j];
                    else if(p[j-1]=='?'|| p[j-1]==s[i-1])
                        dp[i][j] = dp[i-1][j-1];
                }
            }
            return dp[m][n];
        }
};

int main(int argc, char **argv){
    Solution solution;
    string s= argv[1], p=argv[2];
    
    if(solution.isMatch(s, p))
        cout << "Yes, is matching!" << endl;
    else
    {
        cout << "No, is not matching!" << endl;
    }
    
}