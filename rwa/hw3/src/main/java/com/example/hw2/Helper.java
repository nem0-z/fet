package com.example.hw2;

import javax.servlet.http.HttpServletRequest;
import java.util.concurrent.ThreadLocalRandom;


public class Helper {
    public static int generateRandomInt(int max, int previous) {
        int random = previous;
        while (random == previous) {
            random = ThreadLocalRandom.current().nextInt(1, max + 1);
        }

        return random;
    }

    public static double ciLowerBound(double positiveVotes, double totalVotes) {
        if (totalVotes == 0) {
            return 0.;
        }

        double z = 1.96;
        double phat = positiveVotes / totalVotes;
        return (phat + z*z/(2*totalVotes) - z * Math.sqrt((phat * (1-phat) + z*z/(4*totalVotes))/totalVotes))/(1+z*z/totalVotes);
    }

    public static int getRpage(HttpServletRequest request) {
        int rpage = 1;
        String rpageParam = request.getParameter("rpage");
        if (rpageParam != null) {
            rpage = Integer.parseInt(rpageParam);
            if (rpage < 0) {
                rpage = 1;
            }
        }

        return rpage;
    }
}
