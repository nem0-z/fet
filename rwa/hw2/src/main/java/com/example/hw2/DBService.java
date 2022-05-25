package com.example.hw2;

import jakarta.persistence.*;

import java.util.ArrayList;

public class DBService {
    private static final EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("default");

    public static int getTotalVotes(int id) {
        int votes = 0;
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT v.totalVotes FROM VideoModel v");
            entityTransaction.commit();
            votes = query.getFirstResult();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return votes;
    }

    public static int getPositiveVotes(int id) {
        int votes = 0;
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT v.positiveVotes FROM VideoModel v");
            entityTransaction.commit();
            votes = query.getFirstResult();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return votes;
    }

    public static ArrayList<VideoModel> getRandomVideos(int count) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();

        final int rowsCount = getRowsCount();
        ArrayList<VideoModel> videos = new ArrayList<>();
        try {
            entityTransaction.begin();
            for (int i = 0; i < count; i++) {
                //this is not safe, since it can generate 'count' number of same ids
                int generatedID = Helper.generateRandomInt(rowsCount);
                Query query = entityManager.createQuery("SELECT v FROM VideoModel v WHERE v.id = " + generatedID);
                VideoModel vm = (VideoModel) query.getSingleResult();
                videos.add(vm);
            }
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return videos;
    }

    private static int getRowsCount() {
        int rows = 0;
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT COUNT(v) FROM VideoModel v");
            entityTransaction.commit();
            rows = query.getFirstResult();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return rows;
    }
}
