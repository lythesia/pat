#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

char buf[1048577];
map<string, int> h;
int main(int argc, const char *argv[])
{
  gets(buf);
  for(char *p=buf; *p; p++) *p = tolower(*p);
  char *s = buf, *p, *last = buf + strlen(buf);
  do {
    p = find_if(s, last, [](char c){return !isalnum(c);});
    h[string(s, p)]++;
  } while((s = find_if(p, last, [](char c){return isalnum(c);})) != last);
  assert(!h.empty());
  auto ans = max_element(h.begin(), h.end(), [](const pair<string, int> &x, const pair<string, int> &y){return x.second < y.second;});
  printf("%s %d\n", ans->first.c_str(), ans->second);
  return 0;
}
