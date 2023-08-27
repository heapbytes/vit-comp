from math import gcd

def inverse_mod(e, phi):

    i = 1
    j = 1

    while((i * e) - (j * phi) != 1):

        if((i * e) > (j * phi)):
            j += 1
        else:
            i += 1
    
    return i
    #print(i)

def gen_keys(p ,q):

    n = p * q
    phi = (p-1) * (q-1)
    
    e = 0
    for i in range(2, phi):
        if gcd(phi, i) == 1:
            e = i
            break
    
    assert(e < phi)

    d = pow(e, -1, phi)

    return n, e, phi, d


p = int(input("Enter 1st prime number : "))
q = int(input("Enter 2nd prime number : "))

n, e, phi, d = gen_keys(p, q)

print("\n------PUBLIC KEY------")
print("n = ", n)
print("e = ", e)

print("\n------PRIVATE KEY-----")
print("phi = ", phi)
print("d = ", d)

msg = input("\n\nEnter a plaintext : ").encode()
convert = '0x'
for i in msg:
  convert += hex(i)[2:]

fin = int(convert,16)

print("\n----ENCRYPTION-----")
cipher = pow(fin, e , n)
print("Encrypted value : ", cipher)

print("\n----DECRYPTION-----")
txt = pow(cipher, d, n)
msg_txt = hex(txt)[2:]
print(bytes.fromhex(msg_txt))





