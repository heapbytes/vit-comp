#include <stdio.h>
#include <string.h>

// Function to perform the RotNib operation
void rotnib(char* w) {
    char ans[8];
    for (int i = 0; i < 8; i++) {
        ans[i] = w[(i + 4) % 8];
    }
    strncpy(w, ans, 8);
}

// Function to perform the SubNib operation
void subnib(char* w, int length) {
    char subnib_dict[16][5] = {
        "0000", "1001", "0100", "1010",
        "1011", "1101", "0001", "1000",
        "0101", "0110", "0010", "0000",
        "0011", "1100", "1110", "1111"
    };

    if (length == 8) {
        char ans[8];
        strncpy(ans, w, 4);
        strncpy(ans + 4, subnib_dict[atoi(w + 4)], 4);
        strncpy(w, ans, 8);
    } else if (length == 16) {
        int prev = 0;
        int curr = 4;
        while (curr <= length) {
            strncpy(w + prev, subnib_dict[atoi(w + prev)], 4);
            prev += 4;
            curr += 4;
        }
    }
}

// Function to perform the XOR operation
void xor(char* w1, char* w2, char* result) {
    for (int i = 0; i < 8; i++) {
        result[i] = (w1[i] - '0') ^ (w2[i] - '0') + '0';
    }
}

int main() {
    char w0[] = "01001010";
    char w1[] = "11110101";

    char k1[17];
    strcpy(k1, w0);
    strcat(k1, w1);

    char constant_w2[] = "10000000";

    char w2[9];
    xor(w0, constant_w2, w2);
    subnib(w2, 8);

    char w3[9];
    xor(w1, w2, w3);

    char constant_w4[] = "00110000";

    char w4[9];
    xor(w2, constant_w4, w4);
    subnib(w4, 8);

    char w5[9];
    xor(w4, w3, w5);

    char k2[17];
    strcpy(k2, w2);
    strcat(k2, w3);

    char k3[17];
    strcpy(k3, w4);
    strcat(k3, w5);

    // Add round key
    char plaintext[] = "1101011100101000";
    char ark1[17];
    xor(plaintext, k1, ark1);

    subnib(ark1, 16);

    printf("%s\n", ark1);

    return 0;
}

