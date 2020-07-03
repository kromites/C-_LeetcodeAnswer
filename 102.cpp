/*
    题目：102.二叉树的后序遍历
    链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
    时间：2020-6-24     
    BY Kromite

    解题技巧： 标准层次遍历BFS
    题目序号，前序，144， 中序 94， 后序 145, 层次 102
*/
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)   return ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
            int n = que.size();
            for(int i=0;i<n;i++){
                TreeNode *node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};