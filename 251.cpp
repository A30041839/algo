class Vector2D {
  vector<vector<int>::iterator> iters_beg;
  vector<vector<int>::iterator> iters_end;
  int idx = -1;
public:
  Vector2D(vector<vector<int>>& vec2d) {
    int n = vec2d.size();
    for (int i = 0; i < n; ++i) {
      if (!vec2d[i].empty()) {
        iters_beg.push_back(vec2d[i].begin());
        iters_end.push_back(vec2d[i].end());
      }
    }
    if (!iters_beg.empty()) {
      idx = 0;
    }
  }

  int next() {
    int ret = *iters_beg[idx];
    if (++iters_beg[idx] == iters_end[idx]) {
      idx = idx < iters_beg.size() - 1 ? idx + 1 : -1;
    }
    return ret;
  }

  bool hasNext() {
    return idx != -1;
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
