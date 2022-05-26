package com.example.hw2;

import java.util.concurrent.ThreadLocalRandom;

import static java.util.concurrent.ThreadLocalRandom.current;

public class Helper {
    public static int generateRandomInt(int max, int previous) {
        int random = previous;
        while (random == previous) {
            random = ThreadLocalRandom.current().nextInt(1, max + 1);
        }

        return random;
    }
}
