class Solution
{
public:
  bool canReach(vector<int> &arr, int start)
  {
    std::vector<bool> used(int(arr.size()), false);
    std::queue<int> q;
    used[start] = true;
    q.push(start);
    while (!q.empty())
    {
      const int i = q.front();
      q.pop();
      if (arr[i] == 0)
      {
        return true;
      }
      if (i - arr[i] >= 0 and !used[i - arr[i]])
      {
        used[i - arr[i]] = true;
        q.push(i - arr[i]);
      }
      if (i + arr[i] < int(arr.size()) and !used[i + arr[i]])
      {
        used[i + arr[i]] = true;
        q.push(i + arr[i]);
      }
    }
    return false;
  }
};