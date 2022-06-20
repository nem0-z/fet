<%@ page import="com.example.hw2.DBService" %>
<%@ page import="com.example.hw2.VideoModel" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Edit Video</title>
</head>
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
<form action="${pageContext.request.contextPath}/api/video_edit" method="post">
    <label for="title">Title:</label>
    <input name="title" id="title" type="text" value="<%= title %>" required><br>

    <label for="desc">Description:</label>
    <input name="desc" id="desc" type="text" value="<%= desc %>" required><br>

    <label for="embedurl">Embed url:</label>
    <input name="embedurl" id="embedurl" type="text" value="<%= embedUrl %>" required><br>

    <label for="imageurl">(Alternative) Image url:</label>
    <input name="imageurl" id="imageurl" type="text" value="<%= imgUrl %>"><br>

    <input name="id" id="id" type="hidden" value="<%= id %>">
    <input type="submit" value="submit">
</form>
</body>
</html>
