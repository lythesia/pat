#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

char s1[10001], s2[10001];
bool h[128];
int main(int argc, const char *argv[])
{
  gets(s1); gets(s2);
  for(char *p=s2; *p; p++) h[(int)*p] = true;
  for(char *p=s1; *p; p++) if(!h[(int)*p]) putchar(*p);
  puts("");
  return 0;
}
