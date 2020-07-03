/*
    题目：1. 两数之和
    链接：https://leetcode-cn.com/problems/two-sum/
    时间：2020-6-16        
    BY Kromite

    解题技巧： 暴力法尽量不要用，缩短时间复杂度一般要扩大空间复杂度
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
// 1. 暴力法：
        // vector<int> ans;
        // int i=0,j=1;
        // for(int i=0;i!=nums.size()-1;i++){
        //     for(int j=i+1;j!=nums.size();j++)
        //     {
        //         if(nums[i]+nums[j]==target)
        //         {
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             return ans;
        //         }
        //     }
        // }
        // return ans;
// 2. hashmap
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i!=nums.size();i++){
            int c= nums[i];
            if(m.count(target-c)){
                ans.push_back(m[target-c]);
                ans.push_back(i);
                break;
            }
            m[c] = i;
        }
        return ans;
    }
};