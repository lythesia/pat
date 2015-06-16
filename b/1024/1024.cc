#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

char a[10000]; // case 6 len > 9999 ? assert failed..
int main(int argc, const char *argv[])
{
  scanf("%s", a);
  char *s = a;
  if(*s++ == '-') putchar('-');
  char *e = strstr(a, "E") + 1;
  int exp = atoi(e);
  if(exp < 0) {
    exp = -exp, printf("0."), exp--;
    while(exp--) putchar('0'); // exp == -1
  }
  printf("%c", *s), s += 2; // int portion
  if(exp == 0) putchar('.');
  for(; s!=e-1; s++) {
    printf("%c", *s), exp--;
    if(!exp && s!=e-2) putchar('.'); // exp is not enough and not point at end
  }
  if(exp > 0) while(exp--) putchar('0');
  puts("");
  return 0;
}
