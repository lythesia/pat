#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  char s[1001] = {0};
  gets(s);
  int n = strlen(s), p[2002] = {0};
  for(int i=0, id=0, mx=0; i<=2*(n-1); i++) {
    int d = i < mx ? min(p[2*id-i], (mx-i)/2) : 0;
    int a = i / 2 - d, b = (i + 1) / 2 + d;
    while(0<=a && b<n && s[a]==s[b]) --a, ++b, ++d;
    p[i] = d;
    if(mx < 2*b-1) mx = 2 * b - 1, id = i;
  }
  int ans = 0, curr = 0;
  for(int i=0; i<=2*(n-1); i++) {
    if(i & 1) curr = p[i] * 2;
    else curr = p[i] * 2 - 1;
    ans = max(ans, curr);
  }
  printf("%d\n", ans);
  return 0;
}
