#include <iostream>
#include <vector>

using namespace std;

const string ANSWER_WORD = "ABCDE";
const int LENGTH = ANSWER_WORD.size();
constexpr char PRESENT = 'Y';
constexpr char ABSENT = 'B';
constexpr char FILLER = 'F';

vector<string> guess_queries(const vector<string>& results) {
    vector<string> queries;

    for (const auto& result : results) {
        string query = ANSWER_WORD;
        vector<int> absent_index;
        vector<int> present_index;

        for (int i = 0; i < LENGTH; ++i) {
            if (result[i] == PRESENT) {
                present_index.push_back(i);
            } else if (result[i] == ABSENT) {
                absent_index.push_back(i);
            }
        }

        for (const int idx : absent_index) {
            query[idx] = FILLER;
        }

        if (present_index.size() == 1) {
            if (absent_index.size() == 0) {
                return {};
            }
            query[present_index[0]] = ANSWER_WORD[absent_index[0]];
        } else if (present_index.size() > 1) {
            char temp = query[present_index[0]];
            for (int i = 1; i < present_index.size(); ++i) {
                query[present_index[i - 1]] = query[present_index[i]];
            }
            query[present_index.back()] = temp;
        }

        queries.push_back(query);
    }

    return queries;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> results(n);
    for (auto& result : results) {
        cin >> result;
    }

    auto queries = guess_queries(results);

    if (queries.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ANSWER_WORD << '\n';
        for (auto& f : queries) {
            cout << f << '\n';
        }
    }

    return 0;
}