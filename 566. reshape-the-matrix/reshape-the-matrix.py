class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        output = []
        column = []
        if (int(len(nums[0])) * int(len(nums))) != (r * c):
            return nums
        else:
            for i in nums:
                for j in i:
   #                 print(j)
                    column.append(j)
   #                 print(column)
                    if len(column) == c:
   #                     print(column)
                        output.append(column)
                        column = []
            return output
