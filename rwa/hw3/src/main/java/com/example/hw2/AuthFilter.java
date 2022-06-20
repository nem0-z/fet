package com.example.hw2;

import javax.servlet.*;
import javax.servlet.annotation.*;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;

@WebFilter(
        urlPatterns = "/admin/*",
        filterName = "AuthFilter"
)
public class AuthFilter implements Filter {
    public void init(FilterConfig config) throws ServletException {
    }

    public void destroy() {
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws ServletException, IOException {
//        HttpServletRequest httpServletRequest = (HttpServletRequest) request;
//        String currentUser = (String) httpServletRequest.getSession().getAttribute("username");
//        String currentUserRole = (String) httpServletRequest.getSession().getAttribute("userrole");
//        if (currentUser == null) {
//            //not logged in
//            httpServletRequest.getRequestDispatcher("/login.jsp").forward(request, response);
//        } else if (currentUserRole.equals("admin")) {
            chain.doFilter(request, response);
//        } else {
//            httpServletRequest.setAttribute("loginstatus", "hamal");
//            httpServletRequest.getRequestDispatcher("/login.jsp").include(request, response);
//        }
    }
}
