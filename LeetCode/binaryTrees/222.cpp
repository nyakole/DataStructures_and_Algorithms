// problem link
// https://leetcode.com/problems/count-complete-tree-nodes/

// Solution
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        int count = 0;
        inOrderTrav(root, count);
        return count;
    }
    void inOrderTrav(TreeNode *curr, int &count)
    {
        if (curr == NULL)
            return;

        count++;
        inOrderTrav(curr->left, count);
        inOrderTrav(curr->right, count);
    }
};