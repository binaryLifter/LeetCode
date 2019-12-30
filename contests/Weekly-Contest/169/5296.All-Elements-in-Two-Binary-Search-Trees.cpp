/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  vector<int> ans;
  void dfs(const TreeNode *i)
  {
    ans.push_back(i->val);
    if (i->left != NULL)
    {
      dfs(i->left);
    }
    if (i->right != NULL)
    {
      dfs(i->right);
    }
  }

  vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
  {
    if (root1 != NULL)
    {
      dfs(root1);
    }
    if (root2 != NULL)
    {
      dfs(root2);
    }
    std::sort(ans.begin(), ans.end());
    return ans;
  }
};