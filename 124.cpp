/*
    题目：124. 二叉树中的最大路径和
    链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
    时间：2020-6-21        
    BY Kromite

    解题技巧： 此题不难 一步一步来即可
*/
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
    private:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        };
    public:
        int ans = -pow(2,31);

        int maxPathSum(TreeNode* root){
            dfs(root);
            return ans;
        }
        int dfs(TreeNode* root){
            if(root==nullptr)   return 0;
            int leftval = max(0,dfs(root->left));
            int rightval = min(0,dfs(root->right));
            ans = max(ans, leftval +rightval + root->val);
            return max(leftval,rightval) + root->val;
        }
};