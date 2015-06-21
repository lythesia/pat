#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int a[128];
int main(int argc, const char *argv[])
{
  int yes = 0, no = 0;
  char s[1001] = {0};
  gets(s);
  for(char *p=s; *p; p++) a[(int)*p]++, yes++;
  gets(s);
  for(char *p=s; *p; p++) {
    int t = *p;
    if(a[t]) a[t]--, yes--;
    else no++;
  }
  if(no) printf("No %d\n", no);
  else printf("Yes %d\n", yes);
  return 0;
}
