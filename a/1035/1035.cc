#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct acc {
  char name[11] = {0}, pass[11] = {0};
  bool mod = false;
};
int N;
acc a[1000];
int main(int argc, const char *argv[])
{
  int m = 0;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%s %s", a[i].name, a[i].pass);
    for(char *p=a[i].pass; *p; p++) {
      char ch = *p;
      *p = ch == '1' ? '@' :
           ch == '0' ? '%' :
           ch == 'l' ? 'L' :
           ch == 'O' ? 'o' : ch;
      a[i].mod = a[i].mod || (ch != *p);
    }
    if(a[i].mod) m++;
  }
  if(m) {
    printf("%d\n", m);
    for(int i=0; i<N; i++) if(a[i].mod) printf("%s %s\n", a[i].name, a[i].pass);
  }
  else {
    if(N == 1) puts("There is 1 account and no account is modified");
    else printf("There are %d accounts and no account is modified\n", N);
  }
  return 0;
}
