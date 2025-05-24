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

// Estructuras de Datos

// Array
// const int N = 10;
// int arr[N];
// fill(arr, arr + N, -1);

// LinkedList
struct Node {
    int v;
    Node *nxt;
    Node() : v(0), nxt(nullptr) {}
    Node(int _v) : v(_v), nxt(nullptr) {}
    Node(int _v, Node *n) : v(_v), nxt(n) {}
};
// Node *node = new Node(10);

// Double-ended Queue
// deque<int> dq;
// dq.push_back(10);
// dq.push_front(20);
// int front = dq.front();
// int back = dq.back();

// Priority Queue (Heap)
// priority_queue<int> max_heap;
// priority_queue<int, vector<int>, greater<int>> min_heap;
// priority_queue<pair<int, int>, vector<pair<int, int>>, 
//                greater<pair<int, int>>> min_heap_pair;

// Struct
struct Rectangle {
    float w;
    float h;
    float area() const {
        return w * h;
    }

    Rectangle operator+(const Rectangle &other) const {
        return {w + other.w, h + other.h};
    }
    bool operator==(const Rectangle &other) const {
        return w == other.w && h == other.h;
    }
    bool operator!=(const Rectangle &other) const {
        return !(*this == other);
    }
    // Overload '<' for sorting with sort
    bool operator<(const Rectangle &other) const {
        return area() < other.area();
    }
};

// Rectangle rect1 = {10.0f, 20.0f};
// Rectangle rect2 {10.0f, 20.0f};
// Rectangle rect3; rect3.w = 10.0f; rect3.h = 20.0f;
// vector<Rectangle> rects = {{10.0f, 20.0f}, {30.0f, 40.0f}};

// Lambda Functions
// auto lambda = []() { cout << "Hello from lambda!\n"; };
// lambda();

// int equal_sides = count_if(all(rects),
//     [](const Rectangle &rect) {
//         return rect.w == rect.h;
//     });

// transform(all(rects), rects.begin(), // in-place
//     [](const Rectangle &rect) {
//         return Rectangle{rect.w + 100, rect.h + 100};
//     });

// auto comp = [](const Rectangle &rect1, const Rectangle &rect2) {
//     return rect1.area() > rect2.area(); // Decreasing
// };
// sort(all(rects), comp);
// priority_queue<Rectangle, vector<Rectangle>, decltype(comp)> min_heap(comp);
// priority_queue<Rectangle> max_heap; // If '<' is already overloaded

// vector<vector<int>> adj_list;
// function<void(int, int)> dfs = [&dfs, &adj_list](int u, int prev) {
//     for (int &v : adj_list[u])
//     if (v != prev) dfs(v, u);
// };
// dfs(1, 0);

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    vector<vector<int>> adj_list;
    function<void(int, int)> dfs = [&dfs, &adj_list](int u, int prev) {
        for (int &v : adj_list[u])
        if (v != prev) dfs(v, u);
    };
    dfs(1, 0);

    return 0;
}