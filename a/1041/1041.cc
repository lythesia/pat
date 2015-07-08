#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, n[10001], in[10001];
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  int x, cnt = 0;
  while(N--) {
    scanf("%d", &x);
    if(!n[x]) in[cnt++] = x;
    n[x]++;
  }
  int ans = 0;
  for(; ans<10001; ans++) if(n[in[ans]] == 1) break;
  ans != 10001 ? printf("%d\n", in[ans]) : puts("None");
  return 0;
}
