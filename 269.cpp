class Solution {
public:
  string alienOrder(vector<string>& words) {
    if (words.empty()) {
      return "";
    }
    int n = words.size();
    int k = 0;
    unordered_map<char, unordered_set<char>> g;
    unordered_map<char, int> indeg;
    for (string w : words) {
      for (char c : w) {
        g[c] = unordered_set<char>();
        indeg[c] = 0;
      }
    }
    bool f = true;
    while (f) {
      f = false;
      for (int i = 1; i < n; ++i) {
        if (words[i - 1].substr(0, k) == words[i].substr(0, k)) {
          if (k < words[i - 1].size() and k < words[i].size()) {
            f = true;
            if (words[i - 1][k] != words[i][k]) {
              g[words[i - 1][k]].insert(words[i][k]);
            }
          }
        }
      }
      k++;
    }
    string res;
    for (auto& p : g) {
      for (auto vtx: p.second) {
        indeg[vtx]++;
      }
    }
    queue<char> q;
    for (auto& p : indeg) {
      if (p.second == 0) {
        q.push(p.first);
      }
    }
    while (!q.empty()) {
      char c = q.front();
      q.pop();
      res.push_back(c);
      for (char next : g[c]) {
        if (--indeg[next] == 0) {
          q.push(next);
        }
      }
    }
    return res.size() == g.size() ? res : "";
  }
};
