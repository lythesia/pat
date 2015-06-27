#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct stu {
  int id = 0;
  char name[9] = {0};
  int grade = 0;
};
int N, C;
stu st[100000];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &C);
  for(int i=0; i<N; i++) scanf("%d %s %d", &st[i].id, st[i].name, &st[i].grade);
  switch(C) {
    case 1:
      sort(st, st + N, [](const stu &x, const stu &y){return x.id < y.id;}); break;
    case 2: 
      sort(st, st + N, [](const stu &x, const stu &y){return strcmp(x.name, y.name) ? strcmp(x.name, y.name) < 0 : x.id < y.id;}); break;
    case 3:
      sort(st, st + N, [](const stu &x, const stu &y){return x.grade == y.grade ? x.id < y.id : x.grade < y.grade;}); break;
  }
  for(int i=0; i<N; i++) printf("%06d %s %d\n", st[i].id, st[i].name, st[i].grade);
  return 0;
}
