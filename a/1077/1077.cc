#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
char buf[100][257];
char *p[100];
int main(int argc, const char *argv[])
{
  scanf("%d", &N); getchar();
  int mmin = 256, len;
  for(int i=0; i<N; i++) gets(buf[i]), len = strlen(buf[i]), mmin = min(mmin, len), p[i] = buf[i] + len - 1;
  char *s = NULL;
  bool f = false;
  while(mmin--) {
    char *q = p[0]--;
    for(int i=1; i<N; i++) if(*p[i]-- != *q) { f = true; break; }
    if(!f) s = q;
    else break;
  }
  s ? puts(s) : puts("nai");
  return 0;
}
