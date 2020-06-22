/*
    题目：6. Z 字形变换
    链接：https://leetcode-cn.com/problems/zigzag-conversion/
    时间：2020-6-17        
    BY Kromite

    解题技巧： 此题不难 一步一步来即可
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty())   return "";
        if(numRows<2)   return s;
        int n = numRows-2+numRows;
        int m;
        string ans;
        vector<string> str(numRows,"");
        for(int i=0;i<s.size();i++){
            m = (i%n<numRows)? (i%n):(n-i%n);
            str[m] += s[i];
        }
        for(string c:str)
            ans += c;
        return ans;
    }
};