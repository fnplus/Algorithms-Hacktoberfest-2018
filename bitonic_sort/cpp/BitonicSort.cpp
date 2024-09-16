#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void compare(vector<int> &a, int i1, int i2) {
  if (a[i1] > a[i2])
    swap(a[i1],a[i2]);
}

void bitonic_swap(vector<int> &a, int lo, int d) {
  for (int i = lo; i < lo+d; ++i) {
    compare(a, i, i+d);
  }
  if (d > 1) {
    bitonic_swap(a, lo, d/2);
    bitonic_swap(a, lo+d, d/2);
  }
}

void bitonic_merge(vector<int> &a, int lo, int hi) {
  for (int i = lo; i < (lo+hi+1)/2; ++i) {
    compare(a, i, lo+hi-i);
  }
  if (hi-lo > 1) {
    bitonic_swap(a, lo, (hi-lo+1)/4);
    bitonic_swap(a, (lo+hi+1)/2, (hi-lo+1)/4);
  }
}

void bitonic_sort(vector<int> &a) {
  int l = a.size();
  for (int i = 2; i <= l; i<<=1) {
    for (int ind = 0; ind < l; ind+=i) {
      bitonic_merge(a, ind, ind+i-1);
    }
  }
}

int main() {

  vector<int> v{1,0,89,6,4,2,4,6,1,70,1,4,1,1,6,285};
  bitonic_sort(v);
  for (int x : v) {
    cout << x << " "; 
  }

  return 0;
}
