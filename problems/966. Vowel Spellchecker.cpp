#include <bits/stdc++.h>

class IChecker
{
public:
    virtual void add(const std::string &original_string) = 0;
    virtual std::string query(const std::string &original_string) const = 0;

protected:
    virtual std::string get_converted(const std::string &s) const = 0;
};

template <typename T>
class Checker : public IChecker
{
public:
    void add(const std::string &original_string)
    {
        const std::string converted = get_converted(original_string);
        if (this->strings.count(converted))
        {
            return;
        }
        this->strings[converted] = original_string;
    }

    std::string query(const std::string &original_string) const
    {
        const auto it = this->strings.find(get_converted(original_string));
        if (it == this->strings.end())
        {
            return "";
        }
        return it->second;
    }

private:
    std::string get_converted(const std::string &s) const
    {
        std::string converted = "";
        for (const char c : s)
        {
            converted.push_back(T::convert(c));
        }
        return converted;
    }

    std::map<std::string, std::string> strings;
};

class ConverterExactly
{
public:
    static inline char convert(const char c)
    {
        return c;
    }
};

class ConverterLowercase
{
public:
    static inline char convert(const char c)
    {
        return tolower(c);
    }
};

class ConverterConsonant : private ConverterLowercase
{
public:
    static inline char convert(const char c)
    {
        const char lowercase = ConverterLowercase::convert(c);
        if (vowels.count(lowercase))
        {
            return '?';
        }
        return lowercase;
    }

private:
    static std::set<char> vowels;
};

std::set<char> ConverterConsonant::vowels = {'a', 'e', 'i', 'o', 'u'};

class Solution
{
public:
    std::vector<std::string> spellchecker(const std::vector<std::string> &wordlist, const std::vector<std::string> &queries)
    {
        build(wordlist);
        return answer_queries(queries);
    };

private:
    void build(const std::vector<std::string> &wordlist)
    {
        checkers = {
            new Checker<ConverterExactly>(),
            new Checker<ConverterLowercase>(),
            new Checker<ConverterConsonant>()};

        for (const std::string &word : wordlist)
        {
            for (const auto &i : checkers)
            {
                i->add(word);
            }
        }
    }

    std::vector<std::string> answer_queries(const std::vector<std::string> &queries) const
    {
        std::vector<std::string> ans;
        for (const std::string &query : queries)
        {
            ans.push_back(answer_query(query));
        }
        return ans;
    }

    std::string answer_query(const std::string &query) const
    {
        for (const auto &checker : this->checkers)
        {
            const std::string &current = checker->query(query);
            if (current != "")
            {
                return current;
            }
        }
        return "";
    }

    std::vector<IChecker *> checkers;
};

int main()
{
    return 0;
}