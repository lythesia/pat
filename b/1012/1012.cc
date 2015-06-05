#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int N, x;
  int a[] = {0,0,0,0,0}, a2 = 1, a4 = 0;
  bool f2 = false;
  scanf("%d", &N);
  while(N--) {
    scanf("%d", &x);
    if(!(x % 10)) a[0] += x;
    if(x % 5 == 1) a[1] += a2 * x, a2 *= -1, f2 = true;
    if(x % 5 == 2) a[2]++;
    if(x % 5 == 3) a[3] += x, a4++;
    if(x % 5 == 4) a[4] = max(a[4], x);
  }
  a[0] ? printf("%d ", a[0]) : printf("N ");
  f2   ? printf("%d ", a[1]) : printf("N ");
  a[2] ? printf("%d ", a[2]) : printf("N ");
  a[3] ? printf("%.1lf ", a[3]*1.0/a4) : printf("N ");
  a[4] ? printf("%d\n", a[4]) : puts("N");
  return 0;
}
