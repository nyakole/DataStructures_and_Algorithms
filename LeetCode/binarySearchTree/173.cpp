// problem link
// https://leetcode.com/problems/binary-search-tree-iterator/

// Solution
class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        for (; node != NULL; myStack.push(node), node = node->left)
            ;
    }
};