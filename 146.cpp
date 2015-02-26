#include "leetcode.h"

using namespace std;

struct page{
  int key;
  int val;
  page* next;
  explicit page(int _key, int _val): key(_key), val(_val), next(0) {}
};

class LRUCache{
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
    head = new page(0, 0);
  }

  ~LRUCache(){
    page* p = head;
    while (p){
      page* tmp = p->next;
      delete p;
      p = tmp;
    }
  }

  int get(int key) {
    page* p1 = head, *p2 = head->next;
    int res = -1;
    while (p2){
      if (p2->key == key){
        res = p2->val;
        break;
      }
      p1 = p2;
      p2 = p2->next;
    }
    if (res != -1){
      p1->next = p2->next;
      p2->next = head->next;
      head->next = p2;
    }
    return res;
  }

  void set(int key, int value) {
    if (get(key) != -1){
      head->next->val = value;
    }else{
      if (size == capacity){
        page *p1 = head, *p2 = head->next;
        while (p2->next){
          p1 = p2;
          p2 = p2->next;
        }
        p1->next = 0;
        delete p2;
        page* tmp = head->next;
        head->next = new page(key, value);
        head->next->next = tmp;
      }else{
        size++;
        page* tmp = head->next;
        head->next = new page(key, value);
        head->next->next = tmp;
      }
    }
  }

  int capacity;
  int size;
  page* head;
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
