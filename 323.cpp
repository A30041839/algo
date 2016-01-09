class Solution {
  int findRoot(vector<int>& arr, int k) {
    while (arr[k] != k) {
      k = arr[k];
    }
    return k;
  }

public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    if (n <= 0) {
      return 0;
    }
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
      arr.push_back(i);
    }
    int k = edges.size();
    for (int i = 0; i < k; ++i) {
      int r1 = findRoot(arr, edges[i].first);
      int r2 = findRoot(arr, edges[i].second);
      arr[r2] = r1;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] == i) {
        res++;
      }
    }
    return res;
  }
};
