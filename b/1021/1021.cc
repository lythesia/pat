#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int ans[10];
int main(int argc, const char *argv[])
{
  char n[1001] = {0};
  scanf("%s", n);
  for(char *p = n; *p; p++) ans[*p-'0']++;
  for(int i=0; i<10; i++) if(ans[i]) printf("%d:%d\n", i, ans[i]);
  return 0;
}
