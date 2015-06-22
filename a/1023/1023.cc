#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int a[10];
int main(int argc, const char *argv[])
{
  char buf[21] = {0};
  gets(buf);
  int n = strlen(buf);
  for_each(buf, buf + n, [](char c){a[(int)(c - '0')]++;});
  bool no = false;
  int c = 0;
  for(int i=n-1; ~i; i--) {
    int s = 2 * (buf[i] - '0') + c;
    buf[i] = s % 10 + '0', c = s / 10, --a[s % 10];
  }
  if(c) no = true; 
  else for(int i=0; i<10; i++) if(a[i]) { no = true; break; }
  no ? puts("No") : puts("Yes");
  if(c) printf("%d", c);
  puts(buf);
  return 0;
}
