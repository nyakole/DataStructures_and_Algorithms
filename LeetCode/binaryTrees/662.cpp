// problem link
// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

// Solution
class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    if (!root)
      return 0;
    int ans = 0;
    queue<pair<TreeNode *, long>> q;
    q.push({root,
            0});
    while (!q.empty())
    {
      int size = q.size();
      long curMin = q.front().second;
      int leftMost, rightMost;
      for (int i = 0; i < size; i++)
      {
        long cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
        TreeNode *temp = q.front().first;
        q.pop();
        if (i == 0)
          leftMost = cur_id;
        if (i == size - 1)
          rightMost = cur_id;
        if (temp->left)
          q.push({temp->left,
                  cur_id * 2 + 1});
        if (temp->right)
          q.push({temp->right,
                  cur_id * 2 + 2});
      }
      ans = max(ans, rightMost - leftMost + 1);
    }
    return ans;
  }
};