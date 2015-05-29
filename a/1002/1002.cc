#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int K, exp, line = 2;
  double N[1001] = {0.0}, coe;
  set<int> t;
  while(line--) {
    scanf("%d", &K);
    while(K--) {
      scanf("%d%lf", &exp, &coe);
      if((N[exp] += coe) == 0.0) t.erase(exp); // not output term with 0.0 coe!
      else t.insert(exp);
    }
  }
  printf("%zu", t.size());
  for(auto it=t.rbegin(); it!=t.rend(); it++) printf(" %d %.1lf", *it, N[*it]);
  puts("");
  return 0;
}
