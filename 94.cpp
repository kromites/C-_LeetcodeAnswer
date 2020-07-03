/*
    题目：94.二叉树的中序遍历
    链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
//1. 递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    void inorder(TreeNode* root, vector<int> &ans){
        if(root==nullptr)   return ;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
// 2. 迭代，利用栈
    vector<int> inorderTraversal2(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* r= root;
        while(!s.empty()||r){
            // 结点不为空时，不断将左子树压栈
            while(r){
                s.push(r);
                r=r->left;
            }
            // 左子树为空后，一步一步退栈，再将右子树压栈
            r=s.top();
            s.pop();
            ans.push_back(r->val);
            r=r->right;
        }
        return ans;
    }
};