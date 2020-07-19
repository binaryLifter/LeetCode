class Solution
{
public:
  bool canCross(const vector<int> &stones)
  {
    used.resize(int(stones.size()));
    for (int i = 0; i < int(stones.size()); i += 1)
    {
      this->convert[stones[i]] = i;
      this->recover[i] = stones[i];
    }
    return this->solve(0, 0);
  }

private:
  unordered_map<int, int> convert;
  unordered_map<int, int> recover;
  vector<unordered_set<int>> used;

  bool solve(const int &i, const int &k)
  {
    this->used[i].insert(k);
    if (i == int(this->convert.size()) - 1)
    {
      return true;
    }
    bool ans = false;
    for (int j = max(1, k - 1); j <= k + 1; j += 1)
    {
      int nxt = this->recover[i] + j;
      if (this->convert.count(nxt) == 0)
      {
        continue;
      }
      nxt = this->convert[nxt];
      if (this->used[nxt].count(j) == 0)
      {
        ans |= this->solve(nxt, j);
      }
    }
    return ans;
  }
};