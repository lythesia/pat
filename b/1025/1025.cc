#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int dummy = 100000; // largest as dummy
int nxt[100001], dat[100001];

int rev(int h) {
  if(h == -1 || nxt[h] == -1) return h;
  int prev = h, curr = nxt[h];
  while(curr != -1) {
    int t = nxt[curr];
    nxt[curr] = prev, prev = curr, curr = t;
  }
  nxt[h] = -1;
  return prev;
}

int main(int argc, const char *argv[])
{
  int head, n, k;
  scanf("%d%d%d", &head, &n, &k);
  for(int i=0; i<n; i++) {
    int a, d, n;
    scanf("%d%d%d", &a, &d, &n);
    dat[a] = d, nxt[a] = n;
  }
  nxt[dummy] = head;
  int p = head, h = dummy, cnt = 0;
  while(p != -1) {
    if(!(++cnt % k)) {
      int t1 = nxt[h], t2 = nxt[p];
      nxt[p] = -1;  // temporarily end it for reverse
      nxt[h] = rev(nxt[h]);
      nxt[t1] = t2, h = t1, p = t1;
    }
    p = nxt[p];
  }
  head = nxt[dummy];
  while(head != -1) printf("%05d %d ", head, dat[head]), nxt[head] == -1 ? puts("-1") : printf("%05d\n", nxt[head]), head = nxt[head];
  return 0;
}
