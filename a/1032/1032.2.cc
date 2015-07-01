#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int nxt[100000];
bool v[100000];
int main(int argc, const char *argv[])
{
  int h1, h2, N, a, n, ans;
  char d;
  scanf("%d%d%d", &h1, &h2, &N);
  while(N--) scanf("%d %c %d", &a, &d, &n), nxt[a] = n;
  for(ans = h1; ans != -1; ans = nxt[ans]) v[ans] = true;
  for(ans = h2; ans != -1 && !v[ans]; ans = nxt[ans]) v[ans] = true;
  ans == -1 ? puts("-1") : printf("%05d\n", ans);
  return 0;
}
