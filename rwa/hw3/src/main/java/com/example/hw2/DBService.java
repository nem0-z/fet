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
        }

        return rows;
    }

    public static long getUsersCount() {
        long rows = 0;
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT COUNT(v) FROM UsersModel v");
            rows = (long) query.getSingleResult();
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
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


    public static ArrayList<UsersModel> getUsersOrderedById(int offset, int pageSize) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        ArrayList<UsersModel> users = null;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT u FROM UsersModel u ORDER BY u.id ASC")
                    .setMaxResults(pageSize)
                    .setFirstResult(pageSize * offset);
            users = new ArrayList<UsersModel>(query.getResultList());
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return users;
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

    public static UsersModel getUser(int id) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        UsersModel um = null;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT u FROM UsersModel u WHERE u.id = :id");
            query.setParameter("id", id);
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
                vm.setId(getLatestId() + 1);
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

    public static void editUser(boolean newUser, Map<String, String[]> params) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        UsersModel um = null;

        try {
            entityTransaction.begin();
            if (newUser) {
                um = new UsersModel();
                um.setId(getLatestUserId() + 1);
            } else {
                um = entityManager.getReference(UsersModel.class, Integer.parseInt(params.get("id")[0]));
            }

            um.setName(params.get("name")[0]);
            um.setPasswod(params.get("password")[0]);
            um.setRole(params.get("role")[0]);
            if (newUser) {
                entityManager.persist(um);
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

    public static void deleteUser(int id) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();

        try {
            entityTransaction.begin();
            UsersModel um = entityManager.find(UsersModel.class, id);
            if (um != null) {
                entityManager.remove(um);
            }

            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }
    }
    private static int getLatestId() {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        int id = 0;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT MAX(v.id) FROM VideoModel v");
            id = (int) query.getSingleResult();
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return id;
    }

    private static int getLatestUserId() {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        EntityTransaction entityTransaction = entityManager.getTransaction();
        int id = 0;

        try {
            entityTransaction.begin();
            Query query = entityManager.createQuery("SELECT MAX(u.id) FROM UsersModel u");
            id = (int) query.getSingleResult();
            entityTransaction.commit();
        } catch (Exception e) {
            entityTransaction.rollback();
        }

        return id;
    }
}
