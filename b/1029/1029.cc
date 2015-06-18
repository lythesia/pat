#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

char s1[81], s2[81];
bool tab[96];
int ans[37];
int main(int argc, const char *argv[])
{
  gets(s1), gets(s2);
  int cnt = 0;
  char *p1 = s1, *p2 = s2, *p;
  for(; *p2; p1++, p2++) {
    p = strchr(p1, *p2);
    assert(p != NULL);
    while(p1 != p) {
      int c = toupper(*p1++);
      if(!tab[c]) ans[cnt++] = c, tab[c] = true;
    }
  }
  while(*p1) {
    int c = toupper(*p1++);
    if(!tab[c]) ans[cnt++] = c, tab[c] = true;
  }
  for(int i=0; i<cnt; i++) putchar(ans[i]);
  puts("");
  return 0;
}
