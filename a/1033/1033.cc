#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct stop {
  double p = 0.0, d = 0.0;
};
bool operator < (const stop &x, const stop &y) {
  return x.d < y.d;
}
stop s[500];
double C, D, V;
int N;
int main(int argc, const char *argv[])
{
  scanf("%lf%lf%lf%d", &C, &D, &V, &N);
  for(int i=0; i<N; i++) scanf("%lf%lf", &s[i].p, &s[i].d);
  s[N].d = D;
  sort(s, s + N + 1);
  double c = 0.0, d = 0.0, ans = 0.0;
  bool reach = true;
  for(int i=0; i<=N; i++) {
    bool no_fill = false, fill_next = false;
    if(s[i].d - d > c * V) {
      reach = false;
      printf("The maximum travel distance = %.2lf\n", d + c * V);
      break;
    }
    if(i) c -= (s[i].d - s[i-1].d) / V;
    d = s[i].d;
    // not fill
    for(int j=i+1; j<=N && s[j].d-d<=c*V; j++) {
      if(s[j].p < s[i].p) {
        no_fill = true;
        break;
      }
    }
    if(no_fill) continue;
    // fill to get to next
    for(int j=i+1; j<=N && s[j].d-d<=C*V; j++) {
      if(s[j].p < s[i].p) {
        ans += ((s[j].d - d) / V - c) * s[i].p, c = (s[j].d - d) / V;
        fill_next = true;
        break;
      }
    }
    if(fill_next) continue;
    // fill to full
    ans += (C - c) * s[i].p, c = C;
  }
  if(reach) printf("%.2lf\n", ans);
  return 0;
}
