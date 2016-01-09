class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    int n = nums.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(make_pair(nums[i], i));
    }
    vector<int> res(n, 0);
    mergesort(v, res, 0, n - 1);
    return res;
  }

  void mergesort(vector<pair<int, int>>& v, vector<int>& res, int l, int h) {
    if (l >= h) {
      return;
    }
    int mid = l + (h - l) / 2;
    mergesort(v, res, l, mid);
    mergesort(v, res, mid + 1, h);
    int i = l, j = mid + 1;
    vector<pair<int, int>> tmp;
    while (i <= mid and j <= h) {
      if (v[i].first <= v[j].first) {
        res[v[i].second] += (j - mid - 1);
        tmp.push_back(v[i++]);
      }else {
        tmp.push_back(v[j++]);
      }
    }
    while (i <= mid) {
      res[v[i].second] += (j - mid -  1);
      tmp.push_back(v[i++]);
    }
    while (j <= h) {
      tmp.push_back(v[j++]);
    }
    copy(tmp.begin(), tmp.end(), v.begin() + l);
  }
};
