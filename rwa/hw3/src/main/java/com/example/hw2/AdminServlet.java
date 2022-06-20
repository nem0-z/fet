package com.example.hw2;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "AdminServlet", value = "/admin/*")
public class AdminServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        final String contextPath = getServletContext().getContextPath();
        final String videos= contextPath + "/admin/videos";
        final String videosEdit = contextPath + "/admin/videos/edit";
        final String requestURI = request.getRequestURI();
        String route = "";

        if (requestURI.equals(videos)) {
            route = "/videos.jsp";
        } else if (requestURI.equals(videosEdit)) {
            route = "/api/video/edit";
        }

        RequestDispatcher requestDispatcher = request.getRequestDispatcher(route);
        requestDispatcher.forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
