#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  vi ans = {N}, fact;
  int sq = sqrt(N);
  for(int i=2; i<=sq; i++) {
    fact.clear();
    int n = N;
    for(int j=i; j<=n; j++) {
      if(!(n % j)) fact.push_back(j), n /= j;
      else break;
    }
    if(fact.size() > ans.size() || (fact.size() == ans.size() && fact[0] < ans[0])) ans = fact;
  }
  printf("%zu\n", ans.size());
  for(size_t i=0; i<ans.size(); i++) printf("%s%d", i ? "*":"", ans[i]);
  puts("");
  return 0;
}
