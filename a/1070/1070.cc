#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
double D;
struct cake {
  double a, p, w;
};
cake c[1000];
int main(int argc, const char *argv[])
{
  scanf("%d%lf", &N, &D);
  for(int i=0; i<N; i++) scanf("%lf", &c[i].a);
  for(int i=0; i<N; i++) scanf("%lf", &c[i].p), c[i].w = c[i].p / c[i].a;
  sort(c, c + N, [](const cake &x, const cake &y){return x.w > y.w;});
  double ans = 0.0;
  for(int i=0; i<N; i++) {
    if(D >= c[i].a) ans += c[i].p, D -= c[i].a;
    else {
      ans += D * c[i].w;
      break;
    }
  }
  printf("%.2lf\n", ans);
  return 0;
}
