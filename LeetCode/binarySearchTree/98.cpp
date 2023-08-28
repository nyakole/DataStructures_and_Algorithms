// problem link
// https://leetcode.com/problems/validate-binary-search-tree/

// Solution
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST2(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST2(TreeNode *root, long minVal, long maxVal)
    {
        if (root == NULL)
            return true;
        if (root->val >= maxVal || root->val <= minVal)
            return false;
        return isValidBST2(root->left, minVal, root->val) && isValidBST2(root->right, root->val, maxVal);
    }
};