#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int tod[1<<8];
char N1[11], N2[11];
long long conv(char *s, long long r) {
  long long ans = 0;
  for(; *s; s++) {
    ans = ans*r + tod[(int)*s];
    if(ans < 0) return -1; // overflow
  }
  return ans;
}

int main(int argc, const char *argv[])
{
  int tag, radix;
  for(int c='0'; c<='9'; c++) tod[c] = c-'0';
  for(int c='a'; c<='z'; c++) tod[c] = c-'a'+10;
  scanf("%s %s %d %d", N1, N2, &tag, &radix);
  if(tag != 1) swap(N1, N2); // fix N1, tune N2
  long long n = conv(N1, radix), l = tod[(int)*max_element(N2+0, N2+strlen(N2))]+1, r = n+1, m, t;
  bool fnd = false;
  assert(n > 0 && n < LLONG_MAX); // given is within long long 大丈夫ですか?
  while(l <= r) { // deal if initial l = r
    m = l + (r-l) / 2, t = conv(N2, m);
    if(t==-1 || t > n) r = m - 1;
    else if(t < n) l = m + 1;
    else { fnd = true; break; }
  }
  if(fnd) printf("%lld\n", m);
  else puts("Impossible");
  return 0;
}
