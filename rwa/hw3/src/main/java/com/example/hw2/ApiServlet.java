package com.example.hw2;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityTransaction;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.Arrays;
import java.util.Map;

import static com.example.hw2.DBService.entityManagerFactory;

@WebServlet(name = "ApiServlet", value = "/api/*")
public class ApiServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        final String contextPath = getServletContext().getContextPath();
        final String voteURI = contextPath + "/api/vote";
        final String videoEditURI = contextPath + "/api/video_edit";
        final String videoDeleteURI = contextPath + "/api/video_delete";
        final String usersEditURI = contextPath + "/api/users_edit";
        final String usersDeleteURI = contextPath + "/api/users_delete";
        final String logoutURI = contextPath + "/api/logout";

        String requestURI = request.getRequestURI();
        if (requestURI.equals(voteURI)) {
            int winner = Integer.parseInt(request.getParameter("winner"));
            int loser = Integer.parseInt(request.getParameter("loser"));
            DBService.incrementPositiveAndTotalVotes(winner);
            DBService.incrementTotalVotes(loser);
        } else if (requestURI.equals(videoEditURI)) {
            String id = request.getParameter("id");
            DBService.editVideo((id == null || Integer.parseInt(id) == 0), request.getParameterMap());
            request.getRequestDispatcher("/videos.jsp").forward(request, response);
        } else if (requestURI.equals(videoDeleteURI)) {
            DBService.deleteVideo(Integer.parseInt(request.getParameter("id")));
            request.getRequestDispatcher("/videos.jsp").forward(request, response);
        } else if (requestURI.equals(logoutURI)) {
            request.getSession().removeAttribute("username");
            request.getSession().removeAttribute("userrole");
            request.getRequestDispatcher("/index.jsp").forward(request, response);
        } else if (requestURI.equals(usersEditURI)) {
            String id = request.getParameter("id");
            DBService.editUser((id == null || Integer.parseInt(id) == 0), request.getParameterMap());
            request.getRequestDispatcher("/users.jsp").forward(request, response);
        } else if (requestURI.equals(usersDeleteURI)) {
            String id = request.getParameter("id");
            String current = (String) request.getSession().getAttribute("username");
            UsersModel user = DBService.getUser(Integer.parseInt(id));
            if (current != null && user != null && current.equals(user.getName())) {
                request.getSession().removeAttribute("username");
                request.getSession().removeAttribute("userrole");
            }

            DBService.deleteUser(Integer.parseInt(request.getParameter("id")));
            request.getRequestDispatcher("/users.jsp").forward(request, response);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
