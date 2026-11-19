#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// --- CLI Argument Parser ---
map<string, string> args;
void parse_args(int argc, char* argv[]) {
  for (int i = 1; i < argc; i++) {
    string s = argv[i];
    if (s.rfind("--", 0) == 0) {
      size_t eq = s.find('=');
      if (eq != string::npos)
        args[s.substr(2, eq - 2)] = s.substr(eq + 1);
      else
        args[s.substr(2)] = "1";
    } else if (!args.count("seed")) {
      args["seed"] = s; // First positional argument acts as seed
    }
  }
  if (args.count("seed")) rng.seed(stoull(args["seed"]));
}

long long opt(const string& key, long long def) {
  return args.count(key) ? stoll(args[key]) : def;
}

string opt_str(const string& key, const string& def) {
  return args.count(key) ? args[key] : def;
}

// --- Random Helpers ---
long long r_int(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}

vector<long long> r_array(int n, long long l, long long r, bool distinct = false) {
  if (!distinct) {
    vector<long long> a(n);
    for (int i = 0; i < n; i++) a[i] = r_int(l, r);
    return a;
  }
  assert(r - l + 1 >= n);
  set<long long> s;
  while ((int)s.size() < n) s.insert(r_int(l, r));
  vector<long long> a(s.begin(), s.end());
  shuffle(a.begin(), a.end(), rng);
  return a;
}

vector<int> r_perm(int n, int start = 1) {
  vector<int> p(n);
  iota(p.begin(), p.end(), start);
  shuffle(p.begin(), p.end(), rng);
  return p;
}

string r_string(int n, char l = 'a', char r = 'z') {
  string s(n, ' ');
  for (int i = 0; i < n; i++) s[i] = char(r_int(l, r));
  return s;
}

vector<pair<int, int>> r_tree(int n, int elongation = 0) {
  vector<int> p = r_perm(n, 1);
  vector<pair<int, int>> edges;
  for (int i = 2; i <= n; i++) {
    int lo = max(1, i - 1 - max(0, 10 - elongation));
    int par = (elongation < 0) ? 1 : r_int(lo, i - 1);
    int u = p[par - 1], v = p[i - 1];
    if (r_int(0, 1)) swap(u, v);
    edges.push_back({u, v});
  }
  shuffle(edges.begin(), edges.end(), rng);
  return edges;
}

template<typename T>
void print_vec(const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    cout << v[i] << (i + 1 == (int)v.size() ? "" : " ");
  cout << "\n";
}

int main(int argc, char* argv[]) {
  parse_args(argc, argv);

  // Read CLI options with sensible debugging defaults
  int t        = opt("t", r_int(1, 5));
  int max_n    = opt("n", 10);
  long long lo = opt("min", 1);
  long long hi = opt("max", 20);
  bool dist    = opt("distinct", 0);

  cout << t << "\n";
  while (t--) {
    int n = opt("fixed_n", 0) ? max_n : r_int(1, max_n);
    cout << n << "\n";
    print_vec(r_array(n, lo, hi, dist));
  }
  return 0;
}
