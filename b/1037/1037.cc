#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int p[3], a[3], r[3] = {1, 17, 29};
int main(int argc, const char *argv[])
{
  scanf("%d.%d.%d %d.%d.%d", &p[0], &p[1], &p[2], &a[0], &a[1], &a[2]);
  int ans = 0;
  for(int i=0; i<3; i++) ans = ans * r[i] + a[i] - p[i];
  if(ans < 0) printf("-"), ans = -ans;
  int s = ans / 29;
  printf("%d.%d.%d\n", s / 17, s % 17, ans % 29);
  return 0;
}
