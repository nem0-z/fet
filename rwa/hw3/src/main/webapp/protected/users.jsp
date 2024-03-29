<%@ page import="com.example.hw2.DBService" %>
<%@ page import="com.example.hw2.Helper" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="com.example.hw2.UsersModel" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta charset="UTF-8">
    <title>Video voting competition</title>
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
    <div class="header-right">
        <a class="active" href="${pageContext.request.contextPath}/routes/home">Home</a>
        <a href="${pageContext.request.contextPath}/routes/rankings">Rankings</a>
        <a href="${pageContext.request.contextPath}/admin/videos">Videos</a>
        <a href="${pageContext.request.contextPath}/admin/users">Users</a>
    </div>
</div>
<div id="rankings">
    <p>Manage users</p>
    <div id="usersContainer">
        <button id="newuser">Add User</button>
        <div class="top5header">
            <p>ID</p>
            <p>Name</p>
            <p>Role</p>
        </div>
        <%
            final long rowsCount = DBService.getUsersCount();
            int rpage = Helper.getRpage(request);
            final double pageSize = 20;
            ArrayList<UsersModel> usersModels = DBService.getUsersOrderedById(rpage - 1, (int) pageSize);
            for (UsersModel um: usersModels) {
        %>
        <div class="top5row">
            <p class="headline"><%= um.getId() %></p>
            <p class="headline"><%= um.getName() %></p>
            <p class="headline"><%= um.getRole() %></p>
            <button id="manage-video-edit-btn" class="vote manage-video-btn">Edit</button>
            <button id="manage-video-delete-btn" class="vote manage-video-btn">Delete</button>
        </div>
        <%
            }
        %>
    </div>

    <%
        boolean moreForward = !((rpage * pageSize) >= rowsCount);
        boolean moreBack = rpage > 1;
    %>
    <div class="footer">
        <a href="${pageContext.request.contextPath}/routes/videos?rpage=<%= moreBack ? rpage-1 : rpage%>" <% if (!moreBack) out.print("style=\"pointer-events: none\""); %>>
            Back
        </a>
        <a href="${pageContext.request.contextPath}/routes/videos?rpage=<%= moreForward ? rpage+1 : rpage%>" <% if (!moreForward) out.print("style=\"pointer-events: none\""); %>>
            Next
        </a>
        <p>Page <%= rpage%> of <%= (int) Math.ceil(rowsCount / pageSize)%></p>
    </div>
</div>
<script type="text/javascript" src="${pageContext.request.contextPath}/js/users.js"></script>
</body>
</html>
