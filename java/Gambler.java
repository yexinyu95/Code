public class Gambler {
    public static void main(String[] args) {
        //input variables
        int stake  = Integer.parseInt(args[0]);
        int goal   = Integer.parseInt(args[1]);
        int trials = Integer.parseInt(args[2]);
        
        //default variables
        int bets = 0;
        int wins = 0;

        for (int t = 0; t < trials; t++)
        {
            int cash = stake;
            while (cash > 0 && cash < goal)
            {
                bets++;
                if (Math.random() < 0.5) cash++;
                else                     cash--;
            }
            if (cash == goal) wins++;
        }

        //output result variables
        System.out.println(100 * wins / trials + "%wins");
        System.out.println("Avg # bets" + bets / trials);

    }
}
