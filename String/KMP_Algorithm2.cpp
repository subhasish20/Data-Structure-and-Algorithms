#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// Function to build LPS (Longest Prefix-Suffix) array
// LPS[i] = length of longest proper prefix of pattern[0..i]
//          which is also a suffix of pattern[0..i]
// ------------------------------------------------------------
void computeLPS(const string &pat, vector<int> &lps) {
    int m = pat.size();
    int len = 0;         // length of previous longest prefix-suffix
    lps[0] = 0;          // first value always 0 (single char can't repeat)
    int i = 1;           // start from second character

    while (i < m) {

        //  Case 1: Characters match — extend prefix-suffix
        if (pat[i] == pat[len]) {
            len++;              // increase match length
            lps[i] = len;       // store LPS length at this position
            i++;                // move next
        } 
        
        else { // mismatch happened

            // mismatch but we have previous matched prefix to fallback to
            if (len != 0) {
                // go to previous best prefix length
                len = lps[len - 1];
                // (do not increment i — retry match with smaller prefix)
            } 
            else {
                // no match & no prefix → LPS = 0
                lps[i] = 0;
                i++;   // move to next character
            }
        }
    }
}

// ------------------------------------------------------------
// KMP Pattern Search
// Avoids re-checking characters by using LPS array
// ------------------------------------------------------------
void KMPsearch(const string &text, const string &pat) {
    int n = text.size();
    int m = pat.size();

    vector<int> lps(m);
    computeLPS(pat, lps);    // Preprocess the pattern

    int i = 0;   // index in text
    int j = 0;   // index in pattern

    while (i < n) {

        //  Case 1: Characters match → move forward
        if (text[i] == pat[j]) {
            i++;  // move text pointer
            j++;  // move pattern pointer

            // 🎯 If full pattern matched
            if (j == m) {
                cout << "Pattern found at index " << (i - j) << endl;

                // continue searching using previous LPS value
                j = lps[j - 1];
            }
        } 
        
        else { // mismatch

            // mismatch after some matches → use LPS jump
            if (j != 0)
                j = lps[j - 1];   // move pattern pointer smartly
            else
                i++;             // no match at all → move text pointer
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    KMPsearch(text, pattern);

    return 0;
}
