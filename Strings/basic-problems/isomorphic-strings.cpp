
#include <bits/stdc++.h>
using namespace std;

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "foo", t = "bar"

// Output: false

// Explanation:

// The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

// Example 3:

// Input: s = "paper", t = "title"

// Output: true

// my thought proces
// we take a map which has key vale of both char type

// from second insertion onwards we need to check , whether the key which is coming to insert is
// already there or not, if it not there insert the key valeu pair
// but if the key already appeard in the map, then we check value of the key , if value doesn't matches
// we return false , and if it matches , we do nothing, map will already handel it , it will not take duplicate key entries.

// we need to reverse checking also , like what if t was main string , which has keys and s has value
// basiclaly we need to chekc one to one and onto both

bool isIsomorphic(string s, string t)
{
    // we need to check if one to one mapping is possible or not

    if (s.empty())
        return true;

    unordered_map<char, char> mpp;
    unordered_map<char, char> reverse_mpp;

    for (size_t i = 0; i < s.size(); i++)
    {

        auto it = mpp.find(s[i]); // find wheter the key is there or not

        // if it is there
        if (it != mpp.end())
        {
            if (t[i] != it->second)
                return false;
        }

        else
        {
            // we did forward checking, but what if t was the main string,
            //  and we need to check for values in s;

            auto reverse_it = reverse_mpp.find(t[i]);

            if (reverse_it != reverse_mpp.end())
            {
                if (s[i] != reverse_it->second)
                    return false;
            }
        }
        // If both checks pass (s[i] is new AND t[i] is new),
        mpp[s[i]] = t[i];
        reverse_mpp[t[i]] = s[i];
    }
    return true;
}

int main()
{
    string s = "egg";
    string t = "ard";

    if (isIsomorphic(s, t))
    {
        cout << "it is isomorphic";
    }
    else
    {
        cout << "not isomorphic";
    }
    return 0;
}