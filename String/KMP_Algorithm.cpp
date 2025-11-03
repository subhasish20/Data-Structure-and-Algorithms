#include <iostream>
#include <string>
using namespace std;

void computeLPS(string pat, int m, int lps[]) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string text, string pat) {
    int n = text.length();
    int m = pat.length();
    int lps[m];
    computeLPS(pat, m, lps);

    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pat[j]) {
            i++; j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text, pat;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pat;

    KMP(text, pat);
    return 0;
}
