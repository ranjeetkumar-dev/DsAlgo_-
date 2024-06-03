#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0, j = 0;

        // Traverse both strings
        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j])
            {
                j++; // Move `j` if characters match
            }
            i++; // Always move `i`
        }

        // The number of characters in `t` that have not been matched
        return t.length() - j;
    }
};
int main()
{
    Solution r;
    cout << r.appendCharacters("coaching", "coding");

    return 0;
}