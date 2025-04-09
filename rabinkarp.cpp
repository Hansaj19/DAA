#include <stdio.h>
#include <stdlib.h>

#define PRIME 101  // A prime number for hashing

// Function to compute the hash value for a given string using pointers
long long compute_hash(const char *str, int len) {
    long long hash = 0;
    long long power = 1;
    for (int i = 0; i < len; i++) {
        hash += (*(str + i)) * power;
        power *= PRIME;
    }
    return hash;
}

// Function to find all occurrences of pattern in text using Rabin-Karp algorithm
void rabin_karp(const char *text, const char *pattern) {
    int text_len = 0, pattern_len = 0, found = 0;
    while (*(text + text_len) != '\0' && *(text + text_len) != '\n') text_len++;
    while (*(pattern + pattern_len) != '\0' && *(pattern + pattern_len) != '\n') pattern_len++;
    
    if (pattern_len > text_len) {
        printf("-1\n");
        return;
    }

    long long pattern_hash = compute_hash(pattern, pattern_len);
    long long text_hash = compute_hash(text, pattern_len);
    long long power = 1;
    for (int i = 1; i < pattern_len; i++) power *= PRIME; // Compute PRIME^(pattern_len-1)

    for (int i = 0; i <= text_len - pattern_len; i++) {
        if (pattern_hash == text_hash) {
            int match = 1;
            for (int j = 0; j < pattern_len; j++) {
                if (*(text + i + j) != *(pattern + j)) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("%d ", i);
                found = 1;
            }
        }
        if (i < text_len - pattern_len) {
            text_hash = (text_hash - (*(text + i))) / PRIME + (*(text + i + pattern_len)) * power;
        }
    }
    if (!found) {
        printf("-1\n");
    }
}

int main() {
    char text[1000];
    char pattern[100];

    // Taking input from user
    fgets(text, 1000, stdin);
    fgets(pattern, 100, stdin);
    
    rabin_karp(text, pattern);
    return 0;
}
