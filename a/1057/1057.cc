#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
multiset<int, greater<int>> mmax;
multiset<int> mmin;
stack<int> st;
// assert mmax.size == mmin.size + 1(or 0)
void peek_median() {
  if(st.empty()) puts("Invalid");
  else printf("%d\n", *mmax.begin());
}
void push(int x) {
  st.push(x);
  if(mmax.size() > mmin.size()) {
    assert(mmax.size() == mmin.size() + 1);
    if(x >= *mmax.begin()) mmin.insert(x);
    else {
      mmin.insert(*mmax.begin());
      mmax.erase(mmax.begin());
      mmax.insert(x);
    }
  }
  else {
    assert(mmax.size() == mmin.size());
    if(mmax.empty() || x <= *mmin.begin()) mmax.insert(x);
    else {
      assert(!mmin.empty() && !mmax.empty());
      mmax.insert(*mmin.begin());
      mmin.erase(mmin.begin());
      mmin.insert(x);
    }
  }
}
void pop() {
  if(st.empty()) puts("Invalid");
  else {
    int x = st.top(); st.pop();
    printf("%d\n", x);
    if(mmax.size() > mmin.size()) {
      assert(mmax.size() == mmin.size() + 1);
      if(x > *mmax.begin()) {
        mmin.erase(mmin.find(x));
        mmin.insert(*mmax.begin());
        mmax.erase(mmax.begin());
      }
      else mmax.erase(mmax.find(x));
    }
    else {
      assert(mmax.size() == mmin.size());
      if(x > *mmax.begin()) mmin.erase(mmin.find(x));
      else {
        mmax.erase(mmax.find(x));
        mmax.insert(*mmin.begin());
        mmin.erase(mmin.begin());
      }
    }
  }
}
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  char cmd[11] = {0};
  int x;
  while(N--) {
    scanf("%s", cmd);
    if(cmd[1] == 'u') {
      scanf("%d", &x);
      push(x);
    }
    else if(cmd[1] == 'o') pop();
    else if(cmd[1] == 'e') peek_median();
  }
  return 0;
}
