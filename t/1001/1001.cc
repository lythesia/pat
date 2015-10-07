#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int INF = 0x3f3f3f3f;
int N, M;
int fa[501];
struct edge {
  int x, y, c, u;
};
edge e[500 * 500 / 2 + 1];

int fnd(int x) {
  return fa[x] == x ? x : (fa[x] = fnd(fa[x]));
}
bool mrg(int x, int y) {
  int fx = fnd(x), fy = fnd(y);
  if(fx != fy) {
    fa[fx] = fy;
    return true;
  }
  else return false;
}

int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &M);
  for(int i=0; i<M; i++) scanf("%d%d%d%d", &e[i].x, &e[i].y, &e[i].c, &e[i].u), e[i].c = e[i].u ? 0 : e[i].c;
  vi ans;
  int mmax = 1; // 0 indicates connected
  bool never = false;
  sort(e, e + M, [](const edge &e1, const edge &e2){return e1.c < e2.c;});
  for(int i=1; i<=N; i++) { // discard city i
    int need = N - 2, cost = 0;
    for(int j=1; j<=N; j++) fa[j] = j; // init
    for(int j=0; j<M && need; j++) {
      if(e[j].x != i && e[j].y != i && mrg(e[j].x, e[j].y)) need--, cost += e[j].c;
    }
    if(need) { // never connected
      if(!never) ans.clear(), never = true;
      ans.push_back(i);
    }
    else {
      if(never) continue;
      else {
        if(cost > mmax) mmax = cost, ans.clear(), ans.push_back(i);
        else if(cost == mmax) ans.push_back(i);
      }
    }
  }
  if(ans.empty()) printf("0");
  else for(size_t i=0; i<ans.size(); i++) printf("%s%d", i?" ":"", ans[i]);
  puts("");
  return 0;
}
