/*
    题目：122. 买卖股票的最佳时机2
    链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
    时间：2020-7-10        
    BY Kromite

    解题技巧： 此题是贪心问题基础题。
    一般来说最大利润就是直接继续增加加数组的连续数字之间的差值，如果第二个数字大于第一个数字，我们获得的总和将是最大利润
*/
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)    return 0;
        int max=0;
        for(int i=1;i!=prices.size();i++){
            if(prices[i]>prices[i-1])
                max += prices[i]-prices[i-1];
        }
        return max;
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
