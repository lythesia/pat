#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int MULT = 17;
const int NHASH = 1299817;
int N;
char s[1048577], ans[1048577];
unordered_map<int, pair<int,int>> h;

int mul(long x, long y) { return x * y % NHASH; }

int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  getchar();
  gets(s);
  int k = 0, n = strlen(s), m = 1;
  for(int i=0; i<N; i++) {
    k = mul(k, MULT) + (unsigned)s[i];
    if(k >= NHASH) k -= NHASH;
    if(i) m = mul(m, MULT);
  }
  h.insert(make_pair(k, make_pair(0, 1)));
  int mmax = 1;
  for(int i=1; i+N<=n; i++) {
    k -= mul((unsigned)s[i-1], m);
    if(k < 0) k += NHASH;
    k = mul(k, MULT) + (unsigned)s[i + N - 1];
    if(k >= NHASH) k -= NHASH;
    if(h.count(k)) mmax = max(mmax, ++h[k].second);
    else h.insert(make_pair(k, make_pair(i, 1)));
  }
  for(auto p : h) {
    auto &pp = p.second;
    if(pp.second == mmax && (!ans[0] || strncmp(s + pp.first, ans, N) > 0)) strncpy(ans, s + pp.first, N);
  }
  printf("%s %d\n", ans, mmax);
  return 0;
}
