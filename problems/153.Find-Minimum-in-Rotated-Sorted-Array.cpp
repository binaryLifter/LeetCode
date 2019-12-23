class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int n = int(nums.size());
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi)
    {
      const int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] > nums[n - 1])
      {
        lo = mid + 1;
      }
      else
      {
        hi = mid - 1;
      }
    }
    return nums[hi + 1];
  }
};