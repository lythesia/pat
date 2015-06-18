#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, p, ans = 1;
long a[100001];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &p);
  for(int i=0; i<N; i++) scanf("%ld", &a[i]);
  sort(a, a + N);
  for(int i=0; i<N; i++) { // fix l and bsearch
    if(N - i <= ans) break;
    else ans = max(ans, (int)(upper_bound(a + i, a + N, a[i] * p) - a - i));
  }
  printf("%d\n", ans);
  return 0;
}
