#include "leetcode.h"

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    int cnt = calc_factorial(n);
    vector<char> v;
    for (int i = 1; i <= n; ++i){
      v.push_back(i + '0');
    }
    return getPermutation1(n, k, cnt, v);
  }

  string getPermutation1(int n, int k, int cnt, vector<char>& v) {
    if (n == 0){
      return "";
    }
    string res;
    cnt /= n;
    int num = (k - 1) / cnt;
    res.push_back(v[num]);
    v.erase(v.begin() + num);
    res.append(getPermutation1(n - 1, (k - 1) % cnt + 1, cnt, v));
    return res;
  }

  int calc_factorial(int k){
    if (k == 0){
      return 1;
    }
    return calc_factorial(k - 1) * k;
  }
};

int main(){
  Solution s;
  cout << s.getPermutation(1, 1) << endl;
  cout << s.getPermutation(3, 2) << endl;
  cout << s.getPermutation(3, 3) << endl;
  cout << s.getPermutation(3, 4) << endl;
  cout << s.getPermutation(3, 5) << endl;
  cout << s.getPermutation(3, 6) << endl;
  return 0;
}
