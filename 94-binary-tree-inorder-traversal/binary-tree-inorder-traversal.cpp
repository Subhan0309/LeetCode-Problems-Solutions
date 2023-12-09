class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) {
            return {};
        }

        TreeNode* current = root;
        stack<TreeNode*> st;
        vector<int> res;

        while (current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            res.push_back(current->val);
            current = current->right;
        }

        return res;
    }
};
