#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, L;
vi to[1001];
bool v[1001];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &L);
  int k, x;
  for(int i=1; i<=N; i++) {
    scanf("%d", &k);
    while(k--) {
      scanf("%d", &x);
      to[x].push_back(i);
    }
  }
  scanf("%d", &k);
  while(k--) {
    scanf("%d", &x);
    memset(v, 0, sizeof(v));
    queue<int> Q[2];
    int tot = 0, lv = 0;
    Q[lv].push(x); v[x] = true;
    while(lv < L && !Q[lv % 2].empty()) {
      int t = Q[lv % 2].front(); Q[lv % 2].pop();
      for(int n : to[t]) if(!v[n]) Q[1 - lv % 2].push(n), tot++, v[n] = true;
      if(Q[lv % 2].empty()) lv++;
    }
    printf("%d\n", tot);
  }
  return 0;
}
