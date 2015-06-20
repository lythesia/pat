#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, a[100001];
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  int maxn = 0;
  for(int i=0; i<N; i++) {
    int n, x;
    scanf("%d%d", &n, &x);
    a[n] += x, maxn = max(maxn, n);
  }
  auto ans = max_element(a + 1, a + maxn + 1);
  printf("%zu %d\n", ans - a, *ans);
  return 0;
}
