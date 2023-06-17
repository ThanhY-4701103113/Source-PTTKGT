#include<iostream>
using namespace std;


int XuLi(int a[], int diemdau, int diemcuoi, int x) {
    int pivot = a[diemcuoi];
    int i = diemdau - 1;
    for (int j = diemdau; j <= diemcuoi - 1; j++) {
        if (a[j] < pivot && x == 1) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

        }
        if (a[j] > pivot && x == 0) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    swap(a[i + 1], a[diemcuoi]);
    return i + 1;
}

void quicksort(int a[], int diemdau, int diemcuoi , int x) {
    if (diemdau < diemcuoi) {
        int vitri = XuLi(a, diemdau, diemcuoi, x);
        quicksort(a, diemdau, vitri - 1, x);
        quicksort(a, vitri + 1, diemcuoi, x);
    }
}

int main() {
    int n;
    cout << "Nhap so luong cua mang: ";
    cin >> n;
    cout <<endl << "Nhap mang: ";
    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << endl << "Chon tang nhap 0, chon giam nhap 1: ";
    int x;
    cin >> x;
    cout << endl << "Ket qua: ";
    quicksort(a, 0, n - 1, x);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
