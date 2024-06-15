#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void make_mat(string& p, char mt[][5]) {
    int m = ceil(p.length() / 5.0);
    while (p.length() < m * 5) {
        p += 'x';
    }
    int c = 0;
    for (int i = 0; i < m; ++i) {
        for (int x = 0; x < 5; ++x) {
            mt[i][x] = p[c];
            ++c;
        }
    }
}
string encrypt(string p, int s, int col) {
    int m = ceil(p.length() / col);
    char mt[m][5];
    make_mat(p, mt);
    string cipher = "";
    int c = 0, w = 1, n = m - 1, l = col - 1, mn = 0, ml = 0;
    while (c < p.length()) {
        if ((w % 4 == 1 && s == 1) || (w % 4 == 0 && s == 2) || (w % 4 == 3 && s == 3) || (w % 4 == 2 && s == 4)) {
            for (int i = mn; i <= n; ++i) {
                if (c < p.length()) {
                    cipher += mt[i][l];
                    ++c;
                }
            }
            --l;
        }
        else if ((w % 4 == 2 && s == 1) || (w % 4 == 1 && s == 2) || (w % 4 == 3 && s == 4) || (w % 4 == 0 && s == 3)) {
            for (int i = l; i >= ml; --i) {
                if (c < p.length()) {
                    cipher += mt[n][i];
                    ++c;
                }
            }
            --n;
        }
        else if ((w % 4 == 3 && s == 1) || (w % 4 == 2 && s == 2) || (w % 4 == 1 && s == 3) || (w % 4 == 0 && s == 0)) {
            for (int i = n; i >= mn; --i) {
                if (c < p.length()) {
                    cipher += mt[i][ml];
                    ++c;
                }
            }
            ++ml;
        }
        else if ((w % 4 == 0 && s == 1) || (w % 4 == 3 && s == 2) || (w % 4 == 2 && s == 3) || (w % 4 == 1 && s == 4)) {
            for (int i = ml; i <= l; ++i) {
                if (c < p.length()) {
                    cipher += mt[mn][i];
                    ++c;
                }
            }
            ++mn;
        }
        ++w;
    }
    return cipher;
}
string decrypt(string ci, int r, int s) {
    int u = ci.length() / r;
    char m[r][u];
    string plain = "";
    int c = 0, w = 1, n = r - 1, l = u - 1, mn = 0, ml = 0;
    while (c < ci.length()) {
        if ((w % 4 == 1 && s == 1) || (w % 4 == 0 && s == 2) || (w % 4 == 3 && s == 3) || (w % 4 == 2 && s == 4)) {
            for (int i = mn; i <= n; ++i) {
                if (c < ci.length()) {
                    m[i][l] = ci[c];
                    ++c;
                }
            }
            --l;
        }
        else if ((w % 4 == 2 && s == 1) || (w % 4 == 1 && s == 2) || (w % 4 == 3 && s == 4) || (w % 4 == 0 && s == 3)) {
            for (int i = l; i >= ml; --i) {
                if (c < ci.length()) {
                    m[n][i] = ci[c];
                    ++c;
                }
            }
            --n;
        }
        else if ((w % 4 == 3 && s == 1) || (w % 4 == 2 && s == 2) || (w % 4 == 1 && s == 3) || (w % 4 == 0 && s == 0)) {
            for (int i = n; i >= mn; --i) {
                if (c < ci.length()) {
                    m[i][ml] = ci[c];
                    ++c;
                }
            }
            ++ml;
        }
        else if ((w % 4 == 0 && s == 1) || (w % 4 == 3 && s == 2) || (w % 4 == 2 && s == 3) || (w % 4 == 1 && s == 4)) {
            for (int i = ml; i <= l; ++i) {
                if (c < ci.length()) {
                    m[mn][i] = ci[c];
                    ++c;
                }
            }
            ++mn;
        }
        ++w;
    }
    for (int i = 0; i < r; ++i) {
        for (int x = 0; x < u; ++x) {
            plain += m[i][x];
        }
    }
    return plain;
}
int main()
{
    int number;
    string input;
    int start, col;
    cout << "welcome to route cipher encription " << endl;
    cout << "for encryption please press 1 " << endl;
    cout << "for decryption please press 2 " << endl;
    cin >> number;
    if (number == 1) {
        cout << "enter your plaintext whithout spaces then enter number of colum\n";
        cin >> input >> col;
        cout << "if you want to encrypt from tr press 1,if from br press 2, if from bl press 3,iffrom tl press 4\n";
        cin >> start;
        cout << encrypt(input, start, col) << endl;
    }
    else {
        int r;
        cout << "enter your ciphertext whithout spaces,+enter the number if rows that have been used to encrypt note*(\"the ciphertext length should be divisible by r\") \n";
        cin >> input >> r;
        cout << "if the encryption was from tr press 1,if from br press 2, if from bl press 3,iffrom tl press 4\n";
        cin >> start;
        cout << decrypt(input, r, start) << endl;
    }
    return 0;
}