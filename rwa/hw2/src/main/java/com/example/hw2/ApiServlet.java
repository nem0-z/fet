package com.example.hw2;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "ApiServlet", value = "/api/*")
public class ApiServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        final String contextPath = getServletContext().getContextPath();
        final String voteURI = contextPath + "/api/vote";

        if (request.getRequestURI().equals(voteURI)) {
            int winner = Integer.parseInt(request.getParameter("winner"));
            int loser = Integer.parseInt(request.getParameter("loser"));

            DBService.incrementPositiveVotes(winner);
            DBService.incrementTotalVotes(winner);
            DBService.incrementTotalVotes(loser);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
