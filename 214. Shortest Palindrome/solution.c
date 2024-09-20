// Function to reverse a string
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    
    // Create a reversed version of the string
    char rev[len + 1];
    strcpy(rev, s);
    reverse(rev);

    // Create the concatenated string "s#rev"
    char tmp[2 * len + 2];  // length of s + # + length of rev + null terminator
    snprintf(tmp, sizeof(tmp), "%s#%s", s, rev);

    int n = strlen(tmp);

    // building lookup table (lps[] longest proper suffix) using KMP algorithm
    int lps[n];
    int index = 0;
    lps[0] = 0;

    for (int i = 1; i < n; i++) {
        if (tmp[i] == tmp[index]) {
            lps[i] = lps[i - 1] + 1;
            index++;
        } else {
            index = lps[i - 1];
            while (index > 0 && tmp[index] != tmp[i]) {
                index = lps[index - 1];
            }
            if (tmp[index] == tmp[i]) {
                index++;
            }
            lps[i] = index;
        }
    }

    int pos = lps[n - 1];
    
    // Calculate the string to prepend
    int res_len = len - pos;
    char* res = (char*)malloc(res_len + len + 1);  // allocate memory for the result
    
    // Copy the part of the string to prepend in reverse
    for (int i = 0; i < res_len; i++) {
        res[i] = s[len - 1 - i];
    }
    
    // Append the original string
    strcpy(res + res_len, s);

    return res;
}