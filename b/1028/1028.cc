#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct per {
  char name[6] = {0}, date[11] = {0};
};
bool operator < (const per &lhs, const per &rhs) {
  return string(lhs.date) < string(rhs.date);
}
int N;
per p[100001];
int main(int argc, const char *argv[])
{
  int cnt = 0;
  scanf("%d", &N);
  while(N--) {
    scanf("%s %s", p[cnt].name, p[cnt].date);
    string s = p[cnt].date;
    if(s >= "1814/09/06" && s <= "2014/09/06") cnt++;
  }
  auto min_max = minmax_element(p, p + cnt);
  printf("%d", cnt);
  if(cnt) printf(" %s %s\n", (*min_max.first).name, (*min_max.second).name);
  else puts(""); return 0;
}
