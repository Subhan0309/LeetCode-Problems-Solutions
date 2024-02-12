class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if ord(target) > ord(letters[len(letters) - 1]):
            return letters[0] 
        left = 0
        right = len(letters) - 1
        letters = ''.join(letters)
        while left <= right:
            mid = left + ((right - left) // 2)
            if ord(target) > ord(letters[mid]):
                if ord(letters[mid+1]) > ord(target):
                    return letters[mid+1]
                left = mid + 1
            elif ord(target) < ord(letters[mid]):
                if ord(target) > ord(letters[mid-1]):
                    return letters[mid]
                right = mid - 1
            else:
                if mid+1 >= len(letters):
                    return letters[0]
                if letters[mid] != letters[mid+1]:
                    return letters[mid+1]
                left = mid + 1        
        return letters[0]