#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;

// disjoint-set + bfs
int N, fa[10001], dep[10001];
vi edge[10001];

int fnd(int x) {
  if(fa[x] == x) return x;
  else return fa[x] = fnd(fa[x]);
}
void mrg(int x, int y) {
  int fx = fnd(x), fy = fnd(y);
  if(fx != fy) fa[fy] = fx;
}

int depth(int root) {
  queue<int> Q;
  Q.push(root);
  int ans = 0;
  while(!Q.empty()) {
    int t = Q.front(); Q.pop();
    for(int x : edge[t]) {
      if(fa[x]) continue;
      Q.push(x);
      ans = min(dep[x] = dep[t] - 1, ans);
    }
    fa[t] = true;
  }
  return ans;
}

int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=1; i<=N; i++) fa[i] = i;
  for(int i=1; i<=N-1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    edge[x].push_back(y);
    edge[y].push_back(x);
    mrg(x, y);
  }
  int c = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for(int i=1; i<=N; i++) c += (fa[i] == i);
  if(c > 1) printf("Error: %d components\n", c);
  else {
    for(int i=1; i<=N; i++) {
      memset(fa, 0, sizeof(fa));  // used as visit
      memset(dep, 0, sizeof(dep));
      pq.emplace(pii{depth(i), i});
    }
    int deepest = pq.top().first;
    while(!pq.empty()) {
      if(pq.top().first != deepest) break;
      printf("%d\n", pq.top().second);
      pq.pop();
    }
  }
  return 0;
}
