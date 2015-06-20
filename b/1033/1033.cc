#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool broke[96];
int main(int argc, const char *argv[])
{
  char s[100001] = {0};
  gets(s);
  for(char *p = s; *p; p++) broke[tolower(*p)] = true; // default lower
  gets(s);
  for(char *p = s; *p; p++) {
    if(broke[tolower(*p)] || (isupper(*p) && broke[(int)'+'])) continue;
    putchar(*p);
  }
  puts("");
  return 0;
}
