#include "leetcode.h"

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
      unordered_map<string, int> mp;
      int res = INT_MAX;
      for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word1 and mp.count(word2)) {
          res = min(res, i - mp[word2]);
        }else if (words[i] == word2 and mp.count(word1)) {
          res = min(res, i - mp[word1]);
        }
        mp[words[i]] = i;
      }
      return res;
    }
};
