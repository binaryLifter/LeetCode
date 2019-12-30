class Solution
{

public:
	bool alpha[26], digit[10];
	std::vector<std::string> words;
	int len[11234], x[11234];

	bool DFS(int r, int c, int sum)
	{
		if (c == len[int(words.size()) - 1])
		{
			return true;
		}
		int index = words[r][c] - 'A';
		if (r == int(words.size()) - 1)
		{
			if (x[index] != -1)
			{
				if (sum % 10 != x[index])
				{
					return false;
				}
				return DFS(0, c + 1, sum / 10);
			}
			else
			{
				int t = sum % 10;
				if (digit[t])
				{
					return false;
				}
				x[index] = sum % 10;
				digit[t] = true;
				if (DFS(0, c + 1, sum / 10))
				{
					return true;
				}
				digit[t] = false;
				x[index] = -1;
				return false;
			}
		}
		if (c >= len[r])
		{
			return DFS(r + 1, c, sum);
		}
		if (x[index] != -1)
		{
			return DFS(r + 1, c, sum + x[index]);
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				if (len[r] > 1 && c == len[r] - 1 && i == 0)
				{
					continue;
				}
				if (!digit[i])
				{
					digit[i] = true;
					x[index] = i;
					if (DFS(r + 1, c, sum + i))
					{
						return true;
					}
					x[index] = -1;
					digit[i] = false;
				}
			}
			return false;
		}
	}

	bool isSolvable(vector<string> &words, string result)
	{
		this->words = words;
		this->words.push_back(result);
		memset(alpha, false, sizeof(alpha));
		memset(digit, false, sizeof(digit));
		memset(len, 0, sizeof(len));
		memset(x, -1, sizeof(x));

		int idx = 0;
		for (auto &word : this->words) {
			len[idx] = int(word.size());
			idx += 1;
			for (const auto &c : word) {
				alpha[c - 'A'] = true;
			}
			for (int j = 0, k = int(word.size()) - 1; j < k; j++, k--)
			{
				swap(word[j], word[k]);
			}
		}
		return DFS(0, 0, 0);
	}
};