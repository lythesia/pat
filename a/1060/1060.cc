#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
char f[2][205], ans[2][205];
void sig(int i, char *s) {
  for(int c=0; c<N; c++) {
    if(*s == '.') s++;
    ans[i][c] = *s ? *s : '0';
    s++;
  }
}
int main(int argc, const char *argv[])
{
  scanf("%d %s %s", &N, f[0], f[1]);
  int exp[2] = {0};
  char *s = NULL;
  for(int i=0; i<2; i++) {
    if((s = strchr(f[i], '.'))) {
      *s = 0;
      int ip = atoi(f[i]);
      *s = '.';
      if(ip) { // xx.xxx
        char *p = f[i];
        while(*p == '0') p++;
        exp[i] = s - p;
        sig(i, p);
      }
      else { // 0*.xxx
        char *p = s + 1;
        if(atoi(p)) {
          while(*p == '0') p++, exp[i]--;
          sig(i, p);
        }
        else sig(i, p);
      }
    }
    else { // xxxx
      char *p = f[i];
      while(*p == '0') p++;
      exp[i] = strlen(p);
      sig(i, p);
    }
  }
  if(!strcmp(ans[0], ans[1]) && exp[0] == exp[1]) {
    printf("YES");
    printf(" 0.%s*10^%d\n", ans[0], exp[0]);
  }
  else {
    printf("NO");
    for(int i=0; i<2; i++) printf(" 0.%s*10^%d", ans[i], exp[i]);
    puts("");
  }
  return 0;
}
