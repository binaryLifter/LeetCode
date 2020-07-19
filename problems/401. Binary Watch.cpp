class Solution
{
public:
  vector<string> readBinaryWatch(int num)
  {
    vector<string> ans;
    for (int hours = 0; hours <= num; hours += 1)
    {
      int minutes = num - hours;
      if (hours < 0 or hours > 4 or minutes < 0 or minutes > 6)
      {
        continue;
      }
      for (int i = 0; i < (1 << 4); i += 1)
      {
        if (__builtin_popcount(i) != hours)
        {
          continue;
        }
        int hour = 0;
        for (int j = 0; j < 4; j += 1)
        {
          if (i & (1 << j))
          {
            hour += (1 << j);
          }
        }
        if (hour < 0 or hour > 11)
        {
          continue;
        }
        for (int k = 0; k < (1 << 6); k += 1)
        {
          if (__builtin_popcount(k) != minutes)
          {
            continue;
          }
          int minute = 0;
          for (int j = 0; j < 6; j += 1)
          {
            if (k & (1 << j))
            {
              minute += (1 << j);
            }
          }
          if (minute < 0 or minute > 59)
          {
            continue;
          }
          string aux = to_string(minute);
          if (int(aux.size()) == 1)
          {
            aux = "0" + aux;
          }
          ans.push_back(to_string(hour) + ":" + aux);
        }
      }
    }
    return ans;
  }
};