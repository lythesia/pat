#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M, S;
int w[101];
vi chd[101];
void dfs(int r, int s, vi &p) {
  int wi = w[r];
  if(s + wi > S) return;
  else if(s + wi == S) {
    if(chd[r].empty()) { // leaf
      for(int i : p) printf("%d ", i);
      printf("%d\n", wi);
    }
  }
  else {
    p.push_back(w[r]);
    for(int i : chd[r]) dfs(i, s + w[r], p);
    p.pop_back();
  }
}
int main(int argc, const char *argv[])
{
  scanf("%d%d%d", &N, &M, &S);
  for(int i=0; i<N; i++) scanf("%d", &w[i]);
  while(M--) {
    int id, k, c;
    scanf("%d%d", &id, &k);
    while(k--) {
      scanf("%d", &c);
      chd[id].push_back(c);
    }
    sort(chd[id].begin(), chd[id].end(), [](int x, int y){return w[x] > w[y];});
  }
  vi path;
  dfs(0, 0, path);
  return 0;
}
