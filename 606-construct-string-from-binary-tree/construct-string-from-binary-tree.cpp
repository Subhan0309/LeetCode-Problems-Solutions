/**
 * Definition for a binary tree node.
 /* struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 */

 //preorder traversal works for me here
class Solution {
public:

        string helper(TreeNode* current, string &result) {
        if (current == nullptr) {
            return result;
        }

        result += to_string(current->val);

        if (current->left || current->right) {
            result += "(";
            helper(current->left, result);
            result += ")";
        }

        if (current->right) {
            result += "(";
            helper(current->right, result);
            result += ")";
        }

        return result;
    }

    string tree2str(TreeNode* root) {
     if (root == nullptr) {
        return "";  // Return an empty string for an empty tree
    }
    string aka="";
    return helper(root,aka);
      
    }
};