#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct edge {
  int n, dd;
};
int N, M, K, D;
// vector<edge> e[1011];
unordered_map<int, int> e[1101];
bool v[1011];
int d[1011];

struct gas {
  int mmin;
  double avg;
  bool out;
};
gas g[11];

void spfa(int s) {
  memset(v, 0, sizeof(v));
  memset(d, 0x3f, sizeof(d));

  d[s] = 0;
  queue<int> Q;
  v[s] = true;
  Q.push(s);
  while(!Q.empty()) {
    int x = Q.front(); Q.pop();
    v[x] = false;
    for(auto &y : e[x]) {
      int nd = d[x] + y.second;
      if(nd < d[y.first]) {
        d[y.first] = nd;
        if(!v[y.first]) {
          v[y.first] = true;
          Q.push(y.first);
        }
      }
    }
  }
}

int main(int argc, const char *argv[])
{
  scanf("%d%d%d%d", &N, &M, &K, &D);
  int c[2], dd;
  char buf[2][4] = {0};
  while(K--) {
    scanf("%s %s %d", buf[0], buf[1], &dd);
    for(int i=0; i<2; i++) {
      if(buf[i][0] == 'G') c[i] = atoi(buf[i] + 1) + N;
      else c[i] = atoi(buf[i]);
    }
    if(e[c[0]].count(c[1])) e[c[0]][c[1]] = min(e[c[0]][c[1]], dd), e[c[1]][c[0]] = min(e[c[1]][c[0]], dd);
    else e[c[0]][c[1]] = e[c[1]][c[0]] = dd;
  }
  for(int i=1; i<=M; i++) {
    spfa(N + i);
    g[i].out = false;
    int tot = 0, mmin = INT_MAX;
    for(int j=1; j<=N; j++) {
      if(d[j] <= D) tot += d[j], mmin = min(mmin, d[j]);
      else {
        g[i].out = true;
        break;
      }
    }
    if(!g[i].out) g[i].mmin = mmin, g[i].avg = 1.0 * tot / N;
  }
  int ans = 0, mmin = 0;
  double avg = DBL_MAX;
  for(int i=1; i<=M; i++) {
    if(g[i].out) continue;
    if(g[i].mmin > mmin) mmin = g[i].mmin, avg = g[i].avg, ans = i;
    else if(g[i].mmin == mmin && g[i].avg < avg) avg = g[i].avg, ans = i;
  }
  if(!ans) puts("No Solution");
  else printf("G%d\n%.1lf %.1lf\n", ans, (double)g[ans].mmin, g[ans].avg + 0.005);
  return 0;
}
