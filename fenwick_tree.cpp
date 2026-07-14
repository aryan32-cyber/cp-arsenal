cpp#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree (Binary Indexed Tree)
// Supports: point update, prefix sum query — both O(log n)
// 1-indexed internally

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
       this->n = n;   
        bit = vector<int>(n + 1, 0); 
    }

    // Add 'val' to index i (1-indexed)
    void update(int i, int val) {
        for (; i <= n; i += i & (-i))
            bit[i] += val;
    }

    // Sum of elements from 1 to i (1-indexed)
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    // Sum of range [l, r] (1-indexed, inclusive)
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};
