#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool ofPAT(const char c) {
  return c == 'P' || c =='A' || c == 'T';
}
bool ofA(const char c) {
  return c == 'A';
}

/*
 * s-PAT-s: s = A*
 * s-PA{x}T-s{x}: c-part is x-times of a-part, x according to b-part, the # of A
 */
int main(int argc, const char *argv[])
{
  int n;
  char s[101];
  scanf("%d", &n);
  while(n--) {
    scanf("%s", s);
    int len = strlen(s);
    string ss(s);
    size_t p = ss.find('P'), t = ss.find('T');
    if(all_of(s, s+len, ofPAT) &&
        p != string::npos && t != string::npos &&
        all_of(s, s+p, ofA) && all_of(s+p+1, s+t, ofA) && all_of(s+t+1, s+len, ofA)) {
      int times = t-p-1;
      if(times > 0 && p * times == len-t-1) {
        puts("YES");
        continue;
      }
    }
    puts("NO");
  }
  return 0;
}
