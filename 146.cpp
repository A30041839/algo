#include "leetcode.h"

using namespace std;

class LRUCache{
public:
  struct cacheItem{
    int key;
    int val;
    cacheItem(int _key, int _val): key(_key), val(_val) {}
  };

  LRUCache(int capacity) {
    m_capacity = capacity;
  }

  int get(int key) {
    if (m_map.count(key) > 0) {
      move_to_front(m_map[key]);
      m_map[key] = m_list.begin();
      return m_list.front().val;
    }else {
      return -1;
    }
  }

  void set(int key, int value) {
    if (m_map.count(key) > 0) {
      m_map[key]->val = value;
      move_to_front(m_map[key]);
      m_map[key] = m_list.begin();
    }else {
      if (m_map.size() == m_capacity) {
        int del = m_list.back().key;
        m_list.pop_back();
        m_map.erase(del);
      }
      cacheItem newItem(key, value);
      m_list.push_front(newItem);
      m_map[key] = m_list.begin();
    }
  }

private:
  int m_capacity;
  unordered_map<int, list<cacheItem>::iterator> m_map;
  list<cacheItem> m_list;

  void move_to_front(list<cacheItem>::iterator iter) {
    m_list.push_front(*iter);
    m_list.erase(iter);
  }
};

int main(){
  LRUCache lru(10);
  cout << lru.get(1) << endl;
  for (int i = 1; i <= 10000000; ++i){
    lru.set(i, i * i);
  }
  cout << lru.get(4) << endl;
  lru.set(11, 121);
  cout << lru.get(1) << endl;
  cout << lru.get(11) << endl;
  return 0;
}
