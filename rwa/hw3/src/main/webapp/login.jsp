<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Login</title>
</head>
<body>
<form action="${pageContext.request.contextPath}/login" method="post">
    <label for="username">Username:</label>
    <input name="username" id="username" type="text" placeholder="Your username" required><br>

    <label for="password">Password:</label>
    <input name="password" id="password" type="password" placeholder="Your password(max 20 characters)" required><br>

    <%
        String loginStatus = (String) request.getAttribute("loginstatus");
        if (loginStatus != null) {
            if (loginStatus.equals("fail")) {
    %>
        <p style="color: red;">Wrong credentials submitted.</p>
    <%      } else if (loginStatus.equals("hamal")) { %>
        <p style="color: red;">You have to be admin in order to access /admin pages.</p>
    <%      }
        }
    %>

    <input type="submit" value="Log In">
</form>
</body>
</html>
