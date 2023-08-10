def xor(a, b):
    ans = [str(int(i) ^ int(j)) for i, j in zip(a, b)]
    return ''.join(ans)

def bindiv(txt, div, flag, ans):
    que = txt + '0' * (len(div) -1)
    send = 0
    curr = 0

    while(curr != len(que)):
        ans = ans.lstrip('0')
        while(len(ans) != len(div) -1 and curr != len(que)):
            ans += que[curr]
            curr += 1
        print("xoring : ", ans, " with : ", div, " and curr value : ", curr )

        ans = xor(div, ans)
        print("and ans is : ", ans, "\n")


    return que[:-4] + ans


txt = "1010101010"
div = "11001"
size = len(div)
flag = 1
ans = ''

print(bindiv(txt, div, flag, ans))

