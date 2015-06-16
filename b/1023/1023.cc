#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int d[10];
int main(int argc, const char *argv[])
{
  for(int i=0; i<10; i++) scanf("%d", &d[i]);
  if(d[0]) {
    int *p = find_if(d + 1, d + 10, [](int x){return x != 0;});
    printf("%zu", p - d), (*p)--; 
  }
  for(int i=0; i<10; i++) while(d[i]--) printf("%d", i);
  puts("");
  return 0;
}
