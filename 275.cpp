#include "leetcode.h"

using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    int i = 0, j = n - 1;
    while (i <= j) {
      int mid = i + (j - i) / 2;
      if (citations[mid] == n - mid) {
        return citations[mid];
      }else if (citations[mid] < n - mid) {
        i = mid + 1;
      }else {
        j = mid - 1;
      }
    }
    return n - 1 - j;
  }
};
