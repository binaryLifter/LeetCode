class Solution
{

private:
  vector<int> v;

  void dfs(const TreeNode *node)
  {
    if (node->left != NULL)
    {
      dfs(node->left);
    }
    v.push_back(node->val);
    if (node->right != NULL)
    {
      dfs(node->right);
    }
  }

public:
  int getMinimumDifference(TreeNode *root)
  {
    this->dfs(root);
    int ans = INT_MAX;
    for (int i = 1; i < int(this->v.size()); i += 1)
    {
      ans = min(ans, this->v[i] - this->v[i - 1]);
    }
    return ans;
  }
};