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
  char c;
  scanf("%d %c", &n, &c);
  for(int i=0; i<n; i++) putchar(c); puts("");
  for(int i=0; i<(int)round(n / 2.0)-2; i++) printf("%c%*c\n", c, n - 1, c);
  for(int i=0; i<n; i++) putchar(c); puts("");
  return 0;
}
