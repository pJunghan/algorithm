def solution(brown, yellow):
    answer = []
    
    all_color = brown + yellow
    print(all_color)
    
    u = sosu(all_color)

            
    for a, b in u:
         if yellow == (a-2) * (b-2):
                answer.append([a,b])
    
    
    return answer[0]


def sosu(n):

    sa = []
    for i in range(1,n+1):
        if n%i == 0:
            a = i
            b = n//i
            if a >= b :
                sa.append([a,b])
            
    return sa
            
    
    