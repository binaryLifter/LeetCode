class Solution
{
public:
  vector<int> sumZero(int n)
  {
    std::vector<int> ans;
    if (n & 1)
    {
      ans.push_back(0);
    }
    for (int i = 0; i < (n >> 1); i += 1)
    {
      ans.push_back(i + 1);
      ans.push_back(-i - 1);
    }
    return ans;
  }
};