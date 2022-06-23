<%@ page import="com.example.hw2.DBService" %>
<%@ page import="com.example.hw2.UsersModel" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>Edit User</title>
  <link rel="stylesheet" href="${pageContext.request.contextPath}/styles/main.css">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
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
  <div class="header-right">
    <a class="active" href="${pageContext.request.contextPath}/routes/home">Home</a>
    <a href="${pageContext.request.contextPath}/routes/rankings">Rankings</a>
    <%
      if (request.getSession().getAttribute("username") != null) {
    %>
    <a href="${pageContext.request.contextPath}/admin/videos">Videos</a>
    <a href="${pageContext.request.contextPath}/admin/users">Users</a>
    <%
      }
    %>
  </div>
</div>
<body>
<%
  UsersModel um = null;
  String reqId = request.getParameter("id");
  if (reqId != null) {
    um = DBService.getUser(Integer.parseInt(reqId));
  }

  String name = (um == null ? "" : um.getName());
  String password = (um == null ? "" : um.getPasswod());
  String urole = (um == null ? "" : um.getRole());
  int id = (um == null ? 0 : um.getId());
%>
<form action="${pageContext.request.contextPath}/api/users_edit" method="post" class="myform">
  <label for="name">Name:</label>
  <input name="name" id="name" type="text" value="<%= name %>" required><br>

  <label for="password">Password:</label>
  <input name="password" id="password" type="password" value="<%= password %>" required><br>

  <label for="roles">Role:</label>
  <select name="roles" id="roles" style="margin: 1em">
    <option value="admin">Admin</option>
    <option value="hamal">Hamal</option>
  </select><br>

  <input name="id" id="id" type="hidden" value="<%= id %>">

  <input type="submit" value="SUBMIT" class="submit">
</form>
</body>
</html>
