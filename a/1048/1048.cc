#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M;
bool h[501];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &M);
  int ans = M;
  while(N--) {
    int c;
    scanf("%d", &c);
    if(c < M && c <= 500 && M - c < 500) {
      if(h[M - c]) ans = min(ans, min(c, M - c));
      else h[c] = true;
    }
  }
  ans == M ? puts("No Solution") : printf("%d %d\n", ans, M - ans);
  return 0;
}
