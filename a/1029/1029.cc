#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M;
long s[1000005 * 2];
int main(int argc, const char *argv[])
{
  int tot = 0;
  scanf("%d", &N);
  for(; tot<N; tot++) scanf("%ld", &s[tot]);
  scanf("%d", &M);
  for(; tot<N+M; tot++) scanf("%ld", &s[tot]);
  int k = (N + M - 1) / 2;
  nth_element(s, s + k, s + M + N);
  printf("%ld\n", s[k]);
  return 0;
}

#if 0
// or bin-search
long find_kth(long a[], int m, long b[], int n, int k)
{
    if(m > n) return find_kth(b, n, a, m, k);
    if(m == 0) return b[k - 1];
    if(k == 1) return min(a[0], b[0]);
    int pa = min(k / 2, m), pb = k - pa;
    if(a[pa - 1] == b[pb - 1]) return a[pa - 1];
    else if(a[pa - 1] < b[pb - 1]) return find_kth(a + pa, m - pa, b, n, k - pa);
    else return find_kth(a, m, b + pb, n - pb, k - pb);
}

find_kth(S1, N1, S2, N2, (N1 + N2 + 1) / 2);
#endif
