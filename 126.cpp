#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict){
    dict.insert(end);
    return bfs(start, end, dict);
  }

  void dfs_path(string start, string cur, unordered_map<string, vector<string>>& trace,
    vector<vector<string>>& res, vector<string>& path){
    if (cur == start){
      res.push_back({path.rbegin(), path.rend()});
      return;
    }
    for (auto& w : trace[cur]){
      path.push_back(w);
      dfs_path(start, w, trace, res, path);
      path.pop_back();
    }
  }

  vector<vector<string>> bfs(string& start, string& end, unordered_set<string>& dict) {
    queue<string> q;
    vector<vector<string>> res;
    unordered_map<string, vector<string>> trace;
    unordered_set<string> visit;
    visit.insert(start);
    q.push(start);
    bool stop = false;

    while (!q.empty() and !stop){
      unordered_set<string> next_level;
      int len = q.size();
      for (int i = 0; i < len; ++i){
        string w = q.front();
        q.pop();
        if (w == end){
          stop = true;
          break;
        }
        for (int j = 0; j < w.length(); ++j){
          string w_next = w;
          for (char c = 'a'; c <= 'z'; ++c){
            w_next[j] = c;
            if (w_next != w and dict.count(w_next) > 0 and !visit.count(w_next)){
              trace[w_next].push_back(w);
              next_level.insert(w_next);
            }
          }
        }
      }
      for (string w_next : next_level) {
        visit.insert(w_next);
        q.push(w_next);
      }
    }
    vector<string> path = {end};
    dfs_path(start, end, trace, res, path);
    return res;
  }
};

int main(){
  Solution s;
  unordered_set<string> dict = {"ted","tex","red","tax","tad","den","rex","pee"};
  string start = "red";
  string end = "tax";
  vector<vector<string>> res = s.findLadders(start, end, dict);
  for (auto& v : res){
    for (auto& str : v){
      cout << str << "->";
    }
    cout << endl;
  }
  return 0;
}
