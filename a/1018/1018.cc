#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
int C, N, sp, M;
vector<pii> e[501];
int s[501], d[501];
int K, R = INF, B = INF;
bool v[501];
vi p, P;

/*
 * dijkstra/spfa to find shortest path's length
 * dfs to find satisfied unique path with shortest length:
 *  1. less send out
 *  2. less take back
 */
void dijkstra() {
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  memset(d, 0x3f, sizeof(d));
  d[0] = 0;
  Q.push(pii{0, 0});
  while(!Q.empty()) {
    int x = Q.top().second; Q.pop();
    for(pii &n : e[x]) {
      if(v[n.first]) continue;
      int y = n.first, dy = d[x] + n.second;
      Q.emplace(pii{dy, y});
      if(dy < d[y]) d[y] = dy;
    }
    v[x] = true;
  }
}

void spfa() {
  queue<int> Q;
  memset(d, 0x3f, sizeof(d));
  d[0] = 0, v[0] = true;
  Q.push(0);
  while(!Q.empty()) {
    int x = Q.front(); Q.pop();
    for(pii &n : e[x]) {
      int y = n.first, dy = d[x] + n.second;
      if(dy < d[y]) {
        d[y] = dy;
        if(!v[y]) { Q.push(y); v[y] = true; }
      }
    }
    v[x] = false;
  }
}

void dfs(int x, int k, int r, int b) {
  if(k > K) return;
  if(x == sp && k == K) {
    if(r < R || (r == R && b < B)) R = r, B = b, P = p;
    return;
  }
  for(pii &n : e[x]) {
    if(v[n.first]) continue;
    int y = n.first, dy = k + n.second, need = C - s[y], given = b;
    v[y] = true;
    p.push_back(y);
    if(need > given) dfs(y, dy, r + need - given, 0);
    else dfs(y, dy, r, given - need);
    p.pop_back();
    v[y] = false;
  }
}

int main(int argc, const char *argv[])
{
  scanf("%d%d%d%d", &C, &N, &sp, &M), (C >>= 1);
  for(int i=1; i<=N; i++) scanf("%d", &s[i]);
  while(M--) {
    int x, y, d;
    scanf("%d %d %d", &x, &y, &d);
    e[x].emplace_back(pii{y, d});
    e[y].emplace_back(pii{x, d});
  }
  // dijkstra();
  spfa();
  memset(v, 0, sizeof(v));
  v[0] = true, K = d[sp];
  dfs(0, 0, 0, 0);
  printf("%d ", R);
  putchar('0');
  for(int i : P) printf("->%d", i);
  printf(" %d\n", B);
  return 0;
}
