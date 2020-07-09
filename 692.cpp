/*
    题目：692. 前K个高频单词
    链接：https://leetcode-cn.com/problems/top-k-frequent-words/
    时间：2020-7-3        
    BY Kromite

    解题技巧： 应对TOP-K的问题，一般会采用priority_queue来构造堆，这里使用的是大根堆
    易错点： 1.牢记输出顺序，vector 是否要reverse
            2. 内容是pair<string,int>的堆，这里的堆存放顺序函数cmp的构造
*/
#include <queue>
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;


class Solution{
public:
    // cmp 
    struct cmp{
        bool operator() (const pair<string,int> &a, const pair<string, int> &b){
            if(a.second!=b.second)  return a.second>b.second;
            else return a.first < b.first;   
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> q;  // 这个是重点，priority_queue构造适应性堆
        vector<string> ans;
        unordered_map<string,int> m;
        for(auto c: words)
            m[c]++;

        for(auto c:m){
            q.push(c);
            if(q.size()>k)  q.pop();
        }
        while(!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(int argc, char **argv){
    Solution solution;
    vector<string> words;
    int k;
    for(int i=1;i<argc-1;i++){
        words.push_back(argv[i]);
    }
    k = atoi(argv[argc-1]);
    vector<string> ans = solution.topKFrequent(words, k);
    for(auto c: ans)
        cout << c << endl;
    system("pause");
    return 0;
}