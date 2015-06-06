#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

typedef pair<int, int> pii;

const int SLIM = 60*(17 - 8);
int N, M, K, Q;
int w[21], ans[1001];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(int argc, const char *argv[])
{
  scanf("%d%d%d%d", &N, &M, &K, &Q);
  int c, cap = N * M;
  for(int i=0; i<K; i++) {
    scanf("%d", &c);
    if(i < cap) {
      int p = i % N, s = w[p]; // start serve time
      w[p] += c, ans[i] = (s < SLIM ? w[p] : -1);
      q.push(pii{w[p], p});
    }
    else {
      pii t = q.top(); q.pop();
      int s = w[t.second];
      w[t.second] += c, ans[i] = (s < SLIM ? w[t.second] : -1), t.first = w[t.second];
      q.push(t);
    }
  }
  while(Q--) {
    scanf("%d", &c);
    if(ans[c-1] < 0) puts("Sorry");
    else printf("%02d:%02d\n", ans[c-1] / 60 + 8, ans[c-1] % 60);
  }
  return 0;
}
