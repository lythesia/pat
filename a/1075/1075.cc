#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct stu {
  int id = 0, tot = 0, pp[6] = {-1,-1,-1,-1,-1,-1}, sol = 0;
  bool has = false;
};
bool cmp(const stu &x, const stu &y) {
  return x.tot != y.tot ? x.tot > y.tot :
         x.sol != y.sol ? x.sol > y.sol :
         x.id < y.id;
}
int N, K, M, p[6];
stu st[10001];
int main(int argc, const char *argv[])
{
  scanf("%d%d%d", &N, &K, &M);
  for(int i=1; i<=K; i++) scanf("%d", &p[i]);
  while(M--) {
    int n, i, s;
    scanf("%d%d%d", &n, &i, &s);
    st[n].id = n;
    if(s != -1) st[n].pp[i] = max(st[n].pp[i], s), st[n].has = true;
    else st[n].pp[i] = 0;
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=K; j++) {
      st[i].tot += (st[i].pp[j] == -1 ? 0 : st[i].pp[j]), st[i].sol += st[i].pp[j] == p[j];
    }
  }
  sort(st + 1, st + N + 1, cmp);
  int rkt = 0;
  for(int i=1, prk=0, prt=-1; i<=N; i++) {
    if(st[i].has) {
      ++rkt;
      if(st[i].tot != prt) prk = rkt, prt = st[i].tot;
      printf("%d %05d %d", prk, st[i].id, st[i].tot);
      for(int j=1; j<=K; j++) st[i].pp[j] == -1 ? printf(" -") : printf(" %d", st[i].pp[j]);
      puts("");
    }
  }
  return 0;
}
