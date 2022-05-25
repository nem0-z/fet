package com.example.hw2;

import java.util.concurrent.ThreadLocalRandom;

public class Helper {
    public static int generateRandomInt(int max) {
        return ThreadLocalRandom.current().nextInt(0, max);
    }
}
