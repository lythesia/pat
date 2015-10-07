#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int,int> pii;

struct prj {
  int p, l, d;
};
int N, D;
prj P[50];

int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d%d%d", &P[i].p, &P[i].l, &P[i].d), D = max(D, P[i].d);
  sort(P, P + N, [](const prj &p1, const prj &p2){return p1.d < p2.d;});

  /* this version is ugly */
  // vector<pii> dp(D + 1); // <profit, -days>
  // for(int i=0; i<N; i++) {
  //   for(int j=D; j>=P[i].l; j--) {
  //     auto p = dp[j - P[i].l], q = dp[P[i].d - P[i].l];
  //     if(-p.second + P[i].l <= P[i].d) dp[j] = max(dp[j], pii(p.first + P[i].p, p.second - P[i].l));
  //     else dp[j] = max(dp[j], pii(q.first + P[i].p, q.second - P[i].l));
  //   }
  // }
  // printf("%d\n", dp[D].first);

  /* this version is clear */
  vi dp(D + 1);
  for(int i=0; i<N; i++) {
    for(int j=D; j>=P[i].l; j--) {
      int t = min(j, P[i].d) - P[i].l;
      if(t >= 0) dp[j] = max(dp[j], dp[t] + P[i].p);
    }
  }
  printf("%d\n", dp[D]);
  return 0;
}
