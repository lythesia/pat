#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

char zm[] = "10X98765432";
int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
bool verify(char *id) {
  assert(strlen(id) == 18);
  int z = 0;
  for(int i=0; i<17; i++) if(isdigit(id[i])) z += (id[i] - '0') * w[i]; else return false;
  return zm[z % 11] == id[17];
}
int main(int argc, const char *argv[])
{
  int N, cnt = 0;
  scanf("%d", &N); getchar();
  while(N--) {
    char id[19] = {0};
    gets(id);
    if(!verify(id)) printf("%s\n", id), cnt++;
  }
  if(!cnt) puts("All passed");
  return 0;
}
