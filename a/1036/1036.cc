#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct st {
  char name[11] = {0}, id[11] = {0};
  int grade;
};
bool operator < (const st &x, const st &y) { return x.grade < y.grade; }
int N;
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  vector<st> male, female;
  char name[11] = {0}, gender, id[11] = {0};
  int grade;
  while(N--) {
    scanf("%s %c %s %d", name, &gender, id, &grade);
    st t;
    strcpy(t.name, name), strcpy(t.id, id), t.grade = grade;
    if(gender == 'M') male.emplace_back(t);
    else female.emplace_back(t);
  }
  auto h = max_element(female.begin(), female.end()),
       l = min_element(male.begin(), male.end());
  if(h != female.end()) printf("%s %s\n", h->name, h->id);
  else puts("Absent");
  if(l != male.end()) printf("%s %s\n", l->name, l->id);
  else puts("Absent");
  if(h != female.end() && l != male.end()) printf("%d\n", h->grade - l->grade);
  else puts("NA");
  return 0;
}
