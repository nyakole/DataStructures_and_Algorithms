// problem link
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

// Solution
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lf = maxDepth(root->left);
        int ri = maxDepth(root->right);

        return 1 + max(lf, ri);
    }
};