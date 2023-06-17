#include <iostream>
#include <cmath>
using namespace std;

//Khai báo 2 biến toàn cục
int q[100], n, dem=0;

bool KiemTraDatQuanHau(int r, int c);

void InBanCo();

void XuLi(int k);

int main() {
    cout << "Nhap so luong con hau: ";
    cin >> n;
    if (n < 4) {
        cout << "Khong the dat con hau tren ban co "<<n<<"x"<<n;
    }
    else {
        XuLi(1);
        cout << "So cach xep "<<n<<" con hau tren ban co la : " << dem;
    }
    return 0;
}

bool KiemTraDatQuanHau(int r, int c) {
    for (int i = 1; i <= r - 1; ++i) {
        if (q[i] == c || abs(q[i] - c) == abs(i - r)) {
            return false;
        }
    }
    return true;
}

void InBanCo() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (q[i] == j) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void XuLi(int k) {
    for (int i = 1; i <= n; ++i) {
        if (KiemTraDatQuanHau(k, i)) {
            q[k] = i;
            if (k == n) {
                InBanCo();
                dem++;
            }
            else {
                XuLi(k + 1);
            }
        }
    }
}
