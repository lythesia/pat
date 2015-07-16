#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  int ans = 0;
  for(long i=1; i<=N; i*=10) ans += (N/i + 8) / 10 * i + (N/i % 10 == 1) * (N%i + 1);
  printf("%d\n", ans);
  return 0;
}
