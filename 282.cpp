#include "leetcode.h"
using namespace std;

class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(res, "", num, 0, target, 0, true);
    return res;
  }

  void dfs(vector<string>& res, string sub, string num, long long curval, int target, long long prev, bool sgn) {
    if (num.empty()) {
      if (curval == target) {
        res.push_back(sub);
      }
      return;
    }
    long long tmp = 0;
    for (int i = 1; i <= num.size(); ++i) {
      tmp = tmp * 10 + num[i - 1] - '0';
      if (sub.empty()) {
        dfs(res, to_string(tmp), num.substr(i), tmp, target, tmp, true);
      }else {
        dfs(res, sub + "+" + to_string(tmp), num.substr(i), curval + tmp, target, tmp, true);
        dfs(res, sub + "-" + to_string(tmp), num.substr(i), curval - tmp, target, tmp, false);
        if (sgn) {
          dfs(res, sub + "*" + to_string(tmp), num.substr(i), curval - prev + prev * tmp, target, prev * tmp, sgn);
        }else {
          dfs(res, sub + "*" + to_string(tmp), num.substr(i), curval + prev - prev * tmp, target, prev * tmp, sgn);
        }
      }
      if (tmp == 0) break;
    }
  }
};

int main() {
  Solution s;
  vector<string> strs = {"123","232","105","00","3456237490", "2147483648"};
  vector<int> vals = {6,8,5,0,9191, -2147483648};
  for (int i = 0; i < strs.size(); ++i) {
    vector<string> res = s.addOperators(strs[i], vals[i]);
    print_vec(res);
  }
  return 0;
}
