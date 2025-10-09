#include <iostream>
#include <vector>

using namespace std;

constexpr int RLE_CHUNK_SIZE = 80;

int hex_to_dec(const char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    }
    if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
    return -1;
}

int parse_byte(const string& str, int idx) {
    return hex_to_dec(str[idx]) * 16 + hex_to_dec(str[idx + 1]);
}

string decode_rle(const string rle) {
    string decoded;

    int idx = 0;

    while (idx < rle.size()) {
        const int first_byte = parse_byte(rle, idx);

        if (first_byte & 0x80) {
            int cnt = (first_byte & 0x7F) + 3;
            string value = rle.substr(idx + 2, 2);
            for (int i = 0; i < cnt; ++i) {
                decoded += value;
            }
            idx += 4;
        } else {
            int cnt = (first_byte + 1) << 1; 
            idx += 2;
            decoded += rle.substr(idx, cnt);
            idx += cnt;
        }
    }

    return decoded;
}

void print(const string& str, const int line_size) {
    for (int i = 0; i < str.size(); ++i) {
        cout << str[i];
        if (i % line_size == line_size - 1) {
            cout << '\n';
        }
    }
    if (str.size() % line_size) {
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int b;
        cin >> b;

        const int line_count = (2 * b + RLE_CHUNK_SIZE - 1) / RLE_CHUNK_SIZE;
        string rle;

        for (int i = 0; i < line_count; ++i) {
            string chunk;
            cin >> chunk;
            rle += chunk;
        }

        const string decoded = decode_rle(rle);
        cout << decoded.size() / 2 << '\n';
        print(decoded, RLE_CHUNK_SIZE);
    }

    return 0;
}