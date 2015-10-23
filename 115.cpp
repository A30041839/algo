#include "leetcode.h"

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    return numDistinct1(s, t);
  }

  int numDistinct1(string s, string t) {
    if (s.empty() or t.empty()) {
      return 0;
    }
    int n = s.size(), m = t.size();
    long long res = 0;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
      res = 0;
      for (int j = n; j >= 0; --j) {
        if (dp[j] > 0) {
          long long k = dp[j];
          for (int p = j; p < n; ++p) {
            if (s[p] == t[i]) {
              dp[p + 1] += k;
              res += k;
            }
          }
          dp[j] = 0;
        }
      }
    }
    return (int)res;
  }

  int numDistinct2(string s, string t) {
    if (s.empty() or t.empty()) {
      return 0;
    }
    int n = s.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[0]) {
        mp[i] = 1;
      }
    }
    for (int i = 1; i < t.size(); ++i) {
      unordered_map<int, int> tmp;
      for (auto& p : mp) {
        int cur = p.first + 1;
        int cnt = p.second;
        while (cur < n) {
          if (s[cur] == t[i]) {
            tmp[cur] += cnt;
          }
          cur++;
        }
      }
      mp = tmp;
    }
    int res = 0;
    for (auto& p : mp) {
      res += p.second;
    }
    return res;
  }
};

int main() {
  Solution s;
  string a = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
  string b = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
  cout << s.numDistinct(a, b) << endl;
}
