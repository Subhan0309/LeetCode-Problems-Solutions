# class Solution:
#     def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
#         def diff(curr,next):
#             count=sum(x!=y for x,y in zip(curr,next))
#             return count
        
#         visited=set(wordList)

#         if endWord not in visited:
#             return 0
#         q=deque([beginWord])

#         steps=1

#         while q:
#             size=len(q)
#             while size:
#                 curr=q.popleft()

#                 if curr == endWord:
#                     return steps

#                 if curr in visited:
#                     visited.discard(curr)

#                 for next in visited:
#                     if diff(curr,next)==1:
#                         q.append(next)                        
#                 size-=1
#             steps+=1

#         return 0

from collections import deque
from typing import List

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:

        def diff(curr, next):
            count = sum(x != y for x, y in zip(curr, next))
            return count

        visited = set(wordList)

        if endWord not in visited:
            return 0

        q = deque([beginWord])
        steps = 1

        while q:
            size = len(q)
            for _ in range(size):
                curr = q.popleft()

                if curr == endWord:
                    return steps

                if curr in visited:
                    visited.discard(curr)

                # Create a copy of the set before iterating over it
                for next_word in set(visited):
                    if diff(curr, next_word) == 1:
                        q.append(next_word)
                        visited.discard(next_word)

            steps += 1

        return 0
