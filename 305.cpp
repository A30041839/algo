class Solution {
  unordered_map<int, int> mp;
  vector<vector<int>> grid;
  int islandCount = 0;
  int iid = 0;
  vector<int> dx = {1, -1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};

  bool valid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
  }

  int getRoot(int id) {
    while (mp[id] != id) {
      id = mp[id];
    }
    return id;
  }

  int addIsland(pair<int, int>& pos) {
    int m = grid.size(), n = grid[0].size();
    int x = pos.first, y = pos.second;
    if (grid[x][y] != -1) {
      return islandCount;
    }
    //add a new island
    int minid = INT_MAX;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (!valid(nx, ny, m, n) or grid[nx][ny] == -1) {
        continue;
      }
      minid = min(minid, getRoot(grid[nx][ny]));
    }
    if (minid == INT_MAX) {
      grid[x][y] = iid;
      mp[iid] = iid;
      iid++;
      islandCount++;
      return islandCount;
    }
    int diff = 0;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (!valid(nx, ny, m, n) or grid[nx][ny] == -1) {
        continue;
      }
      if (getRoot(grid[nx][ny]) != minid) {
        diff++;
        mp[getRoot(grid[nx][ny])] = minid;
      }
    }
    grid[x][y] = minid;
    islandCount -= diff;
    return islandCount;
  }

public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    grid.assign(m, vector<int>(n, -1));
    vector<int> res;
    for (int i = 0; i < positions.size(); ++i) {
      res.push_back(addIsland(positions[i]));
    }
    return res;
  }
};
