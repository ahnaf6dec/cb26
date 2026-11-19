// implementation of insertion  sort
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

void insertionSort(vector<int>&arr) {
  int n = arr.size();
  for(int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      // cerr << "[i, j] = " << i << ' ' << j << endl;
      --j;
      // cerr << "#2->[j] = " << j << endl;
    }
    arr[j + 1] = key;
  }
}


void printArr(vector<int>&arr) {
  for(int x : arr) {
    cout << x << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int>a(n);
  for(int &x : a){
    cin >> x;
  }
  printArr(a);
  insertionSort(a);
  printArr(a);
  return 0;
}

/*
  Author: ahnaf09
*/
