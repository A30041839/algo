class Solution {
  unordered_map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
public:
  vector<string> findStrobogrammatic(int n) {
    if (n == 0) {
      return {};
    }
    string str(n, '0');
    vector<string> res;
    dfs(res, str, 0, n);
    return res;
  }

  void dfs(vector<string>& res, string cur, int i, int n) {
    int j = n - i - 1;
    if (i > j) {
      res.push_back(cur);
      return;
    }
    for (auto& p : mp) {
      if (i == j) {
        if (p.first == '6' or p.first == '9') {
          continue;
        }
      }else if (n > 1 and i == 0) {
        if (p.first == '0') {
          continue;
        }
      }
      cur[i] = p.first;
      cur[j] = p.second;
      dfs(res, cur, i + 1, n);
    }
  }
};
