#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct sign {
  char id[16] = {0};
  tuple<int, int, int> time {0,0,0};
  bool operator <(const sign &s) {
    return time < s.time;
  }
};

int main(int argc, const char *argv[])
{
  int M;
  scanf("%d", &M);
  vector<sign> vsn(M<<1);
  for(int i=0; i<(M<<1); i+=2) {
    scanf("%s", vsn[i].id);
    scanf("%d:%d:%d", &get<0>(vsn[i].time), &get<1>(vsn[i].time), &get<2>(vsn[i].time));
    strcpy(vsn[i+1].id, vsn[i].id);
    scanf("%d:%d:%d", &get<0>(vsn[i+1].time), &get<1>(vsn[i+1].time), &get<2>(vsn[i+1].time));
  }
  auto p = minmax_element(vsn.begin(), vsn.end());
  printf("%s %s\n", p.first->id, p.second->id);
  return 0;
}
