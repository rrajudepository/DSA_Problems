for t in range(int(input())):
    S = input().strip()
    N = len(S)
    
    A = []
    i = 0
    while i<N:
        j = i+1
        while j<N and S[i]==S[j]:
            j += 1
        A.append(j-i)
        i = j
        
    if len(A)>1 and S[0]==S[-1]:
        A[0] += A[-1]
        A.pop()
    
    B = max(A)
    if len(A)==1:
        ans = 1 if B==1 else B-1
    else:
        if B==1:
            ans = 2 if len(A)==2 else 3
        elif B==2:
            ans = 2 if 1 in A else 3
        else:
            A_copy = A[:]
            A_copy.remove(B)
            B1 = max(A_copy)
            ans = max(B//2, B1)
        
    print('Case {}: {}'.format(t+1, ans))
    