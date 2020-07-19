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
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
  {
    if (t1 == NULL and t2 == NULL)
    {
      return NULL;
    }
    TreeNode *root = new TreeNode(0);
    TreeNode *t1Left = NULL;
    TreeNode *t1Right = NULL;
    if (t1 != NULL)
    {
      root->val += t1->val;
      t1Left = t1->left;
      t1Right = t1->right;
    }
    TreeNode *t2Left = NULL;
    TreeNode *t2Right = NULL;
    if (t2 != NULL)
    {
      root->val += t2->val;
      t2Left = t2->left;
      t2Right = t2->right;
    }
    if (t1Left != NULL or t2Left != NULL)
    {
      root->left = mergeTrees(t1Left, t2Left);
    }
    if (t1Right != NULL or t2Right != NULL)
    {
      root->right = mergeTrees(t1Right, t2Right);
    }
    return root;
  }
};