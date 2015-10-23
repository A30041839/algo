class Solution {
public:
  vector<string> generatePossibleNextMoves(string s) {
    if (s.size() < 2) {
      return {};
    }
    vector<string> res;
    int n = s.size();
    for (int i =1; i < n; ++i) {
      if (s[i] == s[i - 1] and s[i] == '+') {
        s[i - 1] = s[i] = '-';
        res.push_back(s);
        s[i - 1] = s[i] = '+';
      }
    }
    return res;
  }
};
