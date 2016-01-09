class Solution {
public:
  vector<string> generateAbbreviations(string word) {
    vector<string> res;
    dfs(res, word, "", 0);
    return res;
  }

  void dfs(vector<string>& res, string word, string sub, int count) {
    if (word.empty()) {
      if (count > 0) {
        sub.append(to_string(count));
      }
      res.push_back(sub);
      return;
    }
    string str = count > 0 ? to_string(count) : "";
    str.push_back(word[0]);
    dfs(res, word.substr(1), sub + str, 0);
    dfs(res, word.substr(1), sub, count + 1);
  }
};
