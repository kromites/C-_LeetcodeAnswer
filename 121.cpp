/*
    题目：121. 买卖股票的最佳时机
    链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
    时间：2020-7-9        
    BY Kromite

    解题技巧： 此题是动态规划基础题，但是状态转移方程不是很好找，要掌握
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int Min = INT_MAX;
        int n = prices.size();
        if(n<2) return 0;
        vector<int> dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++){
            Min =min(Min, prices[i-1]);
            dp[i]= max(dp[i-1],prices[i]-Min);
        }
        return dp[n-1];
    }
};

int main(int argc, char **argv){
    Solution solution;
    vector<int> prices;
    for(int i=1;i < argc;i++){
        prices.push_back(stoi(argv[i]));
    }
    
    cout << "Best Time to Buy and Sell Stock: " << solution.maxProfit(prices) << endl;
    return 0;
}


