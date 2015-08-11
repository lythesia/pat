#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N;
int pre[30], in[30], post[30], pc;
void inorder(int *s1, int *e1, int *s2, int *e2) {
  if(s1 >= e1 || s2 >= e2) return;
  int root = *s1, *r = find(s2, e2, root);
  post[--pc] = root;
  inorder(s1 + 1 + (r - s2), e1, r + 1, e2); // right
  inorder(s1 + 1, s1 + 1 + (r - s2), s2, r); // left
} 
int main(int argc, const char *argv[])
{
  stack<int> st;
  scanf("%d", &N), pc = N;
  char op[5];
  int cp = 0, ci = 0;
  for(int i=0; i<N*2; i++) {
    scanf("%s", op);
    if(op[1] == 'u') scanf("%d", &pre[cp]), st.push(pre[cp]), cp++;
    else in[ci] = st.top(), st.pop(), ci++;
  }
  inorder(pre, pre + N, in, in + N);
  for(int i=0; i<N; i++) printf("%s%d", i ? " ":"", post[i]);
  puts("");
  return 0;
}
