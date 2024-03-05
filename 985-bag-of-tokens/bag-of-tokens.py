class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        maxScore=-1
        score=0
        tokens.sort()

        left=0
        right=len(tokens)-1

        while(left<=right):

            if(tokens[left] <= power):
                power-=tokens[left]
                score+=1
                left+=1
                maxScore=max(maxScore,score)

            elif score>0:
                score-=1
                power+=tokens[right]
                right-=1
                maxScore=max(maxScore,score)

            else:
                break

        if maxScore == -1 :
            return  0 
        else:
            return maxScore   