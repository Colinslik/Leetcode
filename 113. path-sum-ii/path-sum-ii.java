/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<Integer> path =  new ArrayList();
        return  travelSum(root, path, 0, sum);
    }
    private List<List<Integer>> travelSum(TreeNode node, List<Integer> path, int currentSum, int sum)  {
        List<List<Integer>> result = new ArrayList();
        if(null == node) {
            return result;
        }
        path.add(node.val);
        if(null == node.left && null == node.right) {
            if(currentSum + node.val == sum) {
//                System.out.println("PATH: "+ path);
                result.add(path);
            }
            return result;
        }
        List<List<Integer>> left_ret, right_ret;
        if(null != node.left) {
            ArrayList leftpath = new ArrayList(path);
            left_ret = travelSum(node.left, leftpath, currentSum + node.val, sum);
            for (int i=0; i<left_ret.size(); i++) {
                result.add(left_ret.get(i));
            }
        }
        if(null != node.right) {
            ArrayList rightpath = new ArrayList(path);
            right_ret = travelSum(node.right, rightpath, currentSum + node.val, sum);
            for(int i=0; i<right_ret.size(); i++) {
                result.add(right_ret.get(i));
            }
        }
        
        
        return result;
    }
}
