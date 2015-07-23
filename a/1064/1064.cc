// #include <bits/stdc++.h>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, a[1000], ans[1001], tot;
/* ugly */
// vector<int> lv[11];
// void dfs(int s, int e, int l) {
//   if(s > e) return;
//   else {
//     int n = e - s + 1, i = 1;
//     for(; !((1<<i)-1 <= n && (1<<(i+1))-1 > n); i++);
//     int left = (1<<(i-1)) - 1, rest = n - (1<<i) + 1, half = 1 << (i-1);
//     left += min(half, rest);
//     lv[l-1].push_back(a[s + left]);
//     dfs(s, s + left - 1, l + 1);
//     dfs(s + left + 1, e, l + 1);
//   }
// }
void dfs(int i, int n) {
  if(i > n) return;
  int l = 2*i, r = 2*i + 1;
  dfs(l, n);
  ans[i] = a[tot++];
  dfs(r, n);
}
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &a[i]);
  sort(a, a + N);
  dfs(1, N);
  for(int i=1; i<N; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[N]);
  return 0;
}
