package com.example.hw2;

import jakarta.persistence.*;

import javax.xml.crypto.dsig.spec.ExcC14NParameterSpec;
import java.util.ArrayList;
import java.util.List;

public class DBService {
    private static final EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("default");

    public static ArrayList<VideoModel> getRandomVideos(int count) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();

        final int rowsCount = (int) getRowsCount();
        ArrayList<VideoModel> videos = new ArrayList<>();
        int generatedID = 0;
        try {
            entityTransaction.begin();
            for (int i = 0; i < count; i++) {
                generatedID = Helper.generateRandomInt(rowsCount, generatedID);
                videos.add(entityManager.find(VideoModel.class, generatedID));
            }
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
            System.out.println(e.getMessage());
        }

        return videos;
    }

    public static ArrayList<VideoModel> getTopFiveVideos() {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        ArrayList<VideoModel> videos = null;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT v FROM VideoModel v ORDER BY v.rank DESC").setMaxResults(5);
            videos = new ArrayList<VideoModel>(query.getResultList());
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
            System.out.println(e.getMessage());
        }

        return videos;
    }

    public static void incrementPositiveAndTotalVotes(int id) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        try {
            entityTransaction.begin();
            VideoModel vm = entityManager.getReference(VideoModel.class, id);
            vm.setPositiveVotes(vm.getPositiveVotes() + 1);
            vm.setTotalVotes(vm.getTotalVotes() + 1);
            vm.setRank(Helper.ciLowerBound(vm.getPositiveVotes(), vm.getTotalVotes()));
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }
    }

    public static void incrementTotalVotes(int id) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        try {
            entityTransaction.begin();
            VideoModel vm = entityManager.getReference(VideoModel.class, id);
            vm.setTotalVotes(vm.getTotalVotes() + 1);
            vm.setRank(Helper.ciLowerBound(vm.getPositiveVotes(), vm.getTotalVotes()));
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }
    }

    private static long getRowsCount() {
        long rows = 0;
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT COUNT(v) FROM VideoModel v");
            rows = (long) query.getSingleResult();
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
            System.out.println(e.getMessage());
        }

        return rows;
    }
}
