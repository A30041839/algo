class Solution {
public:
string alienOrder(vector<string>& words) {
  if (words.empty()) {
    return "";
  }
  int n = (int)words.size();
  unordered_map<char, unordered_set<char>> g;
  unordered_map<char, int> indeg;
  for (string w : words) {
    for (char c : w) {
      g[c] = unordered_set<char>();
      indeg[c] = 0;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < (int)words[i].size() and j < (int)words[i + 1].size(); ++j) {
      if (words[i][j] != words[i + 1][j]) {
        g[words[i][j]].insert(words[i + 1][j]);
        break;
      }
    }
  }
  for (auto& p : g) {
    for (char next : p.second) {
      indeg[next]++;
    }
  }
  string res;
  queue<char> q;
  int size = (int)indeg.size();
  for (auto& p : indeg) {
    if (p.second == 0) {
      q.push(p.first);
    }
  }
  int cnt = 0;
  while (!q.empty()) {
    char c = q.front();
    q.pop();
    res.push_back(c);
    cnt++;
    for (char next : g[c]) {
      if (--indeg[next] == 0) {
        q.push(next);
      }
    }
  }
  return cnt < size ? "" : res;
}
};
