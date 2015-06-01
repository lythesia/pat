#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

// sum fisrt and last
// not unique: sum smaller first ans smaller last
// if all negative: 0 start and end

int K, N[10000];
int main(int argc, const char *argv[])
{
  scanf("%d", &K);
  int ans = -1, as = 0, ae = K-1, sum = 0, s = 0;
  for(int i=0; i<K; i++) {
    scanf("%d", &N[i]);
    sum += N[i];
    if(sum > ans) ans = sum, as = s, ae = i;
    if(sum < 0) sum = 0, s = i+1;
  }
  printf("%d %d %d\n", ans==-1 ? 0 : ans, N[as], N[ae]);
  return 0;
}
