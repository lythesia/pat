#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct testee {
  long no = 0;
  int mark = 0, loc = 0, rnk[2] = {0}; // {local, final}
};
bool cmp(const testee *x, const testee *y) {
  return x->mark == y->mark ? x->no < y->no : x->mark > y->mark;
}
void rnk(vector<testee*> &v, int r) {
  sort(v.begin(), v.end(), cmp);
  int prev = (v[0]->rnk[r] = 1), n = v.size();
  for(int i=1; i<n; i++) {
    if(v[i]->mark == v[i-1]->mark) v[i]->rnk[r] = prev;
    else v[i]->rnk[r] = (prev = i + 1);
  }
}

int N;
testee st[100 * 300];
int main(int argc, const char *argv[])
{
  vector<testee*> fin;
  scanf("%d", &N);
  int cnt = 0;
  for(int i=1; i<=N; i++) {
    int k;
    vector<testee*> loc;
    scanf("%d", &k);
    while(k--) {
      scanf("%ld%d", &st[cnt].no, &st[cnt].mark);
      st[cnt].loc = i;
      loc.push_back(&st[cnt]);
      fin.push_back(&st[cnt]);
      cnt++;
    }
    rnk(loc, 0);
  }
  rnk(fin, 1);
  printf("%d\n", cnt);
  for(auto &t : fin) printf("%013ld %d %d %d\n", t->no, t->rnk[1], t->loc, t->rnk[0]);
  return 0;
}
