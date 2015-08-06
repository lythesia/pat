#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
int head, N, K, nxt[100001], val[100001], tot;
const int dummy = 100000;
int rev(int h) {
  if(h == -1 || nxt[h] == -1) return h;
  int prev = h, p = nxt[h];
  while(p != -1) {
    int t = nxt[p];
    nxt[p] = prev, prev = p, p = t;
  }
  nxt[h] = -1;
  return prev;
}
int krev() {
  nxt[dummy] = head;
  int prev = dummy, headk = dummy;
  if(K < 2) return head;
  do {
    for(int i=0; i<K; i++) {
      headk = nxt[headk];
      if(nxt[headk] == -1) {
        if(i < K-1) { // len < K, no rev
          nxt[prev] = head;
          return nxt[dummy];
        }
        else {        // rev last group
          nxt[prev] = rev(head);
          return nxt[dummy];
        }
      }
    }
    if(nxt[headk] == -1) break;
    int t = nxt[headk];
    nxt[headk] = -1, nxt[prev] = rev(head), nxt[head] = t;
    prev = head, head = t, headk = prev;
  } while(headk != -1);
  return nxt[dummy];
}
int main(int argc, const char *argv[])
{
  scanf("%d%d%d", &head, &N, &K);
  int a;
  while(N--) scanf("%d", &a), scanf("%d %d", &val[a], &nxt[a]);
  int p = krev();
  while(p != -1) {
    printf("%05d %d ", p, val[p]);
    nxt[p] == -1 ? puts("-1") : printf("%05d\n", nxt[p]);
    p = nxt[p];
  }
  return 0;
}
