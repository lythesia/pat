#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int N;
  scanf("%d", &N);
  vector<bool> p(N+1, true);
  int sq = (int)sqrt(N);
  for(int i=2; i<=sq; i++) {
    if(p[i]) for(int j=i*i; j<=N; j+=i) p[j] = false;
  }
  int prev = 2, cnt = 0;
  for(int i=3; i<=N; i++) {
    if(p[i]) {
      if(i - prev == 2) cnt++;
      prev = i;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
