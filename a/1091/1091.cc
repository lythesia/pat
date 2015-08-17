#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef tuple<int, int, int> pt;

const int dir[6][3] = {
  { 1,  0,  0}, // below
  {-1,  0,  0}, // above
  { 0,  1,  0}, // down
  { 0, -1,  0}, // up
  { 0,  0,  1}, // right
  { 0,  0, -1}, // left
};
int M, N, L, T;
bool a[60][1286][128];
bool check(int i, int j, int k) {
  return (i>=0 && i<L) && (j>=0 && j<M) && (k>=0 && k<N);
}
void dfs(int i, int j, int k, int &v) {
  if(!a[i][j][k]) return;
  queue<pt> Q;
  Q.push(pt{i, j, k});
  while(!Q.empty()) {
    auto t = Q.front(); Q.pop();
    int x = get<0>(t), y = get<1>(t), z = get<2>(t);
    if(a[x][y][z]) {
      a[x][y][z] = false, v++;
      for(int i=0; i<6; i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1], nz = z + dir[i][2];
        if(check(nx, ny, nz)) Q.push(pt{nx, ny, nz});
      }
    }
  }
}
int main(int argc, const char *argv[])
{
  scanf("%d%d%d%d", &M, &N, &L, &T);
  int x;
  for(int i=0; i<L; i++) for(int j=0; j<M; j++) for(int k=0; k<N; k++) scanf("%d", &x), a[i][j][k] = (x == 1);
  int ans = 0;
  for(int i=0; i<L; i++) for(int j=0; j<M; j++) for(int k=0; k<N; k++) {
    int v = 0;
    dfs(i, j, k, v);
    if(v >= T) ans += v; // if point in scc is over threshold, then every point in the scc is valid
  }
  printf("%d\n", ans);
  return 0;
}
