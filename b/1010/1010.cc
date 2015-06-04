#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vp;

int main(int argc, const char *argv[])
{
  int coe, exp, cnt = 0;
  while(scanf("%d%d", &coe, &exp) != EOF) if(exp) printf("%s%d %d", cnt++? " ":"", coe*exp, exp-1);
  if(!cnt) puts("0 0"); // <- zero poly is indicated here
  return 0;
} 
