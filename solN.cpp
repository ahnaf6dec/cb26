#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

const int N = 200005;
const ll INF = 4e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// go up in number line
ll ceilDiv(ll a, ll b) {
  ll res = a / b;
  if((a % b != 0) && ((a > 0) == (b > 0))) {
    ++res;
  }
  return res;
}
// go down in number line
ll floorDiv(ll a , ll b) {
  ll res = a / b;
  if((a % b != 0) && ((a < 0) ^ (b < 0))) {
    --res;
  }
  return res;
}

bool cmp(int a, int b) {
  return abs(a) < abs(b);
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << ceilDiv(5,3) << endl;
  // float a = 5324.234f, b = 5324.234f;
  // if(abs(a - b) < EPS) {
  //   cout << "Equal" << endl;
  // }
  // string s;
  // getline(cin, s);
  // int freq[26] = {};
  // for(char c : s) {
  //   freq[c - 'a']++;
  // }
  // for(int i = 0; i < 26; ++i) {
  //   cout << char('a' + i) << ':' << ' ' << freq[i] << " \n"[i == 25];
  // }
  // int age;
  // string name;
  // cin >> age;
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  // getline(cin, name);
  // cout << age << ' ' << name << endl;

  vector<int>a = {-5, 2, -1, 4, 3};
  sort(a.begin(), a.end(), cmp);
  for(auto e : a) {
    cout << e << endl;
  }
  return 0;
}
