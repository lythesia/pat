#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int K, exp, mexp = 0;
  double a[2001] = {0.0}, c[2001] = {0.0}, coe;
  set<int> t;
  scanf("%d", &K);
  while(K--) scanf("%d", &exp), scanf("%lf", &a[exp]), mexp = max(mexp, exp);
  scanf("%d", &K);
  while(K--) {
    scanf("%d%lf", &exp, &coe);
    for(int i=0; i<=mexp; i++) {
      if((c[i+exp]+=a[i]*coe) == 0.0) t.erase(i+exp);
      else t.insert(i+exp);
    }
  }
  printf("%zu", t.size());
  for(auto it=t.rbegin(); it!=t.rend(); it++) printf(" %d %.1lf", *it, c[*it]);
  puts("");
  return 0;
}
