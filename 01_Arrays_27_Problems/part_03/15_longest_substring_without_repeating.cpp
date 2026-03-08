#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (lastIndex.count(c) && lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};