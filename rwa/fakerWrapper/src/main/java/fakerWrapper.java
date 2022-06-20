import com.github.javafaker.Faker;

import java.sql.*;
import java.util.ArrayList;

public class fakerWrapper {
    public static void main(String[] args) throws SQLException {
        Faker faker = new Faker();
        ArrayList<String> videos = new ArrayList<>();
        videos.add("GgkASKg4fcE");
        videos.add("qb9craaTuPI");
        videos.add("wiMcIXihIlU");
        videos.add("5FnCqdGsnB4");
        videos.add("uJThEnfd_Xo");
        videos.add("TSHEgUGw5rU");
        videos.add("vYwlo0gYF80");
        videos.add("yO5KCAgcQ-w");
        videos.add("hghcx29R0UY");
        videos.add("s5vNM-8sDhk");
        Connection connection = DriverManager.getConnection("jdbc:mariadb://localhost:3306/rwa_hw?user=zlatan&password=test123");

        for (int i = 1; i <= 25; i++) {
            PreparedStatement preparedStatement = connection.prepareStatement("INSERT INTO rwa_hw.VIDEOS values (?,?,?,?,?,?,?,?)");
            int totalVotes = faker.number().numberBetween(15, 30);
            int positiveVotes = faker.number().numberBetween(5, 15);
            double rank = ciLowerBound(positiveVotes, totalVotes);
            preparedStatement.setInt(1, i);
            preparedStatement.setString(2, faker.artist().name() + "-" + i);
            preparedStatement.setString(3, faker.lorem().sentence());
            preparedStatement.setString(4, videos.get(i % 10));
            preparedStatement.setString(5, "");
            preparedStatement.setInt(6, totalVotes);
            preparedStatement.setInt(7, positiveVotes);
            preparedStatement.setDouble(8, rank);
            preparedStatement.executeUpdate();
        }
    }

    private static double ciLowerBound(double positiveVotes, double totalVotes) {
        if (totalVotes == 0) {
            return 0.;
        }

        double z = 1.96;
        double phat = positiveVotes / totalVotes;
        return (phat + z*z/(2*totalVotes) - z * Math.sqrt((phat * (1-phat) + z*z/(4*totalVotes))/totalVotes))/(1+z*z/totalVotes);
    }
}
