class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    if (A.empty() or B.empty() or A[0].empty() or B[0].empty()) {
      return {};
    }
    vector<tuple<int,int,int>> a, b;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A[i].size(); ++j) {
        if (A[i][j]) {
          a.push_back(make_tuple(i, j, A[i][j]));
        }
      }
    }
    for (int i = 0; i < B.size(); ++i) {
      for (int j = 0; j < B[i].size(); ++j) {
        if (B[i][j]) {
          b.push_back(make_tuple(i, j, B[i][j]));
        }
      }
    }
    vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        if (get<1>(a[i]) != get<0>(b[j])) continue;
        int tmp = get<2>(a[i]) * get<2>(b[j]);
        res[get<0>(a[i])][get<1>(b[j])] += tmp;
      }
    }
    return res;
  }
};
