#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int M, N;
int main(int argc, const char *argv[])
{
  int c, cnt = 0, prev = -1, tot = 0;
  scanf("%d%d", &M, &N), tot = M*N;
  while(tot--) scanf("%d", &c), (!cnt || c == prev) ? (cnt++, prev = c) : cnt--;
  printf("%d\n", prev);
  return 0;
}
