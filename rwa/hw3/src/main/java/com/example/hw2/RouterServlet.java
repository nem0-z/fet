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
        final String requestURI = request.getRequestURI();
        String route = "";

        if (requestURI.equals(indexURI)) {
            route = "/index.jsp";
        } else if (requestURI.equals(rankingsURI)) {
            route = "/rankings.jsp";
        }

        RequestDispatcher requestDispatcher = request.getRequestDispatcher(route);
        requestDispatcher.forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
