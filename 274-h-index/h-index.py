class Solution:


    # def hIndex(self, citations: List[int]) -> int:
    #     citations.sort(reverse=True)

    #     common=sys.maxsize

    #     for i in range(len(citations)):

    #         if(citations[i]<common):
    #             common=citations[i]
            
    #         if (i + 1) >= common:
    #             return citations[i]

    #     if(common > len(citations)):
    #         return len(citations)


     def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)

        common=sys.maxsize
        #4 4 0 0
        #1 2 3 4

        common=0

        for i in range(len(citations)):
            if(citations[i]>common):
                common=i+1
        
        return common
          


        




        
