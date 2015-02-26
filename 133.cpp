#include "leetcode.h"

using namespace std;

class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node){
      return nullptr;
    }
    return bfs(node);
  }

  UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& visit){
    if (visit.count(node->label) > 0){
      return visit[node->label];
    }
    UndirectedGraphNode* node_copy = new UndirectedGraphNode(node->label);
    visit[node->label] = node_copy;
    for (UndirectedGraphNode* next : node->neighbors){
      node_copy->neighbors.push_back(dfs(next, visit));
    }
    return node_copy;
  }

  UndirectedGraphNode* bfs(UndirectedGraphNode* node){
    queue<UndirectedGraphNode*> q1;
    queue<UndirectedGraphNode*> q2;
    q1.push(node);
    UndirectedGraphNode* node_copy = new UndirectedGraphNode(node->label);
    q2.push(node_copy);
    unordered_map<int, UndirectedGraphNode*> visit;
    visit[node->label] = node_copy;

    while (!q1.empty()){
      UndirectedGraphNode* cur1 = q1.front();
      q1.pop();
      UndirectedGraphNode* cur2 = q2.front();
      q2.pop();
      for (UndirectedGraphNode* next : cur1->neighbors){
        if (visit.count(next->label) > 0){
          cur2->neighbors.push_back(visit[next->label]);
        }else{
          UndirectedGraphNode* new_node = new UndirectedGraphNode(next->label);
          q1.push(next);
          q2.push(new_node);
          cur2->neighbors.push_back(new_node);
          visit[next->label] = new_node;
        }
      }
    }
    return node_copy;
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
