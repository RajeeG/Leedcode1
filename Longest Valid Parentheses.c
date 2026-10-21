#include <string.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);
    int open = 0, close = 0, best = 0;

    // Left -> Right
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') open++;
        else close++;

        if (open == close) {
            if (2 * close > best) best = 2 * close;
        } else if (close > open) {
            open = 0;
            close = 0;
        }
    }

    // Right -> Left
    open = 0;
    close = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') open++;
        else close++;

        if (open == close) {
            if (2 * open > best) best = 2 * open;
        } else if (open > close) {
            open = 0;
            close = 0;
        }
    }

    return best;
}