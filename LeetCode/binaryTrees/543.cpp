// problem link
// https://leetcode.com/problems/diameter-of-binary-tree/description/

// Solution
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {

        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    int height(TreeNode *root, int &diameter)
    {
        if (root == NULL)
            return 0;
        int leftDiameter = height(root->left, diameter);
        int rightDiameter = height(root->right, diameter);
        diameter = max(diameter, leftDiameter + rightDiameter);
        return max(leftDiameter, rightDiameter) + 1;
    }
};