/*
    题目：42. 接雨水
    链接：https://leetcode-cn.com/problems/trapping-rain-water/
    时间：2020-7-8        
    BY Kromite

    解题技巧： 此题是双指针数组的hard题，还是用双指针来实现,两个数组相减
*/
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Solution{
public:
    int trap(vector<int>& height){
        if(height.size()<2) return 0;
        int max = 0;            // 首先找到峰值
        int max_sub = 0;        // 峰值下标
        int sum_init = 0;            // sum 为初始总数值值
        int sum_rain= height[0];    // ans 为雨水覆盖的总数组值
        int ans=0;
        // 第一遍循环得到sum和max,max_sub
        for(int i=0; i<height.size(); i++){
            if(height[i]>max){
                max = height[i];
                max_sub = i;
            }
            sum_init += height[i];
        }
        //  第二遍循环得到sum_rain
        for(int i=1;i<=max_sub;i++){
            if(height[i]<height[i-1])
                height[i] = height[i-1];
            sum_rain += height[i];
        }
        for(int i=height.size()-1;i>max_sub;i--){
            if(height[i-1]<height[i])
                height[i-1] = height[i];
            sum_rain += height[i];
        }

        ans = sum_rain - sum_init;
        return ans;
    }
};

int main(int argc, char **argv){
    vector<int> height;
    Solution solution;
    stringstream ss;
    int num;
    for(int i=1;i!=argc;i++){
        ss << argv[i];
        ss >> num;
        height.push_back(num);
        ss.clear();
    }
    int ans = solution.trap(height);
    cout << "ans :" << ans << endl;
    system("pause");
    return 0;
}