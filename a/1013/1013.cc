#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M, K;
int f[1000];
struct edge {
  int x, y;
} e[1000*1000/2];

int fnd(int x) {
  if(f[x] == x) return x;
  else return f[x] = fnd(f[x]);
}
void mrg(int x, int y) {
  int fx = fnd(x), fy = fnd(y);
  if(fx != fy) f[fy] = fx;
}

int main(int argc, const char *argv[])
{
  scanf("%d%d%d", &N, &M, &K);
  for(int i=0; i<M; i++) scanf("%d%d", &e[i].x, &e[i].y);
  while(K--) {
    for(int i=1; i<=N; i++) f[i] = i;
    int c;
    scanf("%d", &c);
    for(int i=0; i<M; i++) if(e[i].x != c && e[i].y != c) mrg(e[i].x, e[i].y);
    int ans = 0;
    for(int i=1; i<=N; i++) if(f[i] == i) ans++;
    printf("%d\n", ans-2);
  }
  return 0;
}
