#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, K;
char stu[40000][5];
vector<char*> cs[2500];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &K);
  for(int i=0; i<N; i++) {
    int C, c;
    scanf("%s %d", stu[i], &C);
    while(C--) {
      scanf("%d", &c);
      cs[c - 1].push_back(stu[i]);
    }
  }
  for(int i=0; i<K; i++) {
    sort(cs[i].begin(), cs[i].end(), [](char *x, char *y){ return strcmp(x, y) < 0; });
    printf("%d %zu\n", i + 1, cs[i].size());
    for(char *s : cs[i]) printf("%s\n", s);
  }
  return 0;
}
