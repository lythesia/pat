#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  char buf[81] = {0};
  gets(buf);
  stack<string> tok;

  char *p  = strtok(buf, " ");
  while(p) {
    tok.emplace(string(p));
    p = strtok(NULL, " ");
  }
  while(tok.size() != 1) {
    printf("%s ", tok.top().c_str());
    tok.pop();
  }
  printf("%s\n", tok.top().c_str());
  return 0;
}
