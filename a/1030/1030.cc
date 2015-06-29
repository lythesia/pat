#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M, S, D;
int d[500], c[500], p[500];
bool v[500];
struct edge {
  int n, dd, cc;
};
vector<edge> e[500];

void spfa() {
  memset(d, 0x3f, sizeof(d));
  for(int i=0; i<N; i++) p[i] = i;

  d[S] = c[S] = 0;
  queue<int> Q;
  Q.push(S);
  v[S] = true;
  while(!Q.empty()) {
    int x = Q.front(); Q.pop();
    v[x] = false; // pop -> false
    for(auto &y : e[x]) {
      if((d[y.n] > d[x] + y.dd) ||
         (d[y.n] == d[x] + y.dd && c[y.n] > c[x] + y.cc)) {
        d[y.n] = d[x] + y.dd, c[y.n] = c[x] + y.cc, p[y.n] = x;
        if(!v[y.n]) {
          Q.push(y.n);
          v[y.n] = true; // push -> true
        }
      }
    }
  }
}

int main(int argc, const char *argv[])
{
  scanf("%d%d%d%d", &N, &M, &S, &D);
  while(M--) {
    int c1, c2, dd, cc;
    scanf("%d%d%d%d", &c1, &c2, &dd, &cc);
    e[c1].emplace_back(edge{c2, dd, cc});
    e[c2].emplace_back(edge{c1, dd, cc});
  }
  spfa();
  stack<int> path;
  int x = D;
  while(x != p[x]) {
    path.push(x);
    x = p[x];
  }
  path.push(S);
  while(!path.empty()) {
    printf("%d ", path.top());
    path.pop();
  }
  printf("%d %d\n", d[D], c[D]);
  return 0;
}
