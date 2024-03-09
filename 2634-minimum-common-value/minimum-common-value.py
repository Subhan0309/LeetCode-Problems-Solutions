class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        nums1=set(nums1)

       
        for val in nums2:
            if val in nums1:
               return val

        return -1