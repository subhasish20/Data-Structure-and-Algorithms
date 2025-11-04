#include <stdio.h>
#include <string.h>

// ---------- compute LPS array ----------
void computeLPS(const char *pat, int m, int lps[]) {
    int len = 0;          // length of previous longest prefix–suffix
    lps[0] = 0;           // first element always 0
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];     // fallback
                // do not increment i here
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// ---------- KMP search ----------
void KMPsearch(const char *text, const char *pat) {
    int n = strlen(text);
    int m = strlen(pat);
    if (m == 0 || n == 0) {
        printf("Empty string or pattern — nothing to search.\n");
        return;
    }

    int lps[m];
    computeLPS(pat, m, lps);

    int i = 0;  // index in text
    int j = 0;  // index in pattern
    int found = 0;

    while (i < n) {
        // character match
        if (text[i] == pat[j]) {
            i++;
            j++;

            if (j == m) {  // full pattern matched
                printf("Pattern found at index %d\n", i - j);
                found = 1;
                j = lps[j - 1];  // continue searching for next match
            }
        }
        // mismatch
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        printf("Pattern not found in text.\n");
}

// ---------- main function ----------
int main(void) {
    char text[1000], pattern[1000];

    printf("Enter the text string  : ");
    scanf(" %[^\n]", text);      // read a line including spaces

    printf("Enter the pattern      : ");
    scanf(" %[^\n]", pattern);

    printf("\n--- Searching ---\n");
    KMPsearch(text, pattern);

    return 0;
}