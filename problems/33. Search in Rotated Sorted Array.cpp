class Solution
{
public:
  int search(const vector<int> &v, const int &target)
  {
    int lo;
    int hi;
    const int n = int(v.size());
    if (n > 1 and v[0] > v[n - 1])
    {
      lo = 0;
      hi = n - 2;
      while (lo <= hi)
      {
        const int mid = (lo + hi) >> 1;
        if (v[mid] == target)
        {
          return mid;
        }
        else if (v[mid] < v[n - 1])
        {
          hi = mid - 1;
        }
        else
        {
          lo = mid + 1;
        }
      }
      if (target >= v[0])
      {
        lo = 0;
      }
      else
      {
        lo = hi + 1;
        hi = n - 1;
      }
    }
    else
    {
      lo = 0;
      hi = n - 1;
    }
    while (lo <= hi)
    {
      const int mid = (lo + hi) >> 1;
      if (v[mid] > target)
      {
        hi = mid - 1;
      }
      else if (v[mid] < target)
      {
        lo = mid + 1;
      }
      else
      {
        return mid;
      }
    }
    return -1;
  }
};