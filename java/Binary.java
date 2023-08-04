public class Binary {
    public static void main(String[] args) {
        // receive a input number
        int n = Integer.parseInt(args[0]);

        //find the nearest power of 2
        int power = 1;
        while (power <= n/2)
            power = 2 * power;

        //repeat
        while (power > 0)
        {
            if (n < power){System.out.print(0);}
            //subsruct n with the power of 2
            //repeat the same steps
            else          {System.out.print(1); n -= power;}
            power /= 2;
        }



        System.out.println();
    }
}
