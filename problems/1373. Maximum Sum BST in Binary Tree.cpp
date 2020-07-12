class TreeInfo
{
public:
    TreeInfo(const int value)
    {
        this->sum = value;
        this->best = 0;
        this->value = value;
        this->max_value = value;
        this->min_value = value;
        this->valid_bst = true;
    }

    int sum;
    int best;
    int value;
    int max_value;
    int min_value;
    bool valid_bst;
};

class Solution
{
public:
    int maxSumBST(const TreeNode* const root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return std::max(0, solve(root)->best);
    }

private:
    TreeInfo* solve(const TreeNode* const root)
    {
        TreeInfo* const current = new TreeInfo(root->val);
        if (root->left != NULL)
        {
            merge_left(current, solve(root->left));
        }
        if (root->right != NULL)
        {
            merge_right(current, solve(root->right));
        }
        if (current->valid_bst)
        {
            current->best = std::max(current->best, current->sum);
        }
        return current;
    }

    void merge_left(TreeInfo* const parent, const TreeInfo* const child)
    {
        if (parent->value <= child->max_value or !child->valid_bst)
        {
            parent->valid_bst = false;
        }
        merge(parent, child);
    }

    void merge_right(TreeInfo* const parent, const TreeInfo* const child)
    {
        if (parent->value >= child->min_value or !child->valid_bst)
        {
            parent->valid_bst = false;
        }
        merge(parent, child);
    }

    void merge(TreeInfo* const parent, const TreeInfo* const child)
    {
        parent->sum += child->sum;
        parent->max_value = std::max(parent->max_value, child->max_value);
        parent->min_value = std::min(parent->min_value, child->min_value);
        parent->best = std::max(parent->best, child->best);
    }
};