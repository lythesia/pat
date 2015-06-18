#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
char c;
#if 0
#define f(x) (2*(x)*(x) + 4*(x) + 1)
int main(int argc, const char *argv[])
{
  scanf("%d %c", &N, &c);
  int n = 0;
  generate_n(x, 23, [&n]() {return n++;});
  int lv = *upper_bound(x, x + 23, N, [](int val, int x){return val < f(x);}) - 1, r = N - f(lv); // there's simpler sol...
  assert(r >= 0);
  for(int i=lv; abs(i)<=lv; i--) {
    int sp = lv - abs(i), st = 2 * abs(i) + 1;
    for(int j=0; j<sp; j++) putchar(' ');
    for(int j=0; j<st; j++) putchar(c);
    // no need for rest spaces ..
    puts("");
  }
  printf("%d\n", r);
  return 0;
}
#endif
int main(int argc, const char *argv[])
{
  scanf("%d %c", &N, &c);
  int n = (int)sqrt((N + 1) / 2), r = N - 2*n*n + 1;
  assert(r >= 0);
  for(int i=--n; abs(i)<=n; i--) {
    int sp = n - abs(i), st = 2 * abs(i) + 1;
    while(sp--) putchar(' ');
    while(st--) putchar(c);
    puts("");
  }
  printf("%d\n", r);
  return 0;
}
