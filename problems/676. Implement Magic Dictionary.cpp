class Trie
{
public:
  Trie()
  {
    this->end = false;
  }

  void insert(const int &i, const string &s)
  {
    if (i == int(s.size()))
    {
      this->end = true;
      return;
    }
    const char &c = s[i];
    if (this->nxt.count(c) == 0)
    {
      this->nxt[c] = new Trie();
    }
    this->nxt[c]->insert(i + 1, s);
  }

  bool query(const int &i, const string &s, const bool &mismatch)
  {
    if (i == int(s.size()))
    {
      return mismatch && this->end;
    }
    const char &c = s[i];
    bool ans = false;
    if (!mismatch)
    {
      for (const auto &j : this->nxt)
      {
        if (j.first != c)
        {
          ans |= j.second->query(i + 1, s, true);
        }
      }
    }
    if (this->nxt.count(c))
    {
      ans |= this->nxt[c]->query(i + 1, s, mismatch);
    }
    return ans;
  }

private:
  unordered_map<char, Trie *> nxt;
  bool end;
};

class MagicDictionary
{
public:
  /** Initialize your data structure here. */
  MagicDictionary()
  {
    this->root = new Trie();
  }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict)
  {
    for (string i : dict)
    {
      this->root->insert(0, i);
    }
  }

  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word)
  {
    return this->root->query(0, word, false);
  }

private:
  Trie *root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */