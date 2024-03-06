class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
         # st holds all valid mutations
        st = set(bank)
        # if end mutation is not in the list, return -1
        if end not in st:
            return -1

        # start BFS by pushing the starting mutation
        Q = deque([start])
        steps = 0

        while Q:
            s = len(Q)
            while s > 0:
                cur = Q.popleft()
                # If we reach the end mutation
                if cur == end:
                    return steps
                # We remove the current mutation to avoid redundant checking
                st.discard(cur)
                # as the length of mutation is 8 and it can take A, C, G, T
                # at each index, we check the possibility of mutation by replacing it with A, C, G, T
                for i in range(8):
                    for nucleotide in ['A', 'C', 'G', 'T']:
                        t = cur[:i] + nucleotide + cur[i + 1:]
                        if t in st:
                            Q.append(t)
                s -= 1
            steps += 1

        return -1