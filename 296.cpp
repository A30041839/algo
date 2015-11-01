class Solution {
  int dist(int x, int y, vector<pair<int, int>>& v) {
    int res = 0;
    for (auto& p : v) {
      res += abs(p.first - x) + abs(p.second - y);
    }
    return res;
  }
public:
  int minTotalDistance(vector<vector<int>>& grid) {
    if (grid.empty() or grid[0].empty()) {
      return 0;
    }
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          v.push_back({i, j});
        }
      }
    }
    int resx, resy;
    int min_dist = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int cur_dist = dist(0, i, v);
      if (cur_dist < min_dist) {
        min_dist = cur_dist;
        resy = i;
      }
    }
    min_dist = INT_MAX;
    for (int i = 0; i < m; ++i) {
      int cur_dist = dist(i, resy, v);
      if (cur_dist < min_dist) {
        min_dist = cur_dist;
        resx = i;
      }
    }
    return dist(resx, resy, v);
  }
};
