#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  char s[81] = {0};
  gets(s);
  int n = strlen(s), v = (n + 2) / 3, h = n + 2 - v * 2;
  assert(v <= h);
  for(int i=0; i<v-1; i++) printf("%c%*c\n", s[i], h - 1, s[n - 1 - i]);
  for(int i=v-1; i<=n-v; i++) putchar(s[i]);
  puts("");
  return 0;
}
