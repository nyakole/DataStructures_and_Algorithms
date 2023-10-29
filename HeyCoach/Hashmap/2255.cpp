// https://leetcode.com/problems/count-prefixes-of-a-given-string/
int countPrefixes(vector<string> &words, string s)
{
    int count = 0;
    for (auto word : words)
    {
        bool isPrefix = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] != s[i])
            {
                isPrefix = false;
                break;
            }
        }
        if (isPrefix)
            count++;
    }
    return count;
}