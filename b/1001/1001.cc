#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int n, ans = 0;
  scanf("%d", &n);
  while(n != 1) {
    if(n&1) n = (3*n+1) >> 1;
    else n >>= 1;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
