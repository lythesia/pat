#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const double eps = 1e-7;
struct cake {
  double s = 0.0, w = 0.0, p = 0.0; // <- point: double on stoke and total worth
};
int N, D;
cake c[1001];

int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &D);
  for(int i=0; i<N; i++) scanf("%lf", &c[i].s);
  for(int i=0; i<N; i++) scanf("%lf", &c[i].w), c[i].p = c[i].w / c[i].s;
  sort(c, c + N, [](const cake &x, const cake &y){ return x.p > y.p; });
  double ans = 0.0, tot = D;
  for(int i=0; i<N && abs(tot) > eps; i++) {
    if(c[i].s > D) ans += D * c[i].p, D = 0;
    else ans += c[i].w, D -= c[i].s;
  }
  printf("%.2lf\n", ans);
  return 0;
}
