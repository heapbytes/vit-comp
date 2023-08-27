p = 151
q = 239

e = 31621
phi = (p-1) * (q-1)

i = 1
j = 1

while((i * e) - (j * phi) != 1):

    if((i * e) > (j * phi)):
        j += 1
    else:
        i += 1

print(i)

print(pow(e, -1, phi))
