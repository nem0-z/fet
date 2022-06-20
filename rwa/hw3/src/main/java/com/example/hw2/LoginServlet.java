package com.example.hw2;

import org.eclipse.persistence.sessions.Session;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "LoginServlet", value = "/login")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//        if (request.getSession().getAttribute("username") != null) {
//            request.getRequestDispatcher("/index.jsp").forward(request, response);
//        }

        String username = request.getParameter("username");
        String password = request.getParameter("password");
        UsersModel user = DBService.getUser(username, password);
        if (user != null) {
            request.getSession().setAttribute("username", username);
            System.out.println("setting user role for user : " + user.getName() + " " + user.getRole());
            request.getSession().setAttribute("userrole", user.getRole());
            request.getRequestDispatcher("/index.jsp").forward(request, response);
        } else {
            request.setAttribute("loginstatus", "fail");
            request.getRequestDispatcher("/login.jsp").forward(request, response);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
