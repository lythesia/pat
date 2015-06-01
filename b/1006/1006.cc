#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int n;
  scanf("%d", &n);
  int b = n / 100, s = (n-100*b) / 10, g = n % 10;
  while(b--) putchar('B');
  while(s--) putchar('S');
  for(int i=1; i<=g; i++) printf("%d", i);
  puts("");
  return 0;
}
