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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *curr=root;
        stack<TreeNode*> st;

        while(curr || !st.empty())
        {
            while(curr)
            {
                st.push(curr);
                curr=curr->left;
            }

            TreeNode * x=st.top();
            st.pop();
            TreeNode * left=x->left;
            x->left=x->right;
            x->right=left;

            curr=x->left;
        }

        return root;
    }
};