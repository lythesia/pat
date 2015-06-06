#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const char day[][4] = {
  "MON",
  "TUE",
  "WED",
  "THU",
  "FRI",
  "SAT",
  "SUN",
};
char s1[61], s2[61];

int main(int argc, const char *argv[])
{
  int d[3] = {0}, cnt = 0, group = 2;
  // it is assert that d[0] and d[1] are found in first string pair, so no need to try finding d[2] in first pair
  while(group--) {
    scanf("%s", s1), scanf("%s", s2);
    for(char *p1=s1, *p2=s2; *p1 && *p2; p1++, p2++) {
      if(*p1 == *p2) {
        char c = *p1;
        if(!cnt) {
          if(c >= 'A' && c <= 'G') d[cnt++] = c - 'A';
        }
        else if(cnt == 1) {
          if((c >= 'A' && c <= 'N') || isdigit(c)) d[cnt++] = isupper(c) ? 10 + c - 'A' : c - '0';
        }
        else if(cnt == 2) {
          if(isalpha(c)) d[cnt++] = p1 - s1;
        }
      }
    }
  }
  printf("%s %02d:%02d\n", day[d[0]], d[1], d[2]);
  return 0;
}
