class Solution:
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum = 0
        for idx, val in enumerate(sorted(nums)):
#            print (val)
            if idx%2 == 0:
                sum += val
        return sum
