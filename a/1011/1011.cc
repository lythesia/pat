#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const char r[] = "WTL";
int main(int argc, const char *argv[])
{
  int games = 3;
  double a[3], ans = 1.0;
  while(games--) {
    scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);
    auto it = max_element(a, a+3);
    ans *= *it; 
    printf("%c ", r[it-a]);
  }
  ans = (ans*0.65-1)*2;
  printf("%.2lf\n", ans);
  return 0;
}
