#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int INF = 0x3f3f3f3f;
int S = 0, D = 1, N, K;
map<string, int> planet;
struct edge {
  int n, c;
};
int e[1005][1005];

bool bfs(vi &path) {
  vector<bool> visited(K);
  queue<int> Q;
  Q.push(S), visited[S] = true;
  while(!Q.empty()) {
    int t = Q.front(); Q.pop();
    for(int i=0; i<K; i++) {
      if(!visited[i] && e[t][i]) Q.push(i), visited[i] = true, path[i] = t;
    }
  }
  return visited[D];
}

int max_flow() {
  int ans = 0;
  vi path(K);
  while(bfs(path)) {
    int mmin = INF;
    for(int i=D; i!=S; i=path[i]) mmin = min(mmin, e[path[i]][i]); // path[i] -> i
    for(int i=D; i!=S; i=path[i]) {
      int j = path[i]; // j -> i
      e[j][i] -= mmin, e[i][j] += mmin;
    }
    ans += mmin;
  }
  return ans;
}

int main(int argc, const char *argv[])
{
  char src[4], dst[4];
  int c;
  scanf("%s %s %d", src, dst, &N);
  planet.insert(make_pair(string(src), K++));
  planet.insert(make_pair(string(dst), K++));
  while(N--) {
    scanf("%s %s %d", src, dst, &c);
    string ss(src), dd(dst);
    if(!planet.count(ss)) planet.insert(make_pair(ss, K++));
    if(!planet.count(dd)) planet.insert(make_pair(dd, K++));
    e[planet[ss]][planet[dd]] = max(e[planet[ss]][planet[dd]], c);
  }
  printf("%d\n", max_flow());
  return 0;
}
