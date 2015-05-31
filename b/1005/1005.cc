#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int n[101];
int h[101];

int main(int argc, const char *argv[])
{
  int k;
  vector<int> ans;
  scanf("%d", &k);
  for(int i=1; i<=k; i++) scanf("%d", &n[i]), h[n[i]] = i;
  for(int i=1; i<=k; i++) {
    if(h[n[i]]) {
      int x = n[i];
      while(x != 1) {
        x = (x&1) ? (3*x+1)/2 : x/2;
        if(x>1 && x<=100) h[x] = 0;
      }
    }
  }
  for(int i=1; i<=k; i++) if(h[n[i]]) ans.push_back(n[i]);
  sort(ans.begin(), ans.end());
  for(size_t i=ans.size()-1; i; i--) printf("%d ", ans[i]);
  printf("%d\n", ans.front());
  return 0;
}
