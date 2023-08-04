public class Factors {
    public static void main(String[] args) {
        //input variable
        long n = Long.parseLong(args[0]);

        for (long factor = 2; factor <= n / factor; factor++)
        {
            while (n % factor == 0)
            {
                n /= factor;
                System.out.println(factor + " ");
            }
        }
        if (n > 1) System.out.print(n);
        System.out.println();

    
    }
}
