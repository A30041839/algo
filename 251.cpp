class Vector2D {
  vector<vector<int>::iterator> iters;
  vector<vector<int>::iterator> iters_end;
  int id;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        int n = vec2d.size();
        for (int i = 0; i < n; ++i) {
          iters.push_back(vec2d[i].begin());
          iters_end.push_back(vec2d[i].end());
        }
        id = 0;
    }

    int next() {
      int ret = *iters[id];
      iters[id]++;
      return ret;
    }

    bool hasNext() {
        while (id < iters.size() and iters[id] == iters_end[id]) {
          id++;
        }
        return id != iters.size(); 
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
