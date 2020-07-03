/*
    题目：145.二叉树的后序遍历
    链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
    时间：2020-6-23     
    BY Kromite

    解题技巧： 递归简单，迭代有点意思，两种都得掌握，树的四大遍历，除了层序遍历，其他三个迭代实现都是使用栈
    题目序号，前序，144， 中序 94， 后序 145, 层次 102
*/
#include <vector>
#include <stack>
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
// 1. 递归
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
    void postorder(TreeNode* root, vector<int> &ans){
        if(root==nullptr)   return ;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
// 2. 迭代, 与先序遍历相反,变形
    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* r = s.top();
            s.pop();
            if(!r) continue;
            ans.push_back(r->val);
            // 记住，这里先得push 左子树，再push 右子树，因为栈本来就是后进先出
            s.push(r->left);
            s.push(r->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};