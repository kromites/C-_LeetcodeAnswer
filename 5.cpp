/*
    题目：5. 最长回文子串
    链接：https://leetcode-cn.com/problems/longest-palindromic-substring/
    时间：2020-6-17        
    BY Kromite

    解题技巧： 使用中心扩展法，分为2n-1个中心点，左边等于右边才是回文串。
*/

#include <string>
using namespace std;

class Solution {
public:
    // 中心扩展法 
    static int hs(string s, int left, int right){
        int l=left, r= right;
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int start=0, end = 0;
        int len=0;
        for(int i=0; i<s.size(); i++){
            int len1 = hs(s, i, i);     //总共有2i-1个点
            int len2 = hs(s, i, i+1);
            len = max(max(len1,len2),len);

            // 关键步骤： start 和 end 的取值
            if(len+start>end+1)
            {
                start = i - (len-1)/2;
                end = i+ len/2;
            }    
        }
        return s.substr(start, len);
    }
    
};