txt = input("Enter a txt : ")

size = len(txt)
mod = 3

enc = ""

for i in txt:
    enc += txt[(txt.find(i) + mod) % mod]

print(enc)

# incomplete progm
