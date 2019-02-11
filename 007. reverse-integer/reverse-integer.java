class Solution {
    public int reverse(int x) {
        int sum = 0;
        try {
            while (x != 0) {
//                System.out.println(sum + " " + (x % 10));
                sum = Math.addExact(Math.multiplyExact(sum, 10), (x % 10));
                x /= 10;
            }
        }
        catch (ArithmeticException ex) {
            return 0;
        }
        return sum;
    }
}
