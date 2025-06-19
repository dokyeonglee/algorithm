#include <iostream>
#include <vector>

using namespace std;

const int NO_CHILD = -1;

struct Node {
    int left;
    int right;

    bool is_leaf() const {
        return left == NO_CHILD && right == NO_CHILD;
    }

    bool has_only_left() const {
        return right == NO_CHILD;
    }

    bool has_only_right() const {
        return left == NO_CHILD;
    }
};



int find_bead_destination(const vector<Node>& tree, long long k) {

    int now = 1;

    while (!tree[now].is_leaf()) {
        const Node& node = tree[now];

        if (node.has_only_left()) {
            now = node.left;
        } else if (node.has_only_right()) {
            now = node.right;
        }else {
            if (k % 2 == 0) {
                now = node.right;    
            } else {
                now = node.left;
            }
            k = (k + 1) / 2; 
        }
    }

    return now;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Node> tree(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].left >> tree[i].right;
    }

    long long k;
    cin >> k;

    cout << find_bead_destination(tree, k);

    return 0;
}