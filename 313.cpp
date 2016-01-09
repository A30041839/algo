class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<long> res = {1};
    int k = primes.size();
    vector<int> id(k, 0);
    vector<long> tmp(k, 0);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        tmp[j] = res[id[j]] * primes[j];
      }
      long minv = *min_element(tmp.begin(), tmp.end());
      res.push_back(minv);
      for (int j = 0; j < k; ++j) {
        if (tmp[j] == minv) {
          id[j]++;
        }
      }
    }
    return (int)res.back();
  }
};
