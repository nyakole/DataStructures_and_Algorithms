// https://leetcode.com/problems/unique-morse-code-words/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int uniqueMorseRepresentations(vector<string> &words)
{
    vector<string> morseCodes = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    unordered_set<string> uniqueTransformations;

    for (const string &word : words)
    {
        string morseWord;
        for (char c : word)
        {
            morseWord += morseCodes[c - 'a'];
        }
        uniqueTransformations.insert(move(morseWord));
    }

    return uniqueTransformations.size();
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    int result = uniqueMorseRepresentations(words);
    cout << "Output: " << result << endl;
    return 0;
}