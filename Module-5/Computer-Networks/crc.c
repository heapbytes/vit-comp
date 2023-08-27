#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *xor(char *a, char *b);
char *bindiv(char *txt, char *div, char *ans);

int main() {
    char *txt = "1010101010";
    char *div = "11001";
    int size = strlen(div);
    char *ans = malloc(size + 1);  // Allocate memory for ans
    strcpy(ans, "0");
    char *result = bindiv(txt, div, ans);
    printf("Result: %s\n", result);
    free(ans);  // Don't forget to free allocated memory
    return 0;
}

char *xor(char *a, char *b) {
    int len = strlen(a);
    char *ans = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        ans[i] = (a[i] == b[i]) ? '0' : '1';
    }
    ans[len] = '\0';
    return ans;
}

char *bindiv(char *txt, char *div, char *ans) {
    int txt_len = strlen(txt);
    int div_len = strlen(div);
    int ans_len = txt_len + div_len - 1;
    char *que = malloc(ans_len + 1);
    strcpy(que, txt);
    for (int i = txt_len; i < ans_len; i++) {
        que[i] = '0';
    }
    que[ans_len] = '\0';
    int curr = 0;
    while (curr != ans_len) {
        ans = xor(ans, que + curr);
        while (strlen(ans) != div_len && curr != ans_len) {
            ans = strcat(ans, que + curr);
            curr++;
        }
        if (strlen(ans) == div_len) {
            ans = xor(div, ans);
        } else {
            char padding[div_len - 1 - strlen(ans) + 1];
            memset(padding, '0', div_len - 1 - strlen(ans));
            padding[div_len - 1 - strlen(ans)] = '\0';
            ans = strcat(padding, ans);
        }
    }
    printf("que : %s\n", que);
    printf("ans : %s\n", ans);
    free(que); // Free allocated memory for que
    return ans + (txt_len - div_len + 1);
}

