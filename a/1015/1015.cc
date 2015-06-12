#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool is_prime(int x) {
  if(x < 2) return false;
  int sq = (int)sqrt(x);
  for(int i=2; i<=sq; i++) if(!(x % i)) return false;
  return true;
}
int revr(int x, int r) {
  int ans = 0;
  while(x) ans = ans * r + x % r, x /= r;
  return ans;
}

int main(int argc, const char *argv[])
{
  int N, D;
  while(scanf("%d%d", &N, &D) == 2) is_prime(N) && is_prime(revr(N, D)) ? puts("Yes") : puts("No");
  return 0;
}
