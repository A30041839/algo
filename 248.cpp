class Solution {
  unordered_map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

  bool cmp(string lhs, string rhs) {
    int n1 = lhs.size(), n2 = rhs.size();
    if (n1 == n2) {
      return lhs <= rhs;
    }else {
      return n1 < n2 ? true : false;
    }
  }

public:
  int strobogrammaticInRange(string low, string high) {
    int n1 = low.size(), n2 = high.size();
    if (n1 > n2) {
      return 0;
    }else if (n1 == n2 and low > high) {
      return 0;
    }
    int cnt = 0;
    for (int l = n1; l <= n2; ++l) {
      string str(l, '0');
      dfs(str, low, high, l, 0, cnt);
    }
    return cnt;
  }

  void dfs(string str, string low, string high, int n, int i, int& cnt) {
    int j = n - i - 1;
    if (i > j) {
      if (n == low.size() or n == high.size()) {
        if (cmp(low, str) and cmp(str, high)) {
          cnt++;
        }
      }else {
        cnt++;
      }
      return;
    }
    for (auto& p : mp) {
      if (i == j) {
        if (p.first == '6' or p.first == '9') {
          continue;
        }
      }else if (i == 0) {
        if (p.first == '0') {
          continue;
        }
      }
      str[i] = p.first;
      str[j] = p.second;
      dfs(str, low, high, n, i + 1, cnt);
    }
  }
};
