#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

// Min Stack
stack<pair<int, int>> stk;

void add(int x) {
    int mini = stk.empty() ? x : min(x, stk.top().second);
    stk.push({x, mini});
}
int remove() {
    int removed = stk.top().first;
    stk.pop();
    return removed;
}
int get_min() { return stk.top().second; }

// Min Queue

// Basic (Need to know the element that will be removed)
deque<int> q;

void add(int x) {
    while (!q.empty() && q.back() > x)
        q.pop_back();
    q.push_back(x);
}
void remove(int x) {
    if (!q.empty() && q.front() == x)
        q.pop_front();
}
int get_min() { return q.front(); }

// Keep track of index (Don't need to know element that will be removed)
deque<pair<int, int>> q;
int cnt_added = 0, cnt_removed = 0;

void add(int x) {
    while (!q.empty() && q.back().first > x)
        q.pop_back();
    q.push_back({x, cnt_added++});
}
void remove() {
    if (!q.empty() && q.front().second == cnt_removed)
        q.pop_front();
    cnt_removed++;
}
int get_min() { return q.front().first; }

// Two stacks (Get removed element)
stack<pair<int, int>> stk1, stk2;

void add(int x) {
    int mini = stk1.empty() ? x : min(x, stk1.top().second);
    stk1.push({x, mini});
}
int remove() {
    if (stk2.empty())
    while (!stk1.empty()) {
        int element = stk1.top().first;
        stk1.pop();
        int mini = stk2.empty() ? element : min(element, stk2.top().second);
        stk2.push({element, mini});
    }

    int removed = stk2.top().first;
    stk2.pop();
    return removed;
}
int get_min() {
    if (stk1.empty() || stk2.empty())
        return stk1.empty() ? stk2.top().second : stk1.top().second;
    return min(stk1.top().second, stk2.top().second);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}