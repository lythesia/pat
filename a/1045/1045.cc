#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M, f[201], L, a[10001];
int dp[10001][201];
// TLE
// void dfs(int p, int c, int len) {
//   if(p == L || c == M) return;
//   if(a[p] == f[c]) {
//     ans = max(ans, len + 1);
//     dfs(p + 1, c, len + 1); // still current color
//     dfs(p + 1, c + 1, len + 1); // next color
//   }
//   else {
//     dfs(p + 1, c, len); // find color ahead
//     dfs(p, c + 1, len); // switch next color
//   }
// }
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  scanf("%d", &M);
  for(int i=1; i<=M; i++) scanf("%d", &f[i]);
  scanf("%d", &L);
  for(int i=1; i<=L; i++) scanf("%d", &a[i]);
  for(int i=1; i<=L; i++) for(int j=1; j<=M; j++)
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + (a[i] == f[j]);
  printf("%d\n", dp[L][M]);
  return 0;
}
