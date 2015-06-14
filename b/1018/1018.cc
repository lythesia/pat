#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int rule[1<<8], iorder[1<<8];
char corder[] = "BCJ";
int main(int argc, const char *argv[])
{
  rule[(int)'B'] = 0, rule[(int)'J'] = 1, rule[(int)'C'] = 2;
  iorder[(int)'B'] = 0, iorder[(int)'J'] = 2, iorder[(int)'C'] = 1;
  int n, aw = 0, at = 0, ac[3] = {0}, bc[3] = {0};
  scanf("%d", &n);
  char a, b;
  for(int i=0; i<n; i++) {
    getchar();
    scanf("%c %c", &a, &b);
    if(a == b) at++;
    else {
      int ia = a, ib = b;
      if(rule[ia] == ((rule[ib] + 1) % 3)) aw++, ac[iorder[ia]]++;
      else bc[iorder[ib]]++;
    }
  }
  printf("%d %d %d\n%d %d %d\n%c %c\n", aw, at, n - aw - at, n - aw - at, at, aw,
      corder[max_element(ac, ac+3) - ac], corder[max_element(bc, bc+3) - bc]);
  return 0;
}
