# 그리드 문제 : 최적해는 아닐수 있음 

def solution(people, limit):
    
    answer = 0 # 필요한 보트 수 
    
    people.sort() # 몸무게 오름차순 정렬
    
    start = 0 # 가장 가벼운 사람
    end = len(people)-1 # 가장 무거운 사람 
    
    
    while (start<=end):
        
        if (people[start]+people[end] <= limit): # 가벼움 + 무거운 사람이 한계 이하면
            start += 1 # 가벼운 사람 탑승
            end -= 1  # 무거운 사람 탑승 
            answer += 1 # 보트 추가

        else: # 무거운 사람 혼자 탑습
            end -= 1  # 무거운 사람 탑승
            answer += 1 # 보트 추가
        
    
    
    return answer


# 시간복잡도 O(n log n) > 정렬(sort) + while(O(n)) 