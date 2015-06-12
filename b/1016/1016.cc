#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int gao(char *s, char d) {
  int ans = 0, cnt = count(s, s + strlen(s), d);
  while(cnt--) ans = ans * 10 + d - '0';
  return ans;
}

int main(int argc, const char *argv[])
{
  char a, da[12], b, db[12];
  scanf("%s %c %s %c", da, &a, db, &b);
  printf("%d", gao(da, a) + gao(db, b));
  return 0;
}
