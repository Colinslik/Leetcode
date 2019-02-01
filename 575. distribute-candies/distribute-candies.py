class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        dic = {}
        for i in candies:
            if i in dic:
                dic[i] = dic.get(i)+1
            else:
                dic[i] = 1
        sorted_d = sorted(dic.items(), key=operator.itemgetter(0),reverse=False)
        
#        print(sorted_d[0][1],len(sorted_d),int(len(candies)/2))
        
        if int(sorted_d[0][1]) > len(sorted_d) or int(len(candies)/2) >= len(sorted_d):
            return len(sorted_d)
        else:
            return int(len(candies)/2)
