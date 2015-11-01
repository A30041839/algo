class Solution {
  vector<vector<int>> buildGraph(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> g(n, vector<int>());
    for (auto& edge : edges) {
      g[edge.first].push_back(edge.second);
      g[edge.second].push_back(edge.first);
    }
    return g;
  }

public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> g = buildGraph(n, edges);
    vector<bool> visit(n, false);
    visit[0] = true;
    if (dfs(g, visit, -1, 0)) {
      return false;
    }
    int cnt = 0;
    for (bool f : visit) {
      if (!f) {
        return false;
      }
    }
    return true;
  }

  bool dfs(vector<vector<int>>& g, vector<bool>& visit, int prev, int cur) {
    for (int next : g[cur]) {
      if (next != prev) {
        if (visit[next] == false) {
          visit[next] = true;
          if (dfs(g, visit, cur, next)) {
            return true;
          }
        }else {
          return true;
        }
      }
    }
    return false;
  }
};
