#include "leetcode.h"

using namespace std;

class Solution {
public:
  void sortColors(int A[], int n) {
    if (n < 1){
      return;
    }
    int b[3] = {0, 0, 0};
    for (int i = 0; i < n; ++i){
      b[A[i]]++;
    }
    int k = 0;
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < b[i]; ++j){
        A[k++] = i;
      }
    }
  }
};

class Solution2 {
public:
  void sortColors(int A[], int n) {
    if (n < 1){
      return;
    }
    int b[3] = {0, 0, 0};
    for (int i = 0; i < n; ++i){
      b[A[i]]++;
    }
    int k = 0;
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < b[i]; ++j){
        A[k++] = i;
      }
    }
  }
};


class Solution1 {
public:
  void sortColors(int A[], int n) {
    if (n > 0){
      q_sort(A, 0, n - 1);
    }
  }

  void q_sort(int A[], int start, int finish){
    if (start < finish){
      int pos = partition(A, start, finish);
      q_sort(A, start, pos - 1);
      q_sort(A, pos + 1, finish);
    }
  }

  int partition(int A[], int start, int finish){
    int i = -1;
    int mid = (start + finish) / 2;
    swap(A[mid], A[finish]);
    for (int j = 0; j < finish; ++j){
      if (A[j] <= A[finish]){
        swap(A[++i], A[j]);
      }
    }
    swap(A[i + 1], A[finish]);
    return i + 1;
  }

};

int main(){
  int A[5] = {2,1,0,1,0};
  Solution s;
  s.sortColors(A, 5);
  for (int i = 0; i < 5; ++i){
    cout << A[i] << ",";
  }
  cout << endl;
  return 0;
}
