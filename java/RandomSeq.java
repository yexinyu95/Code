public class RandomSeq
{
    /**
    receive N, lo and hi from command line(seperate by enter)
    and print N random numbers between lo and hi,
    */   
    public static void RandomNum() 
    
    {
        int N = StdIn.readInt();
        double lo = StdIn.readDouble();
        double hi = StdIn.readDouble();

        for (int i = 0; i < N; i++)
        {
            double x = StdRandom.uniformDouble(lo, hi);
            StdOut.printf("%2f\n", x);
        }

    }
    
    public static void main(String[] args) {
        RandomNum();
    }
}