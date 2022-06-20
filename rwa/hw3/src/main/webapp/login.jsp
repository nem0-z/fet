<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Login</title>
    <link rel="stylesheet" href="${pageContext.request.contextPath}/styles/main.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
<div class="header">
    <%
        String user = (String) request.getSession().getAttribute("username");
        String role = (String) request.getSession().getAttribute("userrole");
        if (user != null) {
    %>
    <a href="${pageContext.request.contextPath}/api/logout">LOG OUT (Logged in as: <%= user %> (<%= role %>))</a>
    <% } else { %>
    <a href="${pageContext.request.contextPath}/login.jsp">LOG IN</a>
    <% } %>
    <%--  <a href="${pageContext.request.contextPath}">Video voting competition</a>--%>
    <div class="header-right">
        <a class="active" href="${pageContext.request.contextPath}/routes/home">Home</a>
        <a href="${pageContext.request.contextPath}/routes/rankings">Rankings</a>
        <a href="#">Share</a>
        <%
            if (request.getSession().getAttribute("username") != null) {
        %>
        <a href="${pageContext.request.contextPath}/admin/videos">Videos</a>
        <%
            }
        %>
    </div>
</div>
<form action="${pageContext.request.contextPath}/login" method="post" class="myform">
    <label for="username">Username:</label>
    <input name="username" id="username" type="text" placeholder="Username" required><br>

    <label for="password">Password:</label>
    <input name="password" id="password" type="password" placeholder="Password(max 20 characters)" required><br>

    <%
        String loginStatus = (String) request.getAttribute("loginstatus");
        if (loginStatus != null) {
            if (loginStatus.equals("fail")) {
    %>
        <p style="color: red;">Wrong credentials submitted.</p>
    <%      } else if (loginStatus.equals("hamal")) { %>
        <p style="color: red;">You have to have admin right in order to access /admin pages.</p>
    <%      } else if (loginStatus.equals("needslogin")) { %>
        <p style="color: red;">You need to be logged in in order to view this page.</p>
    <%      }
        }
    %>

    <input type="submit" value="LOG IN" class="submit">
</form>
</body>
</html>
