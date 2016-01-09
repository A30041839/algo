class Solution {
  string sum(string a, string b) {
    string res;
    int m = a.size(), n = b.size();
    int i = m - 1, j = n - 1, carry = 0;
    while (i >= 0 or j >= 0 or carry) {
      int x = i >= 0 ? a[i] - '0' : 0;
      int y = j >= 0 ? b[j] - '0' : 0;
      int tmp = x + y + carry;
      carry = tmp / 10;
      tmp %= 10;
      res.push_back(tmp + '0');
      i--;
      j--;
    }
    reverse(res.begin(), res.end());
    return res;
  }

public:
  bool isAdditiveNumber(string num) {
    if (num.empty()) {
      return false;
    }
    int n = num.size();
    for (int i = 0; i <= n / 2; ++i) {
      for (int j = i + 1; j < n; ++j) {
        string a = num.substr(0, i + 1);
        string b = num.substr(i + 1, j - i);
        if (check(a, b, num, j + 1)) {
          return true;
        }
      }
    }
    return false;
  }

  bool check(string a, string b, string num, int pos) {
    if (pos == num.size()) {
      return false;
    }
    while (pos < num.size() and num.find(sum(a, b), pos) != string::npos) {
      string tmp = sum(a, b);
      a = b;
      b = tmp;
      pos += b.size();
    }
    return pos == num.size() ? true : false;
  }
};
