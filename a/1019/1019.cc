#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool is_pali(vi &v) {
  reverse(v.begin(), v.end());
  for(int i=0, j=v.size()-1; i<j; i++, j--) if(v[i] != v[j]) return false;
  return true;
}

int main(int argc, const char *argv[])
{
  int n, b;
  scanf("%d%d", &n, &b);
  vi ans;
  while(n) {
    ans.push_back(n % b);
    n /= b;
  }
  if(ans.empty()) ans.push_back(0);
  is_pali(ans) ? puts("Yes") : puts("No");
  for(size_t i=0; i<ans.size()-1; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[ans.size()-1]);
  return 0;
}
