#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int T;
long long A, B, C;
int main(int argc, const char *argv[])
{
  scanf("%d", &T);
  for(int i=1; i<=T; i++) {
    scanf("%lld%lld%lld", &A, &B, &C);
    long long t = A + B;
    int inf = 0;
    if(A > 0 && B > 0 && t <= 0) inf = 1;
    else if(A < 0 && B < 0 && t >= 0) inf = -1;
    printf("Case #%d: %s\n", i, (inf > 0 || (!inf && t > C)) ? "true" : "false");
  }
  return 0;
}
