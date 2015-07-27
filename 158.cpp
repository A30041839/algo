#include "leetcode.h"

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
  char _buf[3];
  int _buf_len;
public:
  Solution(): _buf_len(0) {}
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    if (n <= 0) {
      return 0;
    }
    int m, remain = n, offset = _buf_len;
    if (_buf_len > 0) {
      m = min(_buf_len, n);
      memcpy(buf, _buf, m);
      memcpy(_buf, _buf + m, _buf_len - m);
      remain -= m;
      _buf_len -= m;
    }
    if (remain == 0) {
      return n;
    }
    int n_read = 0, n_get;
    while (n_read < remain) {
      n_get = read4(buf + offset);
      offset += n_get;
      n_read += n_get;
      if (n_get < 4) {
        break;
      }
    }
    if (n_read > remain) {
      memcpy(_buf, buf + n, n_read - remain);
      _buf_len = n_read - remain;
    }
    int valid_len = min(offset, n);
    buf[valid_len] = '\0';
    return valid_len;
  }
};

int main(){
  return 0;
}
