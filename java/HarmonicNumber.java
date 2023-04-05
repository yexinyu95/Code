public class HarmonicNumber {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        double i = 1.0;
        double sum = 0;
        while (i <= n)
        {
            sum = sum + 1 / i;
            i = i + 1;
        }
        
        System.out.println(sum);
    }
}
