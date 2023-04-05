public class sqrt {
    public static void main(String[] args) {
        double n = Double.parseDouble(args[0]);
        double ER = 1e-15;
        double t = n;
        while (Math.abs(t - n/t) > ER * t)
        {
            t = (n/t + t) / 2.0;
        }
        System.out.println(t);
    }
}
