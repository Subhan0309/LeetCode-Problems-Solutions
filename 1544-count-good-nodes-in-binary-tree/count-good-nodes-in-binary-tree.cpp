/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recGN(TreeNode * root,int & answer,int max)
    {   
        if(!root)
        {
            return;
        }
        if(root->val >= max)
        {
            answer++;
            max=root->val;
        }

        recGN(root->left,answer,max);
        recGN(root->right,answer,max);

    }

    int goodNodes(TreeNode* root) {
        int ans=0;
        recGN(root,ans,INT_MIN);
        return ans;
    }
};