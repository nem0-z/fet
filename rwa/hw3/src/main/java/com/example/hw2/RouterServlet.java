package com.example.hw2;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "RouterServlet", value = "/routes/*")
public class RouterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        final String contextPath = getServletContext().getContextPath();
        final String indexURI = contextPath + "/routes/home";
        final String rankingsURI = contextPath + "/routes/rankings";
        final String usersURI = contextPath + "/routes/users";
        final String videosURI = contextPath + "/routes/videos";
        final String usersEditURI = contextPath + "/routes/users_edit";
        final String videosEditURI = contextPath + "/routes/video_edit";
        final String requestURI = request.getRequestURI();
        String route = "";

        if (requestURI.equals(indexURI)) {
            route = "/index.jsp";
        } else if (requestURI.equals(rankingsURI)) {
            route = "/rankings.jsp";
        } else if (requestURI.equals(usersURI)) {
            route = "/protected/users.jsp";
        } else if (requestURI.equals(videosURI)) {
            route = "/protected/videos.jsp";
        } else if (requestURI.equals(usersEditURI)) {
            route = "/protected/users_edit.jsp";
        } else if (requestURI.equals(videosEditURI)) {
            route = "/protected/video_edit.jsp";
        } else {
            request.setAttribute("path", request.getRequestURI());
            route = "/unknown.jsp";
        }

        RequestDispatcher requestDispatcher = request.getRequestDispatcher(route);
        requestDispatcher.forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
