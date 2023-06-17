#include <iostream>
#include <string>
using namespace std;

void Nhap(string& s1, string& s2);
string ChuoiChungDaiNhat(string s1, string s2);
int main() {
    string s1, s2;
    Nhap(s1, s2);
    cout << "Chuoi chung dai nhat cua " << s1 << " va " << s2 << " la: " << ChuoiChungDaiNhat(s1, s2);
    return 0;
}
void Nhap(string& s1, string& s2) {
    cout << "Nhap chuoi s1: ";
    getline(cin, s1);
    cout << "Nhap chuoi s2: ";
    getline(cin, s2);
}

string ChuoiChungDaiNhat(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[100][100];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    // Xây dựng bảng DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    //kết quả
    int len = dp[m][n];
    //Khởi tạo kết quả:
    string result(len, ' ');
    int i = m, j = n;
    while (len > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result[len - 1] = s1[i - 1];
            i--;
            j--;
            len--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    return result;
}
