#include <iostream>

using std::cout, std::cin;

bool is_ascending(int *arr, int length);
bool is_descending(int *arr, int length);

int main() {
    const int scale_num = 8;
    int scales[scale_num];
    
    for (int i=0; i<scale_num; i++) {
        cin >> scales[i];
    }

    if (is_ascending(scales, scale_num)) {
        cout << "ascending" << '\n';
    }
    else if (is_descending(scales, scale_num)) {
        cout << "descending" << '\n';
    }
    else {
        cout << "mixed" << '\n';
    }
}

bool is_ascending(int *arr, int length) {
    for (int i=0; i<length; i++) {
        if (arr[i] != i + 1) {
            return false;
        }
    }
    return true;
}

bool is_descending(int *arr, int length) {
    for (int i=0; i<length; i++) {
        if (arr[i] != length - i) {
            return false;
        }
    }
    return true;
}