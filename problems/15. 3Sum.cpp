class Solution
{

public:
  vector<vector<int>> threeSum(vector<int> &v)
  {
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    for (int i = 0; i < int(v.size()); i += 1)
    {
      if (i > 0 and v[i] == v[i - 1])
      {
        continue;
      }
      int k = int(v.size()) - 1;
      for (int j = i + 1; j < int(v.size()); j += 1)
      {
        if (j > i + 1 and v[j] == v[j - 1])
        {
          continue;
        }
        while (k > j and v[i] + v[j] + v[k] > 0)
        {
          k -= 1;
        }
        if (k > j and v[i] + v[j] + v[k] == 0)
        {
          ans.push_back({v[i], v[j], v[k]});
        }
      }
    }
    return ans;
  }
};