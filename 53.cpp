/*
    题目：53. 最大子序和
    链接：https://leetcode-cn.com/problems/maximum-subarray/
    时间：2020-7-11        
    BY Kromite

    解题技巧： 此题是贪心问题基础题。
    一般来说最大利润就是直接继续增加加数组的连续数字之间的差值，如果第二个数字大于第一个数字，我们获得的总和将是最大利润
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        int res = nums[0];
        for(int i=0;i!=n;i++){
            sum += nums[i];
            res = max(res, sum);
            // sum <0 clear sum
            if(sum<0)
                sum =0;
        }
        return res;
    }
};


int main(int argc, char **argv){
    vector<int> nums;
    for(int i=1;i<argc;i++)
        nums.push_back(stoi(argv[i]));
    Solution solution;
    cout << "The max subarray is " << solution.maxSubArray(nums) << endl;

    return 0;
}