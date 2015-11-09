class Solution {
  bool valid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
  }

public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    int m = image.size(), n = image[0].size();
    int xmin = x, xmax = x, ymin = y, ymax = y;
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    visit[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    while (!q.empty()) {
      int curx = get<0>(q.front());
      int cury = get<1>(q.front());
      q.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        if (valid(nx, ny, m, n) and image[nx][ny] == '1' and !visit[nx][ny]) {
          visit[nx][ny] = true;
          xmin = min(xmin, nx);
          xmax = max(xmax, nx);
          ymin = min(ymin, ny);
          ymax = max(ymax, ny);
          q.push({nx, ny});
        }
      }
    }
    return (xmax - xmin + 1) * (ymax - ymin + 1);
  }
};
