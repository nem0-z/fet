package com.example.hw2;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "LoginServlet", value = "/login")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        UsersModel user = DBService.getUser(username, password);
        HttpSession session = request.getSession();
        if (user != null) {
            session.setAttribute("username", username);
            session.setAttribute("userrole", user.getRole());
            response.sendRedirect(request.getContextPath() + "/index.jsp");
        } else {
            if (username != null && password != null) {
                request.setAttribute("loginstatus", "fail");
            }

            request.getRequestDispatcher("/login.jsp").forward(request, response);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
