/*
 * 3_LongestSubstringWithoutRepeatingCharacters.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: randy
 */



/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLength = 0;

        std::unordered_set<int> lettersSeen;
        string::iterator it = s.begin();
        string::iterator it2 = s.begin();
        int len = 0;

        for(; it != s.end(); ++it)
        {
        	if(lettersSeen.find(*it2) == lettersSeen.end())
        	{
        		// continue searching
        		while(it2 != s.end() && lettersSeen.find(*it2) == lettersSeen.end())
				{
					lettersSeen.insert(*it2);
					++len;
					++it2;
				}

        		// exited due to duplicate or end of string. check if longer than current longest
        		if(len > longestLength)
        		{
        			longestLength = len;
        		}


        	}

			// remove letter at first pointer from set, decrement length.
			--len;
			lettersSeen.erase(*it);
			continue;
        }
        return longestLength;
    }
};



int main()
{
	std::string str("abcabcbbnauewb");
	Solution s;
	cout << "Longest substring for " << str << " is " << s.lengthOfLongestSubstring(str) << std::endl;
	return 0;
}
