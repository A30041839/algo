#include "leetcode.h"

using namespace std;

class LRUCache{
private:
  list<pair<int, int>> mlist;
  unordered_map<int, list<pair<int, int>>::iterator> mmap;
  int mcapacity;

  void move_to_front(int key, list<pair<int, int>>::iterator iter) {
    if (iter == mlist.begin()) {
      return;
    }
    mlist.push_front(*iter);
    mlist.erase(iter);
    mmap[key] = mlist.begin();
  }

public:
  LRUCache(int capacity) {
    mcapacity = capacity;
  }

  int get(int key) {
    if (mmap.find(key) != mmap.end()) {
      move_to_front(key, mmap[key]);
      return mmap[key]->second;
    }else {
      return -1;
    }
  }

  void set(int key, int value) {
    if (mmap.find(key) != mmap.end()) {
      move_to_front(key, mmap[key]);
      mmap[key]->second = value;
    }else {
      if (mmap.size() == mcapacity) {
        int remove_key = mlist.back().first;
        mmap.erase(remove_key);
        mlist.pop_back();
      }
      mlist.push_front(make_pair(key, value));
      mmap[key] = mlist.begin();
    }
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
