#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, a[101], K;
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  int x, cnt = 0;
  while(N--) {
    scanf("%d", &x);
    a[x]++;
  }
  scanf("%d", &K);
  while(K--) {
    scanf("%d", &x);
    printf("%s%d", cnt++ ? " ":"", a[x]);
  }
  puts("");
  return 0;
}
