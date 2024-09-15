#define MAX_LEN 32

int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int findTheLongestSubstring(char* s) {
    int n = strlen(s), mask = 0, res = 0;
    int index[MAX_LEN];
    for (int i = 0; i < MAX_LEN; i++) {
        index[i] = -1;
    }
    index[0] = -1;

    int position[256] = {0};
    position['a'] = 0;
    position['e'] = 1;
    position['i'] = 2;
    position['o'] = 3;
    position['u'] = 4;

    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            mask ^= (1 << position[(int)s[i]]);
        }

        if (mask != 0 && index[mask] == -1) {
            index[mask] = i;
        }

        res = res > (i - index[mask]) ? res : (i - index[mask]);
    }

    return res;
}