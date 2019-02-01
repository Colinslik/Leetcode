class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        strnum = list(bin(num))
        sum = 0
        for idx, val in enumerate(reversed(strnum)):
            if val == '0':
#                print(idx, val)
                sum += 2**idx
            elif val == 'b':
#                print(idx, val)
                break
        return sum
