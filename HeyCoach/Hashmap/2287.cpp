// https://leetcode.com/problems/rearrange-characters-to-make-target-string/

int rearrangeCharacters(string s, string target)
{
    unordered_map<char, int> targetFreq;
    for (auto a : target)
    {
        targetFreq[a]++;
    }
    unordered_map<char, int> sentFreq;
    for (auto a : s)
    {
        sentFreq[a]++;
    }
    int mn = INT_MAX;
    for (auto a : targetFreq)
    {
        mn = min(mn, sentFreq[a.first] / a.second);
    }
    return mn;
}