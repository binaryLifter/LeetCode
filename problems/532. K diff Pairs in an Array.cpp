class Solution
{
public:
  int findPairs(vector<int> &v, const int &k)
  {
    unordered_set<int> used;
    unordered_map<int, int> have;
    for (const int &i : v)
    {
      have[i] += 1;
    }
    int ans = 0;
    for (int i = 0; i < int(v.size()); i += 1)
    {
      if (used.count(v[i]))
      {
        continue;
      }
      used.insert(v[i]);
      have[v[i]] -= 1;
      if (v[i] + k >= v[i] and have[v[i] + k] > 0)
      {
        ans += 1;
      }
      have[v[i]] += 1;
    }
    return ans;
  }
};