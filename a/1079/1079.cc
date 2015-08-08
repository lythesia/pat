#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
double P, r, ans = 0.0;
struct sup {
  vi chd;
  int stk = 0;
};
sup s[100000];
void dfs(int root, double rate) {
  if(s[root].chd.empty()) ans += P * rate * s[root].stk;
  else for(int ch : s[root].chd) dfs(ch, rate * r);
}
int main(int argc, const char *argv[])
{
  scanf("%d%lf%lf", &N, &P, &r), r = 1.0 + r / 100.0;
  for(int i=0; i<N; i++) {
    int k, x;
    scanf("%d", &k);
    if(k) {
      while(k--) {
        scanf("%d", &x);
        s[i].chd.push_back(x);
      }
    }
    else scanf("%d", &s[i].stk);
  }
  dfs(0, 1.0);
  printf("%.1lf\n", ans);
  return 0;
}
