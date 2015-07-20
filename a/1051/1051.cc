#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int M, N, K;
bool v[1001];
int pop[1001];
// rather dirty..
int main(int argc, const char *argv[])
{
  scanf("%d%d%d", &M, &N, &K);
  while(K--) {
    stack<int> st;
    memset(v, 0, sizeof(v));
    bool invalid = false;
    for(int i=0; i<N; i++) scanf("%d", &pop[i]);
    for(int i=0; i<N; i++) {
      int x = pop[i];
      if(st.empty() || (st.top() != x && !v[x])) { // !v[x] equals x > all in stack, or printed out
        for(int j=1; j<=x; j++) {
          if(!v[j]) {
            if((int)st.size() == M) {
              invalid = true;
              goto END;
            }
            else {
              st.push(j);
              v[j] = true;
            }
          }
        }
        st.pop();
      }
      else if(st.top() != x){
        invalid = true;
        goto END;
      }
      else st.pop();
    }
END:
    invalid ? puts("NO") : puts("YES");
  }
  return 0;
}
