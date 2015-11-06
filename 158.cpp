// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  char cache[3];
  int cache_size = 0;
public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    if (n <= 0) {
      return 0;
    }
    int read_len = 0;
    if (cache_size > 0) {
      //copies cache content
      read_len = min(n, cache_size);
      memcpy(buf, cache, read_len);
      memcpy(cache, cache + read_len, cache_size - read_len);
      cache_size -= read_len;
    }
    while (read_len < n) {
      int cur = read4(buf + read_len);
      read_len += cur;
      if (cur < 4) {
        break;
      }
    }
    if (read_len > n) {
      //copy remain reading chars to cache
      memcpy(cache, buf + n, read_len - n);
      cache_size = read_len - n;
    }
    read_len = min(read_len, n);
    buf[read_len] = '\0';
    return read_len;
  }
};
