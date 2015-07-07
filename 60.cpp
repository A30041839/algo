#include "leetcode.h"

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    return getPermutation3(n, k);
  }

private:
  string _getPermutation1(int n, int k, int cnt, vector<char>& v) {
    if (n == 0) {
      return "";
    }
    string res;
    cnt /= n;
    int i = (k - 1) / cnt;
    res.push_back(v[i]);
    v.erase(v.begin() + i);
    res.append(_getPermutation1(n - 1, k - i *cnt, cnt, v));
    return res;
  }

  //recursive
  string getPermutation1(int n, int k) {
    vector<char> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i + '1');
    }
    int cnt = calc_factorial(n);
    return _getPermutation1(n, k, cnt, v);
  }

  int calc_factorial(int k){
    if (k == 0){
      return 1;
    }
    return calc_factorial(k - 1) * k;
  }

  //TLE
  string getPermutation2(int n, int k) {
    vector<int> v;
    string res;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
    }
    for (int i = 0; i < k - 1; ++i) {
      nextPermutation(v);
    }
    for (int i = 0; i < n; ++i) {
      res.push_back(v[i] + '1');
    }
    return res;
  }

  void nextPermutation(vector<int> &nums) {
    if (nums.empty()) {
      return;
    }
    int pos1 = -1, pos2 = 0;
    int n = nums.size();
    for (int i = n - 1; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        pos1 = i - 1;
        break;
      }
    }
    if (pos1 == -1) {
      sort(nums.begin(), nums.end());
      return;
    }
    for (int i = n - 1; i > 0; --i) {
      if (nums[i] > nums[pos1]) {
        pos2 = i;
        break;
      }
    }
    swap(nums[pos1], nums[pos2]);
    reverse(nums.begin() + pos1 + 1, nums.end());
  }

  //iterative
  string getPermutation3(int n, int k) {
    int cnt = calc_factorial(n), j;
    string res;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
    }
    for (int i = n; i >= 1; --i) {
      cnt /= i;
      j = (k - 1) / cnt;
      res.push_back('1' + v[j]);
      v.erase(v.begin() + j);
      k -= j * cnt;
    }
    return res;
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
