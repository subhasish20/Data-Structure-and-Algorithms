#include<iostream>
#include<string>
using namespace std;

#define d 256          // number of characters (ASCII)
#define q 101          // a prime for mod (reduces collision)

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int h = 1;
    int p = 0; // pattern hash
    int t = 0; // text window hash

    // h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Compute initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide over text
    for (int i = 0; i <= n - m; i++) {

        // If hash matches, check characters
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Compute next hash (rolling hash)
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + 1 + m - 1]) % q;

            if (t < 0) 
                t = t + q;  // make positive
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    rabinKarp(text, pattern);
    return 0;
}
