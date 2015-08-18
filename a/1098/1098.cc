#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, a[100];
int main(int argc, const char *argv[])
{
  int useless;
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &useless);
  for(int i=0; i<N; i++) scanf("%d", &a[i]);
  int *p = find_if(a, a + N, [](int x){return x > a[0];});
  bool heap = is_sorted(p, a + N) && is_heap(a, p);
  if(heap) pop_heap(a, p);
  else sort(a, is_sorted_until(a, a + N) + 1);
  puts(heap ? "Heap Sort" : "Insertion Sort");
  for(int i=0; i<N-1; i++) printf("%d ", a[i]);
  printf("%d\n", a[N-1]);
  return 0;
}
