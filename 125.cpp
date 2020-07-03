/*
    题目：125. 验证回文串
    链接：https://leetcode-cn.com/problems/valid-palindrome/
    时间：2020-6-19     
    BY Kromite

    解题技巧： 此题两次遍历求解不难，要掌握进阶方法，一次遍历就要成功
*/
#include <string>
using namespace std;

class Solution {
public:
 // 1. 两次遍历, 将s处理成纯小写字母加数字的字符串，然后再用判断回文的方法判断。
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        string s1;
        for(char &c: s){
            if(isalnum(c)){
                s1 += tolower(c);
            }
        }
        int i=0, j=s1.size()-1;
        while(i<=j){
            if(s1[i++]!=s1[j--])
                return false;
        }
        return true;
    }

// 2. 一次遍历就求解，一步到位，要习惯这种思路，边遍历边筛选
    bool isPalindrome2(string s){
        if(s.size()==0) return true;
        int i=0, j= s.size()-1;
        while(i<=j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i++])!=tolower(s[j--]))
                return false;
        }
        return true;
    }
};