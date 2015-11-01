class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty() or rooms[0].empty()) {
      return;
    }
    queue<pair<pair<int, int>, int>> q;
    int m = rooms.size(), n = rooms[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (rooms[i][j] == 0) {
          q.push({{i, j}, 0});
        }
      }
    }
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    while (!q.empty()) {
      int curx = q.front().first.first;
      int cury = q.front().first.second;
      int dist = q.front().second;
      q.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int nx = curx + dirx[dir];
        int ny = cury + diry[dir];
        if (nx >= 0 and nx < m and ny >= 0 and ny < n and rooms[nx][ny] > 0) {
          if (dist + 1 < rooms[nx][ny]) {
            rooms[nx][ny] = dist + 1;
            q.push({{nx, ny}, dist + 1});
          }
        }
      }
    }
  }
};
