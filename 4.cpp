#include "leetcode.h"

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int mid = (m + n) / 2;
    if ((m + n) % 2){
      return findKth(nums1.begin(), m, nums2.begin(), n, mid + 1);
    }else{
      return (double)(findKth(nums1.begin(), m, nums2.begin(), n, mid) +
              findKth(nums1.begin(), m, nums2.begin(), n, mid + 1)) / 2.0;
    }
  }

  int findKth(vector<int>::iterator iter1, int m, vector<int>::iterator iter2, int n, int k){
    if (m > n){
      return findKth(iter2, n, iter1, m, k);
    }
    if (m == 0){
      return *(iter2 + k - 1);
    }
    if (k == 1){
      return min(*iter1, *iter2);
    }
    int i = min(k / 2, m);
    int j = k - i;
    int a = *(iter1 + i - 1);
    int b = *(iter2 + j - 1);
    if (a > b) {
      return findKth(iter1, i, iter2 + j, n - j, k - j);
    }else if (a < b){
      return findKth(iter1 + i, m - i, iter2, j, k - i);
    }else{
      return a;
    }
  }
};

int main(){
  Solution s;
  vector<int> nums1 = {-1, 1, 3, 6, 6, 7};
  vector<int> nums2 = {2,4,9};
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
