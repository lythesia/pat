#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, K;
inline int f(char* n) {
  return (n[0]-'A')*26*26*10+(n[1]-'A')*26*10+(n[2]-'A')*10+n[3]-'0';
}
const int MMAX = 26*26*26*10+1;
int st[MMAX];
set<int> cs[500000];
unordered_map<string, set<int>> regist;
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &K);
  int c, s, cnt = 0;
  char buf[5] = {0};
  while(K--) {
    scanf("%d%d", &c, &s);
    while(s--) {
      scanf("%s", buf);
      int sn = f(buf);
      if(!st[sn]) st[sn] = ++cnt;
      cs[st[sn] - 1].insert(c);
    }
  }
  while(scanf("%s", buf) != EOF) {
    printf("%s ", buf);
    int sn = f(buf);
    if(!st[sn]) puts("0");
    else {
      printf("%zu", cs[st[sn] - 1].size());
      for(int i : cs[st[sn] - 1]) printf(" %d", i);
      puts("");
    }
  }
  return 0;
}
