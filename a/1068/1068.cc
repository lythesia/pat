#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M, a[10001];
int dp[10001][101];
bool path[10001][101];

int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &M);
  for(int i=1; i<=N; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + N, greater<int>()); // why desc? since we intend to pick smaller coin, if we use asc, in that case not to pick a larger coin **does not** mean we select smaller seq(as 1 3 4 vs. 2 4 6)
  for(int i=1; i<=N; i++) {
    for(int j=a[i]; j<=M; j++) {
      if(dp[i-1][j] <= dp[i-1][j-a[i]] + a[i]) dp[i][j] = dp[i-1][j-a[i]] + a[i], path[i][j] = true; // pick smaller coin
      else dp[i][j] = dp[i-1][j], path[i][j] = false; // rather than not pick
     }
  }
  if(dp[N][M] != M) puts("No Solution");
  else {
    int c = N;
    while(M) {
      if(path[c][M]) M -= a[c], printf("%d%s", a[c], M ? " ":"");
      c--;
    }
    puts("");
  }
  return 0;
}
