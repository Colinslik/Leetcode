class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        c = x ^ y
        sum = 0
        while c != 0:
            sum += c%2
            c = int(c/2)
      #  print ("a:",bin(x)," b:",bin(y)," c:",bin(c)," sum",sum)
        return sum
