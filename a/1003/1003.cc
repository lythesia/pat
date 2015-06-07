#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
int N, M, C1, C2;
vector<pii> e[500]; // edge: <node, dist>
int t[500];         // team
int d[500], r[500], c[500]; // dist, rescues, counts
bool v[500];        // visited

void dijkstra() {
  priority_queue<pii, vector<pii>, greater<pii>> Q; // <dist, #>
  d[C1] = 0, r[C1] = t[C1], c[C1] = 1;
  Q.push(pii{0, C1});
  while(!Q.empty()) {
    pii u = Q.top(); Q.pop();
    int x = u.second;
    if(v[x]) continue;
    for(pii &p : e[x]) {
      int y = p.first, l = p.second, dy = d[x] + l;
      Q.push(pii{dy, y});
      if(dy < d[y]) d[y] = dy, r[y] = r[x]+t[y], c[y] = c[x];
      else if(dy == d[y]) r[y] = max(r[y], r[x]+t[y]), c[y] += c[x];
    }
    v[x] = true;
  }
}

int main(int argc, const char *argv[])
{
  scanf("%d%d%d%d", &N, &M, &C1, &C2);
  int c1, c2, l;
  for(int i=0; i<N; i++) scanf("%d", &t[i]);
  for(int i=0; i<M; i++) {
    // c1 - c2's shorter gap is guaranteed, no need to check
    scanf("%d%d%d", &c1, &c2, &l);
    e[c1].emplace_back(pii{c2, l});
    e[c2].emplace_back(pii{c1, l});
  }
  memset(d, 0x3f, sizeof(d));
  dijkstra();
  printf("%d %d\n", c[C2], r[C2]);
  return 0;
}
