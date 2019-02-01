class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """    
        SDcheck = bool(1)
        SDnumber = []
        for i in range(left,right+1):
            int2str = str(i)
            for j in int2str:
                if int(j) == 0 or i%int(j) !=0:
                    SDcheck = bool(0)
                    break
            if SDcheck:
                SDnumber.append(i)
            else:
                SDcheck = bool(1)
        return SDnumber
