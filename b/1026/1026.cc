#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int TICK = 100;
int main(int argc, const char *argv[])
{
  int c1, c2, ss, hh, mm;
  scanf("%d%d", &c1, &c2), ss = (int)round(1.0 * (c2 - c1) / TICK), hh = ss / 3600, mm = (ss - hh * 3600) / 60;
  printf("%02d:%02d:%02d\n", hh, mm, ss % 60);
  return 0;
}
