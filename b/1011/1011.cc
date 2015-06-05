#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int T, cas = 0;
  long a, b, c;
  scanf("%d", &T);
  while(T--) {
    scanf("%ld%ld%ld", &a, &b, &c);
    printf("Case #%d: %s\n", ++cas, a+b>c ? "true" : "false");
  }
  return 0;
}
