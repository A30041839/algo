class Solution {
public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    unordered_map<string, int> mp;
    int n = words.size();
    int res = words.size();
    for (int i = 0; i < n; ++i) {
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
