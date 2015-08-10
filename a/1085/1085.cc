#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, P, ans;
long a[100000];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &P);
  for(int i=0; i<N; i++) scanf("%ld", a + i);
  sort(a, a + N);
  int ans = 0, tail = 0;
  for(int i=0; i<N; i++) {
    for(; tail<N && a[tail] <= P * a[i]; tail++);
    ans = max(ans, (--tail) - i + 1);
  }
  printf("%d\n", ans);
  return 0;
}
