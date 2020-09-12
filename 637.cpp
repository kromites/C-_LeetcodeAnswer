/*
    题目：637. 二叉树的层平均值
    链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
    时间：2020-9-12        
    BY Kromite

    解题技巧： 本题为easy题，直接可以通过BFS解答。
*/

#include <vector>
#include <queue>

class Solution{
    private:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        };
    public:
        void bfs(TreeNode *root, std::vector<double> &ans)
        {
            std::queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int n = q.size();
                double sum = 0;
                double num = 0;
                for(int i=0; i!=n; i++)
                {
                    TreeNode* t1 = q.front();
                    sum += t1->val;
                    num++;
                    q.pop();
                    if(t1->left)
                    {
                        q.push(t1->left);
                    }
                    if(t1->right)
                    {
                        q.push(t1->right);
                    }
                }
                double res = sum/num;
                ans.push_back(res);
            }
        }
        std::vector<double> averageOfLevels(TreeNode* root) {
            std::vector<double> ans;
            bfs(root, ans);
            return ans;
        } 
};

