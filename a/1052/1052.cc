#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct node {
  int addr, key;
};
bool operator < (const node &x, const node &y) {
  return x.key < y.key;
}
int N, head;
node n[100000];
int key[100000], nxt[100000];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &head);
  int aa, kk, nn, tot = 0;
  for(int i=0; i<N; i++) scanf("%d%d%d", &aa, &kk, &nn), key[aa] = kk, nxt[aa] = nn;
  for(; head!=-1; head=nxt[head]) n[tot].addr = head, n[tot].key = key[head], tot++;
  sort(n, n + tot);
  if(tot) {
    printf("%d %05d\n", tot, n[0].addr);
    for(int i=1; i<tot; i++) printf("%05d %d %05d\n", n[i-1].addr, n[i-1].key, n[i].addr);
    printf("%05d %d -1\n", n[tot-1].addr, n[tot-1].key);
  }
  else puts("0 -1");
  return 0;
}
