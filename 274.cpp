#include "leetcode.h"

using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int n = citations.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (citations[i] > res) {
        res++;
      }else {
        break;
      }
    }
    return res;
  }
};
