package com.example.vjezbe7;

import java.io.*;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet("/HelloServlet")
public class HelloServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    /**
     * @see HttpServlet#HttpServlet()
     */
    public HelloServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

    /**
     * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        response.setContentType("text/html");

        PrintWriter out = response.getWriter();

        String name = "";
        String colour = "";
        Cookie[] cookies = request.getCookies();
        for (Cookie c: cookies) {
            if (c.getName().equals("name")) {
                name = c.getValue();
            } else if (c.getName().equals("colour")) {
                colour = c.getValue();
            }
        }
        // get request cookies
        // check if there are relevant cookies set
        // if cookies have been set, display cookies content
        // else display form as per below

        if (!name.isEmpty() && !colour.isEmpty()) {
            out.println("<head><title>Hello cookie</title></head>");
            out.println("<body>");
            out.println("<p>Your name is: " + name + " </p>");
            out.println("<p>Your favorite colour is: " + colour + " </p>");
            out.println("</body>");
        } else {
            out.println("<head><title>Hello cookie</title></head>");
            out.println("<body>");
            out.println("<form action=\"/vjezbe7_war_exploded/HelloServlet\" method=\"post\">");
            out.println("Your name: <br/>");
            out.println("<input type=\"text\" name=\"name\"/><br/>");
            out.println("Favourite colour: <br/>");
            out.println("<input type=\"text\" name=\"colour\"/><br/>");
            out.println("<input type=\"submit\" value=\"Save\"/>");
            out.println("</form>");
            out.println("</body>");
        }
    }

    /**
     * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // read request parameters and set as response as cookies
        String name = request.getParameter("name");
        String colour = request.getParameter("colour");

        Cookie nameCookie = new Cookie("name", name);
        Cookie colourCookie = new Cookie("colour", colour);

        response.addCookie(nameCookie);
        response.addCookie(colourCookie);

        doGet(request, response);
    }

}