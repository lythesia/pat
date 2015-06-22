#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool is_pali(char *s) {
  for(int i=0, j=strlen(s)-1; i<j; i++, j--) if(s[i] != s[j]) return false;
  return true;
}
int main(int argc, const char *argv[])
{
  char n[128] = {0}, rn[128] = {0};
  int k;
  scanf("%s %d", n, &k);
  int step = 0;
  strcpy(rn, n);
  while(!is_pali(n) && step != k) {
    int c = 0, len = strlen(n);
    strcpy(rn, n);
    reverse(n, n + len);
    for(int i=0; i<len; i++) {
      int s = n[i] - '0' + rn[i] - '0' + c;
      n[i] = s % 10 + '0', c = s / 10;
    }
    if(c) n[len] = c + '0';
    step++;
  }
  reverse(n, n + strlen(n));
  puts(n);
  printf("%d\n", step);
  return 0;
}
