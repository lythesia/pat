#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M;
vi chd[100];
int ans, lv = 1;
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &M);
  int x, k, c;
  while(M--) {
    scanf("%d%d", &x, &k);
    while(k--) {
      scanf("%d", &c);
      chd[x].push_back(c);
    }
  }
  queue<int> Q[2];
  int cur = 0, dep = 1, cnt = 0;
  Q[cur].push(1);
  while(!Q[cur].empty()) {
    int t = Q[cur].front(); Q[cur].pop();
    cnt++;
    for(int c : chd[t]) Q[1-cur].push(c);
    if(Q[cur].empty()) {
      if(cnt > ans) ans = cnt, lv = dep;
      cur = 1 - cur, cnt = 0, dep++;
    }
  }
  printf("%d %d\n", ans, lv);
  return 0;
}
