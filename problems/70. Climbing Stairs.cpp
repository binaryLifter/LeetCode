class Solution
{
public:
  int climbStairs(int n)
  {
    this->dp = vector<int>(n + 1, -1);
    return this->solve(0);
  }

private:
  vector<int> dp;

  int solve(const int &i)
  {
    if (this->dp[i] != -1)
    {
      return this->dp[i];
    }
    if (i == int(this->dp.size()) - 1)
    {
      return this->dp[i] = 1;
    }
    int ans = 0;
    for (int j = i + 1; j <= i + 2; j += 1)
    {
      if (j < int(this->dp.size()))
      {
        ans += solve(j);
      }
    }
    return this->dp[i] = ans;
  }
};