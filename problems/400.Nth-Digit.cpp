class Solution
{
public:
  int findNthDigit(int n)
  {
    long long int qtd = 9;
    long long int total = 0;
    long long int pot = 1;
    for (int digits = 1; true; digits += 1)
    {
      if (total + (1LL * digits * qtd) < n)
      {
        total += (1LL * digits * qtd);
        qtd *= 10;
        pot *= 10;
        continue;
      }
      n -= total;
      pot += (n / digits);
      n %= digits;
      if (n == 0)
      {
        pot -= 1;
        n = digits;
      }
      return to_string(pot)[n - 1] - '0';
    }
  }
};