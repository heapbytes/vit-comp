#from string import ascii_letters
#alp = ascii_letters * 2
rot = 2

txt = input("Enter a text : ")
enc = ''

for i in txt:
    if(i == " "):
        enc += " "
    else:
        enc += chr(ord(i) + rot)

print(enc)

#bug : after z wont work, have to do with other algo : ):
