# include <iostream>

using std::cin, std::cout;

int main() {
    unsigned int N, T, P;
    unsigned int t_shirts_num[6];
    unsigned int t_shirt_set = 0;
    unsigned int pencil_set, pencil_one;

    cin >> N;
    for (int i=0; i<6; i++) {
        cin >> t_shirts_num[i];
    }
    cin >> T >> P;


    for (int i=0; i<6; i++) {
        t_shirt_set += t_shirts_num[i] / T;
        if (t_shirts_num[i] % T) {
            t_shirt_set += 1;
        }
    }
    pencil_set = N / P;
    pencil_one = N % P;

    cout << t_shirt_set << '\n';
    cout << pencil_set << ' ' << pencil_one << '\n';

    return 0;
}