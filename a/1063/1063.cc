#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

// using set<int> will TLE
int N, M[51], K, a, b;
int n[51][10000];
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=1; i<=N; i++) {
    scanf("%d", &M[i]);
    for(int j=0; j<M[i]; j++) scanf("%d", &n[i][j]);
  }
  scanf("%d", &K);
  while(K--) {
    scanf("%d%d", &a, &b);
    int in = 0, un = 0;
    sort(n[a], n[a] + M[a]);
    sort(n[b], n[b] + M[b]);
    auto fa = n[a], la = unique(n[a], n[a] + M[a]), fb = n[b], lb = unique(n[b], n[b] + M[b]);
    while(true) {
      if(fa == la) {
        un += distance(fb, lb);
        break;
      }
      if(fb == lb) {
        un += distance(fa, la);
        break;
      }
      if(*fa < *fb) un++, fa++;
      else if(*fb < *fa) un++, fb++;
      else in++, un++, fa++, fb++;
    }
    printf("%.1lf%%\n", 100.0 * in / un);
  }
  return 0;
}
