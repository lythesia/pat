#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct stu {
  char name[11] = {0}, id[11] = {0};
  int pt = 0;
};

int main(int argc, const char *argv[])
{
  int n;
  scanf("%d", &n);
  vector<stu> st(n);
  for(int i=0; i<n; i++) scanf("%s %s %d", st[i].name, st[i].id, &st[i].pt);
  sort(st.begin(), st.end(), [](const stu &s1, const stu &s2) {return s1.pt > s2.pt;});
  printf("%s %s\n%s %s\n", st.front().name, st.front().id, st.back().name, st.back().id);
  return 0;
}
