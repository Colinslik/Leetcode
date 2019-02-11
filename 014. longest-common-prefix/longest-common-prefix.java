class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefix = (strs.length >= 1)? strs[0]: "";
        for (int i = 1; i < strs.length; i++) {
//            System.out.println(prefix.substring(0, prefix.length()));
            for (int j = 1; j <= prefix.length(); j++) {
//                System.out.println(strs[i].indexOf(prefix.substring(0, j), 0));
                if (strs[i].indexOf(prefix.substring(0, j), 0) != 0) {
                    prefix = prefix.substring(0, j-1);
                }
            }
        }
        return prefix;
    }
}
