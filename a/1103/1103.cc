#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

// case 5: 400 50 2
int N, K, P;
vi fact;
int mmax;

int powx(int b, int e) {
  int ans = 1;
  while(e) {
    if(e & 1) ans *= b, e--;
    else b *= b, e >>= 1;
  }
  return ans;
}

void dfs(int n, int k, vi &ans) {
  if(k == K) {
    if(!n) {
      int sum = accumulate(ans.begin(), ans.end(), 0);
      if(sum >= mmax) fact = ans, mmax = sum;
    }
  }
  else {
    int hi = sqrt(n), lo = k ? ans[k - 1] : 1;
    for(int i=lo; i<=hi; i++) {
      int t = powx(i, P);
      if(n >= t) { // why not set hi early?
        ans[k] = i;
        dfs(n - t, k + 1, ans);
      }
      else return;
    }
  }
}

int main(int argc, const char *argv[])
{
  scanf("%d%d%d", &N, &K, &P);
  vi v(K);
  dfs(N, 0, v);
  reverse(fact.begin(), fact.end());
  if(fact.size() == (size_t)K) {
    printf("%d = ", N);
    for(int i=0; i<K; i++) printf("%s%d^%d", i ? " + ":"", fact[i], P);
    puts("");
  }
  else puts("Impossible");
  return 0;
}
