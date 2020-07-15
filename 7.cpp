/*
    题目：7. 整数反转
    链接：https://leetcode-cn.com/problems/reverse-integer/
    时间：2020-7-11        
    BY Kromite

    解题技巧： 这道题目算是入门基本题
*/

#include <algorithm>
#include <iostream>

using namespace std;
class Solution{
public:
    int reverse(int x){
        // long 来让其不溢出
        long sum = 0;
        int Max = pow(2,31)-1;
        int Min = -pow(2,31);
        // 标准int整数反转代码, 整数负数都能这样实现
        while(x){
            sum = sum*10 + x%10;
            x = x/10;
        }
        if(sum >Max || sum < Min) return 0;
        return sum;
    }
};

int main(){
    int x;
    Solution solution;
    while(cin>>x){
        cout << solution.reverse(x) << endl;
    }
    system("puase");
    return 0;
}