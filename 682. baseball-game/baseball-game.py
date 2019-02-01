class Solution:
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        sum = 0
        my_ops = ops
        for idx, val in enumerate(my_ops):
            if val == 'C':
                for idx2 in range(idx, -1, -1):
                    if my_ops[idx2].lstrip('-').isdigit():
                        sum -= int(my_ops[idx2])
                        my_ops[idx2] = 'X'
                        break
            elif val == 'D':
                val2 = 0
                for idx2 in range(idx, -1, -1):
#                    print("idx2: ",idx2)
                    if my_ops[idx2].lstrip('-').isdigit():
                        val2 = int(my_ops[idx2]) * 2
 #                       print(val2)
                        my_ops[idx] = str(val2)
                        sum += val2
                        break
            elif val == '+':
                count = 0
                val2 = 0
                for idx2 in range(idx, -1, -1):
  #                  print("idx2: ",idx2)
                    if my_ops[idx2].lstrip('-').isdigit() and count<2:
 #                       print(my_ops[idx2])
                        val2 += int(my_ops[idx2])
                        count += 1
   #                     print("val2: ",val2)
                my_ops[idx] = str(val2)
                sum += val2
            else:
                sum += int(val)
#        print(my_ops)
        return sum
