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
    int solid(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root)   return 0;
        if(dp.find(root) != dp.end())   return dp[root];

        int robThis = 0, drob = 0;

        //rob current house
        robThis += root->val;
        if(root->left){
            robThis += solid(root->left->left, dp) + solid(root->left->right, dp);
        }
        if(root->right){
            robThis += solid(root->right->left, dp) + solid(root->right->right, dp);
        }

        //dont rob current house
        drob = solid(root->right, dp) + solid(root->left, dp);

        dp[root] = max(drob, robThis);
        return dp[root];
        
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solid(root, dp);
    }
};
