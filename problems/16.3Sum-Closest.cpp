class Solution
{

private:
  int ans = INT_MAX;
  int diff = INT_MAX;

  void check(const int &sum, const int &target)
  {
    int currentDiff = abs(sum - target);
    if (currentDiff < this->diff)
    {
      this->diff = currentDiff;
      this->ans = sum;
    }
  }

public:
  int threeSumClosest(vector<int> &v, const int &target)
  {
    int n = int(v.size()) - 2;
    int m = int(v.size()) - 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i += 1)
    {
      int l = i + 1;
      int r = m;
      while (l < r)
      {
        const int currentSum = v[i] + v[l] + v[r];
        this->check(currentSum, target);
        if (currentSum < target)
        {
          l += 1;
        }
        else
        {
          r -= 1;
        }
      }
    }
    return this->ans;
  }
};