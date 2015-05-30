#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M;
vi node[101]; // assum node from 01 02 .. n

int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &M);
  for(int i=0; i<M; i++) {
    int n, k;
    scanf("%d%d", &n, &k);
    while(k--) {
      int c;
      scanf("%d", &c);
      node[n].push_back(c);
    }
  }
  vi ans;
  queue<int> Q[2];
  int cnt = 0, cur = 0;
  Q[cur].push(1);
  while(!Q[cur].empty()) {
    int t = Q[cur].front(); Q[cur].pop();
    if(node[t].empty()) cnt++;
    else for(int c : node[t]) Q[1-cur].push(c);
    if(Q[cur].empty()) {
      ans.push_back(cnt);
      cnt = 0;
      cur = 1 - cur;
    }
  }
  for(size_t i=0; i<ans.size()-1; i++) printf("%d ", ans[i]);
  printf("%d\n", ans.back());
  return 0;
}
