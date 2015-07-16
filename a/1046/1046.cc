#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M;
int a[200010], s[200010];
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=1; i<=N; i++) {
    scanf("%d", &a[i]);
    a[i + N] = a[i];
  }
  // cal prefix sum first to avoid TLE
  for(int i=1; i<= N*2; i++) s[i] = s[i-1] + a[i]; // s[i]: 1 -- i+1
  scanf("%d", &M);
  while(M--) {
    int e1, e2;
    scanf("%d%d", &e1, &e2);
    if(--e1 > --e2) swap(e1, e2);
    printf("%d\n", min(s[e2] - s[e1], s[e1 + N] - s[e2]));
  }
  return 0;
}
