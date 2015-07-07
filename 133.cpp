#include "leetcode.h"

using namespace std;

class Solution {
public:
  typedef UndirectedGraphNode UGN;
  UGN *cloneGraph(UGN *node) {
    if (!node) {
      return nullptr;
    }
    //unordered_map<UGN*, UGN*> mp;
    //return dfs(node, mp);
    return bfs(node);
  }

  UGN* dfs(UGN* node,
    unordered_map<UGN*, UGN*>& mp){
    if (mp.find(node) != mp.end()) {
      return mp[node];
    }
    UGN* nodeCpy = new UGN(node->label);
    mp[node] = nodeCpy;
    for (auto& next : node->neighbors) {
      nodeCpy->neighbors.push_back(dfs(next, mp));
    }
    return nodeCpy;
  }

  UGN* bfs(UGN* node){
    queue<UGN*> q;
    unordered_map<UGN*, UGN*> mp;
    q.push(node);
    mp[node] = new UGN(node->label);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto& next : cur->neighbors) {
        if (mp.find(next) == mp.end()) {
          mp[next] = new UGN(next->label);
          q.push(next);
        }
        mp[cur]->neighbors.push_back(mp[next]);
      }
    }
    return mp[node];
  }
};

int main(){
  Solution s;
  UndirectedGraphNode* node1 = new UndirectedGraphNode(0);
  UndirectedGraphNode* node2 = new UndirectedGraphNode(1);
  UndirectedGraphNode* node3 = new UndirectedGraphNode(2);
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node3);
  node2->neighbors.push_back(node1);
  node2->neighbors.push_back(node3);
  node3->neighbors.push_back(node1);
  node3->neighbors.push_back(node2);
  node3->neighbors.push_back(node3);

  UndirectedGraphNode* copy = s.cloneGraph(node1);

  return 0;
}
