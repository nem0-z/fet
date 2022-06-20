<%@ page import="com.example.hw2.DBService" %>
<%@ page import="com.example.hw2.VideoModel" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Edit Video</title>
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
    <%--  <a href="${pageContext.request.contextPath}">Video voting competition</a>--%>
    <div class="header-right">
        <a class="active" href="${pageContext.request.contextPath}/routes/home">Home</a>
        <a href="${pageContext.request.contextPath}/routes/rankings">Rankings</a>
        <a href="#">Share</a>
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
    VideoModel vm = null;
    String reqId = request.getParameter("id");
    if (reqId != null) {
        vm = DBService.getVideo(Integer.parseInt(reqId));
    }

    String title = (vm == null ? "" : vm.getTitle());
    String desc = (vm == null ? "" : vm.getDescription());
    String embedUrl = (vm == null ? "" : vm.getEmbedUrl());
    String imgUrl = (vm == null ? "" : vm.getImgUrl());
    int id = (vm == null ? 0 : vm.getId());
%>
<form action="${pageContext.request.contextPath}/api/video_edit" method="post" class="myform">
    <label for="title">Title:</label>
    <input name="title" id="title" type="text" value="<%= title %>" required><br>

    <label for="desc">Description:</label>
    <input name="desc" id="desc" type="text" value="<%= desc %>" required><br>

    <label for="embedurl">Embed url:</label>
    <input name="embedurl" id="embedurl" type="text" value="<%= embedUrl %>" required><br>

    <label for="imageurl">(Alternative) Image url:</label>
    <input name="imageurl" id="imageurl" type="text" value="<%= imgUrl %>"><br>

    <input name="id" id="id" type="hidden" value="<%= id %>">
    <input type="submit" value="SUBMIT" class="submit">
</form>
</body>
</html>
