char** letterCombinations(char* digits, int* returnSize) {
    int n = strlen(digits);
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    const char* map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


    int total = 1;
    for (int i = 0; i < n; i++) {
        total *= strlen(map[digits[i] - '0']);
    }

    char** res = (char**)malloc(total * sizeof(char*));
    for (int i = 0; i < total; i++) {
        res[i] = (char*)malloc(n + 1);
        res[i][n] = '\0';
    }

    // fill column by column
    int repeat = total;
    for (int pos = 0; pos < n; pos++) {
        const char* letters = map[digits[pos] - '0'];
        int len = strlen(letters);
        repeat /= len;

        for (int i = 0; i < total; i++) {
            res[i][pos] = letters[(i / repeat) % len];
        }
    }

    *returnSize = total;
    return res;
}