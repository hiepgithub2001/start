#include <bits/stdc++.h>

using namespace std;

const int lim = 1e9;

struct cube {
    int a, b, c, d, h, id;
    cube() {}
    bool operator < (const cube &x) const {
        return c < x.c;
    }
};

int n;
cube v[300005];
vector <int> vals; int sz;
long long ans[300005];
long long area[300005];
const long long LINF = 1e18;

struct data {
    long long val, lazy, first, second, amount;
    data() {}
} t[3000005];

void unzip(int node, int l, int r) {
    if (t[node].lazy <= t[node].first) {
        t[node].lazy = -1;
        return;
    }
    t[node].val += (t[node].lazy - t[node].first) * t[node].amount;
    t[node].first = t[node].lazy;
    if (r - l > 1) {
        t[node * 2].lazy = max(t[node * 2].lazy, t[node].lazy);
        t[node * 2 + 1].lazy = max(t[node * 2 + 1].lazy, t[node].lazy);
    }
    t[node].lazy = -1;
}
void combine(data &node, data _left, data _right) {
    node.val = _left.val + _right.val;
    if (_left.first < _right.first) {
        node.first = _left.first;
        node.second = min(_left.second, _right.first);
        node.amount = _left.amount;
    }
    else if (_left.first > _right.first) {
        node.first = _right.first;
        node.second = min(_left.first, _right.second);
        node.amount = _right.amount;
    }
    else {
        node.first = _left.first;
        node.second = min(_left.second, _right.second);
        node.amount = _left.amount + _right.amount;
    }
}

void build(int node, int l, int r) {
    t[node].lazy = -1;
    t[node].val = 0;
    t[node].first = 0;
    t[node].second = LINF;
    t[node].amount = vals[r] - vals[l];
    if (r - l == 1) return;
    int m = l + r >> 1;
    build(node * 2, l, m);
    build(node * 2 + 1, m, r);
}

void upd(int node, int l, int r, int u, int v, int x) {
    unzip(node, l, r);
    if (u >= r || v <= l || t[node].first >= x) return;
    if (u <= l && r <= v && t[node].second > x) {
        t[node].lazy = x;
        unzip(node, l, r);
        return;
    }
    int m = l + r >> 1;
    upd(node * 2, l, m, u, v, x);
    upd(node * 2 + 1, m, r, u, v, x);
    combine(t[node], t[node * 2], t[node * 2 + 1]);
}

long long get(int node, int l, int r, int u, int v) {
    if (u >= r || v <= l) return 0;
    unzip(node, l, r);
    if (u <= l && r <= v) return t[node].val;
    int m = l + r >> 1;
    return get(node * 2, l, m, u, v) + get(node * 2 + 1, m, r, u, v);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d >> v[i].h;
        v[i].id = i;
        vals.push_back(v[i].a);
        vals.push_back(v[i].b);
    }
    sort(v + 1, v + n + 1);
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    sz = vals.size();
    build(1, 0, sz);
    for (int i = 1; i <= n; ++i) {
        area[v[i].id] = 1LL * (v[i].b - v[i].a) * v[i].h;
        int l = lower_bound(vals.begin(), vals.end(), v[i].a) - vals.begin();
        int r = lower_bound(vals.begin(), vals.end(), v[i].b) - vals.begin();
        long long old = get(1, 0, sz, l, r);
        upd(1, 0, sz, l, r, v[i].h);
        ans[v[i].id] = get(1, 0, sz, l, r) - old;
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == area[i]) cout << 1 << '\n';
        else if (ans[i] == 0) cout << 0 << '\n';
        else {
            long long d = __gcd(ans[i], area[i]);
            cout << ans[i] / d << '/' << area[i] / d << '\n';
        }
    }
    return 0;
}
