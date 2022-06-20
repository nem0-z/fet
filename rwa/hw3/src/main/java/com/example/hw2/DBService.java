package com.example.hw2;

import jakarta.persistence.*;

import javax.servlet.http.HttpServletRequest;
import javax.xml.crypto.dsig.spec.ExcC14NParameterSpec;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DBService {
    public static final EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("default");

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

    public static long getRowsCount() {
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

    public static ArrayList<VideoModel> getVideosForRankingTable(int offset, int pageSize) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        ArrayList<VideoModel> videos = null;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT v FROM VideoModel v ORDER BY v.rank DESC")
                    .setMaxResults(pageSize)
                    .setFirstResult(pageSize * offset);
            videos = new ArrayList<VideoModel>(query.getResultList());
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return videos;
    }

    public static ArrayList<VideoModel> getVideosForRankingTableOrderedById(int offset, int pageSize) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        ArrayList<VideoModel> videos = null;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT v FROM VideoModel v ORDER BY v.id ASC")
                    .setMaxResults(pageSize)
                    .setFirstResult(pageSize * offset);
            videos = new ArrayList<VideoModel>(query.getResultList());
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return videos;
    }

    public static boolean userExists(String username, String password) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        boolean exists = false;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT u FROM UsersModel u WHERE u.name = :username AND u.passwod = :password");
            query.setParameter("username", username);
            query.setParameter("password", password);
            UsersModel user = (UsersModel) query.getSingleResult();
            System.out.println(user);
            if (user != null) {
                exists = true;
            }

            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return exists;
    }

    public static UsersModel getUser(String username, String password) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        UsersModel um = null;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT u FROM UsersModel u WHERE u.name = :username AND u.passwod = :password");
            query.setParameter("username", username);
            query.setParameter("password", password);
            um = (UsersModel) query.getSingleResult();
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return um;
    }

    public static VideoModel getVideo(int id) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        VideoModel vm = null;

        try {
            entityTransaction.begin();
            vm = entityManager.getReference(VideoModel.class, id);
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return vm;
    }

    public static void editVideo(boolean newVideo, Map<String, String[]> params) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        VideoModel vm = null;

        try {
            entityTransaction.begin();
            if (newVideo) {
                vm = new VideoModel();
                vm.setId((int) DBService.getRowsCount() + 1);
            } else {
                vm = entityManager.getReference(VideoModel.class, Integer.parseInt(params.get("id")[0]));
            }

            vm.setTitle(params.get("title")[0]);
            vm.setDescription(params.get("desc")[0]);
            vm.setEmbedUrl(params.get("embedurl")[0]);
            vm.setImgUrl(params.get("imageurl")[0]);
            if (newVideo) {
                entityManager.persist(vm);
            }

            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }
    }

    public static void deleteVideo(int id) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();

        try {
            entityTransaction.begin();
            VideoModel vm = entityManager.find(VideoModel.class, id);
            if (vm != null) {
                entityManager.remove(vm);
            }

            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }
    }
}
