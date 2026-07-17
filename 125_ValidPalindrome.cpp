#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        // tc O(n), sc O(n)
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
            {
                str += tolower(s[i]);
            }
        }
        for (int i = 0; i < str.size() / 2; i++)
        {
            if (str[i] != str[str.size() - i - 1])
                return false;
        }
        return true;

        // tc O(n), sc O(1)
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            while (l < r && !isalnum(s[l]))
                l++;
            while (l < r && !isalnum(s[r]))
                r--;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};