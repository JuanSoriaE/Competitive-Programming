#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

// Helpers
string ltrim(const string &s) {
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    return start == string::npos ? "" : s.substr(start);
}
string rtrim(const string &s) {
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return end == string::npos ? "" : s.substr(0, end + 1);
}
string trim(const string &s) {
    return ltrim(rtrim(s));
}

vector<string> split(const string &s, char delimiter) {
    vector<string> res;
    size_t l = 0, r = s.find(delimiter);
    while (r != string::npos) {
        res.push_back(trim(s.substr(l, r - l)));
        l = r + 1;
        r = s.find(delimiter, l);
    }
    res.push_back(trim(s.substr(l)));
    return res;
}

// Operations
constexpr int NUM_OPS = 7;
constexpr int INF = 1e6;

string aux[NUM_OPS] = {"BUY", "SELL", "UNPACK", "PACK", "? COUNT", "? CONTAINS", "? MIN"};

int ID = 1;
map<int, string> containers;
map<string, int> goods;

int get_op_index(const string &s) {
    for (int i = 0; i < NUM_OPS; i++)
    if (s.substr(0, sz(aux[i])) == aux[i])
        return i;
    return -1;
}
bool is_digit(const char &c) { return c >= '0' && c <= '9'; }
void tolower(string &s) {
    transform(all(s), s.begin(), [](unsigned char c) {
        return tolower(c);
    });
}

void ok() { cout << "OK\n"; }
void discard() { cout << "DISCARD\n"; }
void cont_added(int a) { cout << "OK, " << (a ? to_string(a) : "No") << " containers added.\n"; }

pair<string, int> get_good_qty(const string &s) {
    vector<string> aux = split(s, ' ');
    if (is_digit(aux[0][0])) swap(aux[0], aux[1]);
    return {aux[0], sz(aux) > 1 ? stoi(aux[1]) : 1};
}

void unpack(const string &s) {
    string aux = s.substr(1, sz(s) - 2);

    int cnt = 0;
    for (string t : split(aux, ','))
    if (t[0] == '(') containers[ID++] = t, cnt++;
    else {
        pair<string, int> p = get_good_qty(t);
        goods[p.first] += p.second;
    }
    cont_added(cnt);
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s;
    while (getline(cin, s)) {
        int op_index = get_op_index(s);

        string content = s.substr(sz(aux[op_index]) + 1, INF);
        tolower(content);
        if (op_index == 0) {
            containers[ID++] = content;
            ok();
        } else if (op_index == 1) {
            int id = stoi(content);
            if (containers.count(id)) ok();
            else discard();
            containers.erase(id);
        } else if (op_index == 2) {
            int id = stoi(content);
            if (containers.count(id)) {
                unpack(containers[id]);
                containers.erase(id);
            } else {
                discard();
            }
        } else if (op_index == 3) {

        } else if (op_index == 4) {
            
        } else if (op_index == 5) {

        } else if (op_index == 6) {

        }

        // for (auto &[a, b] : goods) {
        //     debug(a)
        //     debug(b)
        // }
        // for (auto &[a, b] : containers) {
        //     debug(a)
        //     debug(b)
        // }
    }

    return 0;
}