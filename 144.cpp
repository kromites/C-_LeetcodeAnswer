/*
    题目：144.二叉树的前序遍历
    链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
    时间：2020-6-23     
    BY Kromite

    解题技巧： 递归简单，迭代有点意思，两种都得掌握，树的四大遍历，除了层序遍历，其他三个迭代实现都是使用栈
    题目序号，前序，144， 中序 94， 后序 145, 层次 102
*/

#include <vector>
#include <stack>

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
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void preorder(TreeNode* root, vector<int> &ans){
        if(root==nullptr)   return ;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

// 2. 迭代, 借助栈
    vector<int> preorderTraversal2(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* r = s.top();
            s.pop();
            if(!r) continue;
            ans.push_back(r->val);
            // 记住，这里先得push 右子树，再push 左子树，因为栈本来就是后进先出
            s.push(r->right);
            s.push(r->left);
        }
        return ans;
    }

};