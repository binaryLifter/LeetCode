class Solution
{

public:
  string removeKdigits(string num, int k)
  {
    num = "0" + num;
    int removed = 0;
    stack<int> before;
    for (int i = 0; i < int(num.size()); i += 1)
    {
      if (removed < k and before.empty() == false and before.top() > num[i])
      {
        before.pop();
        i -= 1;
        removed += 1;
      }
      else
      {
        before.push(num[i]);
      }
    }
    string ans = "";
    while (before.empty() == false)
    {
      ans.push_back(before.top());
      before.pop();
    }
    reverse(ans.begin(), ans.end());
    int remaining = k - removed;
    ans = ans.substr(0, int(ans.size()) - remaining);
    for (int i = 0; i < int(ans.size()); i += 1)
    {
      if (ans[i] != '0')
      {
        ans = ans.substr(i, int(ans.size()) - i);
        break;
      }
    }
    if (ans[0] == '0')
    {
      ans = "0";
    }
    return ans;
  }
};