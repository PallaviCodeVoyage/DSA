class Solution {
  public:
    vector<int> ans;

    int querr(int i, int l, int r, int ql, int qr, vector<int>& tree) {
        if (qr < l || r < ql) return 0;

        if (ql <= l && r <= qr) return tree[i];

        int mid = (l + r) / 2;
        int ls = querr(2 * i + 1, l, mid, ql, qr, tree);
        int rs = querr(2 * i + 2, mid + 1, r, ql, qr, tree);
        return ls + rs;
    }

    void build(int i, int l, int r, vector<int>& tree, int arr[]) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, tree, arr);
        build(2 * i + 2, mid + 1, r, tree, arr);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        vector<pair<int, int>> querry;
        for (int i = 0; i < 2 * q; i += 2) {
            querry.push_back({queries[i], queries[i + 1]});
        }

        vector<int> Tree(4 * n);
        build(0, 0, n - 1, Tree, arr);

        for (pair<int, int> p : querry) {
            // p.first and p.second are 1-based index; convert to 0-based
            int a = querr(0, 0, n - 1, p.first - 1, p.second - 1, Tree);
            ans.push_back(a);
        }

        return ans;
    }
};
