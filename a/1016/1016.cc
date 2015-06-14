#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct record {
  int m = 0, dd = 0, hh = 0, mm = 0;
  bool on = false;
  record(int mon, int day, int hour, int min, bool o) : m(mon), dd(day), hh(hour), mm(min), on(o) {}
};
bool operator < (const record &x, const record &y) {
  return x.dd != y.dd ? x.dd < y.dd :
         x.hh != y.hh ? x.hh < y.hh : x.mm < y.mm;
}

int toll[24]; // cents per min
int N;
map<string, vector<record>> lst; 

int main(int argc, const char *argv[])
{
  for(int i=0; i<24; i++) scanf("%d", &toll[i]);
  scanf("%d", &N);
  while(N--) {
    char buf[21] = {0}, st[16] = {0};
    int m, dd, hh, mm;
    scanf("%s %d:%d:%d:%d %s", buf, &m, &dd, &hh, &mm, st);
    lst[string(buf)].emplace_back(record(m, dd, hh, mm, strcmp(st, "on-line") ? false : true));
  }
  for(auto &p : lst) {
    auto &v = p.second;
    sort(v.begin(), v.end());
    int tot = 0;
    auto last = find_if(v.begin(), v.end(), [](const record &r){ return r.on; });
    if(last == v.end()) continue;
    for(auto it=last+1; it!=v.end(); it++) {
      if(last->on && !it->on) {
        if(!tot) printf("%s %02d\n", p.first.c_str(), it->m);
        int d = (it->dd - last->dd)*1440 + (it->hh - last->hh)*60 + (it->mm - last->mm), f = 0; // cents
        int hours = (it->dd - last->dd)*24 + (it->hh - last->hh);
        for(int i=0, cur=last->hh; i<hours; i++, cur = (cur+1)%24) f += toll[cur]*60;
        f += toll[it->hh]*it->mm - toll[last->hh]*last->mm;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
            last->dd, last->hh, last->mm,
            it->dd, it->hh, it->mm,
            d, 1.0*f/100);
        tot += f;
      }
      last = it;
    }
    if(tot) printf("Total amount: $%.2lf\n", 1.0*tot/100);
  }
  return 0;
}
