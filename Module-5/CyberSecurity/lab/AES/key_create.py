
def rotnib(w):
    ans = [0 for i in range(8)]
    for i in range(8):
        ans[i] = w[(i + 4) % 8]

    return ''.join([i for i in ans])

def subnib(w):
    length = len(w)
    subnib_dict = {
        "0000": "1001",
        "0001": "0100",
        "0010": "1010",
        "0011": "1011",
        "0100": "1101",
        "0101": "0001",
        "0110": "1000",
        "0111": "0101",
        "1000": "0110",
        "1001": "0010",
        "1010": "0000",
        "1011": "0011",
        "1100": "1100",
        "1101": "1110",
        "1110": "1111",
        "1111": "0111"
    }

    if length == 8:
        ans = [0 for _ in range(8)]
        ans[:4] = subnib_dict[w[:4]]
        ans[4:] = subnib_dict[w[4:]]
        return ans

    if length == 16:
        ans = [0 for i in range(16)]

        ans[:4] = subnib_dict[w[:4]]
        ans[4:8] = subnib_dict[w[4:8]]
        ans[8:12] = subnib_dict[w[8:12]]
        ans[12:16] = subnib_dict[w[12:16]]

        return ''.join([ans[i] for i in range(16)])


def xor16(w1, w2):

    ans = [0 for i in range(16)]
    for i in range(len(ans)):
        ans[i] = int(w1[i]) ^ int(w2[i])

    return ''.join([str(i) for i in ans])

def xor(w1, w2):

    ans = [0 for i in range(8)]
    for i in range(len(ans)):
        ans[i] = int(w1[i]) ^ int(w2[i])

    return ''.join([str(i) for i in ans])

def swap_nib(ark):

    ans = [0 for _ in range(16)]
    ans = ark[0:4] + ark[12:16] + ark[8:12] + ark[4:8]
    return ans

def bit_4(val):
    constant = "10011"


def mix_column(Me, s):

    ans = [0 for _ in range(16)]
    for i in range(4):
        for j in range(4):
            ans[i * 4 + j] = Me[i] * s[j] + Me[i + 1] * s[j + 4] + Me[i + 2] * s[j + 8] + Me[i + 3] * s[j + 12]

    return ans

if __name__ == "__main__":


    w0 = "01001010"
    w1 = "11110101"

    k1 = w0 + w1

    constant_w2 = "10000000"

    w2 = xor(w0, xor(constant_w2, subnib(rotnib(w1))))
    w3 = xor(w1, w2)

    constant_w4 = "00110000"
    w4 = xor(w2, xor(constant_w4, subnib(rotnib(w3))))
    w5 = xor(w4, w3)

    k2 = w2 + w3
    k3 = w4 + w5

    #add round key
    plaintext = "1101011100101000"
    ark1 = xor16(plaintext, k1)

    ark1 = subnib(ark1)

    #swap 2nd and 4th nibble
    ark1_nib = swap_nib(ark1)
    #print(ark1)

    Me = [1, 4, 1, 4]
    s = ark1 

    mixAns = mix_column(Me, s)
    print(ark1) 



