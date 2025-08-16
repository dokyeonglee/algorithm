#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1000000000;

struct Box {
    int width;
    int height;
};

void rotate_box(Box& box) {
    swap(box.width, box.height);
}

void rotate_boxes(vector<Box>& boxes, const int rotate_state) {
    for (int i = 0; i < 3; ++i) {
        if (rotate_state & (1 << i)) {
            rotate_box(boxes[i]);
        }
    }
}

int evaluate_row_shape(const vector<Box>& boxes) {
    int total_width = boxes[0].width + boxes[1].width + boxes[2].width;
    int total_height = max(boxes[0].height, max(boxes[1].height, boxes[2].height));
    return total_width * total_height;
}

int evaluate_c_shape(const vector<Box>& boxes, const int left_box_idx) {
    const Box& right_upper_box = boxes[(left_box_idx + 1) % 3];
    const Box& right_lower_box = boxes[(left_box_idx + 2) % 3];
    int total_width = boxes[left_box_idx].width + max(right_upper_box.width, right_lower_box.width);
    int total_height = max(boxes[left_box_idx].height, right_upper_box.height + right_lower_box.height);
    return total_width * total_height;
}

int calculate_min_area(vector<Box>& boxes) {
    int min_area = INF;

    for (int rotate_state = 0; rotate_state < 8; ++rotate_state) {
        rotate_boxes(boxes, rotate_state);
        min_area = min(min_area, evaluate_row_shape(boxes));
        for (int i = 0; i < 3; ++i) {
            min_area = min(min_area, evaluate_c_shape(boxes, i));
        }
        rotate_boxes(boxes, rotate_state);
    }

    return min_area;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        vector<Box> boxes(3);
        for (auto& box : boxes) {
            cin >> box.width >> box.height;
        }

        cout << calculate_min_area(boxes) << '\n';
    }

    return 0;
}