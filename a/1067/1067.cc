#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, a[100000];
int fnd(int x) {
  for(int i=x; i<N; i++) if(a[i] != i) return i;
  return -1;
}
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &a[i]);
  int p = 0, ans = 0;
  while((p = fnd(p)) != -1) {
    if(!a[0]) { // one circle done
      swap(a[0], a[p]);
      ans++;
    }
    while(a[0]) {
      swap(a[0], a[a[0]]);
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
