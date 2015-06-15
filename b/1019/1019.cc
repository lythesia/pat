#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

vi to_a(int x) {
  vi ans(4, 0);
  int i = 0;
  while(x) {
    ans[i++] = x % 10;
    x /= 10;
  }
  return ans;
}
int dsc(vi &a) {
  sort(a.begin(), a.end(), greater<int>());
  return accumulate(a.begin(), a.end(), 0, [](int acc, int x){return acc * 10 + x;});
}
int asc(vi &a) {
  sort(a.begin(), a.end());
  return accumulate(a.begin(), a.end(), 0, [](int acc, int x){return acc * 10 + x;});
}
int main(int argc, const char *argv[])
{
  int n;
  scanf("%d", &n);
  do {
    vi arr = to_a(n);
    int a = dsc(arr), b = asc(arr);
    n = a - b, printf("%04d - %04d = %04d\n", a, b, n);
    if(!n) break;
  } while(n != 6174);
  return 0;
}
