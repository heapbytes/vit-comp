def xor(a, b):
    ans = [str(int(i) ^ int(j)) for i, j in zip(a, b)]
    return ''.join(ans)

def bindiv(txt, div, ans):
    que = txt + '0' * (len(div) -1)
    curr = 0

    while(curr != len(que)):
        ans = ans.lstrip('0')
        while(len(ans) != len(div) and curr != len(que)):
            ans += que[curr]
            curr += 1
        print("xoring : ", ans, " with : ", div, " and curr value : ", curr )
        
        if(len(ans) == len(div)):
            ans = xor(div, ans)
        else:
            ans = '0' * ((len(div)-1) - len(ans)) + ans
        #print("and ans is : ", ans, "\n")

    print("que : ", que)
    print("ans : ", ans)
    return que[:-len(div)-1] + ans


txt = "1010101010"
div = "11001"
size = len(div)

ans = ''

print(bindiv(txt, div, ans))

