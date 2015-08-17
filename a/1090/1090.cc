#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
double P, R;
vi s[100000];
int dep, tot;
void dfs(int root, int lv) {
  if(s[root].empty()) {
    if(lv == dep) tot++;
    else if(lv > dep) dep = lv, tot = 1;
  }
  else for(int chd : s[root]) dfs(chd, lv + 1);
}
int main(int argc, const char *argv[])
{
  scanf("%d%lf%lf", &N, &P, &R);
  int x, root = 0;
  for(int i=0; i<N; i++) {
    scanf("%d", &x);
    if(x == -1) root = i;
    else s[x].push_back(i);
  }
  dfs(root, 0);
  printf("%.2lf %d\n", P * pow(1.0 + R/100.0, dep), tot);
  return 0;
}
