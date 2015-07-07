#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
string n[10000];
int main(int argc, const char *argv[])
{
  cin >> N;
  for(int i=0; i<N; i++) cin >> n[i];
  sort(n, n + N, [](const string &x, const string &y){ return x + y < y + x; });
  auto s = find_if(n, n + N, [](const string &s){return stoi(s);});
  if(s == n + N) cout << "0" << endl;
  else {
    cout << stoi(*s++);
    copy(s, n + N, ostream_iterator<string>(cout));
    cout << endl;
  }
  return 0;
}
