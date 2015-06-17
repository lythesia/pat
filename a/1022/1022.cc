#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef set<int> si;

int N, M;
unordered_map<string, si> tab[5]; //title, author, key, pub, year;
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  int id;
  char tit[81] = {0}, auth[81] = {0}, kwd[64] = {0}, pb[81] = {0}, y[5] = {0};
  while(N--) {
    scanf("%d\n", &id), gets(tit), gets(auth), gets(kwd), gets(pb), gets(y);
    tab[0][string(tit)].insert(id);
    tab[1][string(auth)].insert(id);
    for(char *tok = strtok(kwd, " "); tok; tok = strtok(NULL, " ")) tab[2][string(tok)].insert(id);
    tab[3][string(pb)].insert(id);
    tab[4][string(y)].insert(id);
  }
  scanf("%d", &M);
  int opt;
  char q[81] = {0};
  while(M--) {
    scanf("%d: ", &opt), gets(q);
    printf("%d: %s\n", opt, q);
    string qs(q);
    if(!tab[opt-1].count(qs)) puts("Not Found");
    else for(int i : tab[opt-1][qs]) printf("%07d\n", i);
  }
  return 0;
}
