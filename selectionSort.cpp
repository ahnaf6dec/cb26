// implementation of selection  sort
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

void selectionSort(vector<int>&arr) {
  int n = arr.size();
  for(int i = 0; i < n - 1; ++i) {
    int curr = i;
    for(int j = i + 1; j < n; ++j) {
      if(arr[j] < arr[curr]) {
        curr = j;
      }
    }
    swap(arr[i], arr[curr]);
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
  selectionSort(a);
  printArr(a);
  return 0;
}

/*
  Author: ahnaf09
*/
