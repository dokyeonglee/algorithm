#include <iostream>
#include <stack>

using namespace std;

struct TruthValues {
    bool has_true = false;
    bool has_false = false;
};

int calculate_max_depth(const string& and_or_tree) {
    int max_depth = 0;
    int depth = 0;

    for (const char c : and_or_tree) {
        if (c == '(') {
            ++depth;
        } else if (c == ')') {
            --depth;
        }
        max_depth = max(max_depth, depth);
    }

    return max_depth;
}

TruthValues collect_truth_values(stack<char>& st) {
    TruthValues truth_values;

    while (!st.empty() && st.top() != '(') {
        if (st.top() == 'T') {
            truth_values.has_true = true;
        } else {
            truth_values.has_false = true;
        }
        st.pop();
    }

    if (!st.empty() && st.top() == '(') {
        st.pop();
    }

    return truth_values;
}

char evaluate_node(const TruthValues& truth_values, const bool is_and_node) {
    if (is_and_node) {
        return truth_values.has_false ? 'F' : 'T';
    }
    return truth_values.has_true ? 'T' : 'F';
}

char evaluate_substree(stack<char>& st, const int max_depth, const int depth) {
    auto truth_values = collect_truth_values(st);
    bool is_and_node = ((max_depth - depth) % 2 == 0);
    return evaluate_node(truth_values, is_and_node);
}

string evaluate_and_or_tree(const string& and_or_tree) {
    int max_depth = calculate_max_depth(and_or_tree);
    int depth = 0;
    stack<char> st;

    for (const char c : and_or_tree) {
        if (c == '(') {
            ++depth;
            st.push(c);
        } else if (c == ')') {
            char result = evaluate_substree(st, max_depth, depth);
            st.push(result);
            --depth;
        } else {
            st.push(c);
        }
    }

    return st.top() == 'T' ? "true\n" : "false\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1;; ++i) {
        string and_or_tree;
        cin >> and_or_tree;

        if (and_or_tree[1] == ')') {
            break;
        }

        cout << i << ". " << evaluate_and_or_tree(and_or_tree);
    }

    return 0;
}