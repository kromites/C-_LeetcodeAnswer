/*
    题目：3. 无重复字符的最长子串
    链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
    时间：2020-6-17        
    BY Kromite

    解题技巧： 采用双指针遍历string，通过指针移位获得最长子串
*/

#include <string>
using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.size()<2)  return s.size();
            int i=0,j=1;
            int ans = 0;
            while(j<s.size()){
                for(int k=i;k<j;k++){
                    if(s[k]==s[j])
                    {
                        i = k+1;
                        break;
                    } 
                }
                j++;
                ans = max(ans, j-i);
            }
            return ans;
        }
};