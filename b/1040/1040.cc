#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1000000007;
int main(int argc, const char *argv[])
{
  int at = 0, t = 0, pat = 0;
  char s[100001] = {0};
  gets(s);
  for(char *p=strrchr(s, 'T'); p>=s; p--) {
    if(*p == 'T') t++;
    else if(*p == 'A') at = (at + t) % mod;
    else pat = (pat + at) % mod;
  }
  printf("%d\n", pat);
  return 0;
}
