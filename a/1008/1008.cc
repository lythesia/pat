#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int N, f, ans = 0, prev = 0;
  scanf("%d", &N);
  while(N--) scanf("%d", &f), ans += (f > prev ? 6*(f-prev) : 4*(prev-f)) + 5, prev = f;
  printf("%d\n", ans);
  return 0;
}
