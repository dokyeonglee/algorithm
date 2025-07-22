#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Building {
    int height;
    int idx;
};

struct VisibilityInfo {
    int count = 0;
    int nearest_building = -1;
};

template <typename It>
using is_building_iterator = enable_if_t<
    is_same_v<remove_cv_t<typename iterator_traits<It>::value_type>, Building>
>;

template <typename It, typename = is_building_iterator<It>>
vector<VisibilityInfo> compute_one_side_info(const vector<Building>& buildings, It begin, It end) {
    vector<VisibilityInfo> visibility_info(buildings.size());
    stack<Building> st;

    for (; begin != end; ++begin) {
        while (!st.empty() && st.top().height <= begin->height) {
            st.pop();
        }

        int idx = begin->idx;
        visibility_info[idx].count = st.size();
        if (!st.empty()) {
            visibility_info[idx].nearest_building = st.top().idx;
        }

        st.emplace(*begin);
    }

    return visibility_info;
}

int choose_nearest(const int idx, const int left_nearest, const int right_nearest) {
    if (left_nearest == -1) {
        return right_nearest;
    }
    if (right_nearest == -1) {
        return left_nearest;
    }
    if (idx - left_nearest > right_nearest - idx) {
        return right_nearest;
    }
    return left_nearest;
}

vector<VisibilityInfo> calculate_visibility_info(const vector<Building>& buildings) {
    const int n = buildings.size();

    auto left_info = compute_one_side_info(buildings, buildings.begin(), buildings.end());
    auto right_info = compute_one_side_info(buildings, buildings.rbegin(), buildings.rend());

    vector<VisibilityInfo> visibility_info(n + 1);
    for (int i = 0; i < n; ++i) {
        visibility_info[i].count = left_info[i].count + right_info[i].count;
        int left_nearest = left_info[i].nearest_building;
        int right_nearest = right_info[i].nearest_building;
        visibility_info[i].nearest_building = choose_nearest(i, left_nearest, right_nearest);
    }
    
    return visibility_info;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Building> buildings(n);
    for (int i = 0; i < n; ++i) {
        cin >> buildings[i].height;
        buildings[i].idx = i;
    }

    auto visibility_info = calculate_visibility_info(buildings);
    for (int i = 0; i < n; ++i) {
        cout << visibility_info[i].count << ' ';
        if (visibility_info[i].nearest_building != -1) {
            cout << visibility_info[i].nearest_building + 1;
        }
        cout << '\n';
    }

    return 0;
}