#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

char a[1001], q[1001];
int b;
int main(int argc, const char *argv[])
{
  scanf("%s %d", a, &b);
  assert(a[0] != 0);
  int n = strlen(a), r = 0, cnt = 0;
  for(int i=0; i<n; i++) {
    r = r * 10 + a[i] - '0';
    if(r < b) { if(cnt) q[cnt++] = 0; }
    else q[cnt++] = r / b, r %= b;
  }
  for(int i=0; i<cnt; i++) printf("%d", q[i]);
  printf("%s %d\n", cnt ? "":"0", r);
  return 0;
}
