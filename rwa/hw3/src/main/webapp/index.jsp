<%@ page import="com.example.hw2.DBService" %>
<%@ page import="com.example.hw2.VideoModel" %>
<%@ page import="java.util.ArrayList" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html lang="en">
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
    <%--    <a class="title" href="${pageContext.request.contextPath}">Video voting competition</a>--%>
    <div class="header-right">
        <a class="active" href="${pageContext.request.contextPath}/routes/home">Home</a>
        <a href="${pageContext.request.contextPath}/routes/rankings">Rankings</a>
        <a id="shareBtn" href="#">Share</a>
        <%
            if (role != null && role.equals("admin")) {
        %>
        <a href="${pageContext.request.contextPath}/admin/videos">Videos</a>
        <a href="${pageContext.request.contextPath}/admin/users">Users</a>
        <%
            }
        %>
    </div>
</div>

<div class="voting">
    <%
        ArrayList<VideoModel> randomTwoVideos = DBService.getRandomVideos(2);
        int i = 0;
        for (VideoModel vm: randomTwoVideos) {
    %>
        <div class="video" style="float: <%= i == 0 ? "left" : "right"%>" id="<%= vm.getId()%>">
            <p><%= vm.getTitle() %></p>
            <iframe src="https://www.youtube.com/embed/<%= vm.getEmbedUrl() %>" frameborder="0"></iframe>
            <button class="vote" id="<%= i == 0 ? "voteFirst" : "voteSecond"%>">Vote</button>
        </div>
    <%
            i++;
        }
    %>
</div>

<div id="rankings">
    <p>Top 5 videos</p>
    <div id="rankingsContainer">
        <div class="top5header">
            <p></p>
            <p>Headline</p>
            <p>Votes(positive/total)</p>
            <p>Rank</p>
        </div>
        <%
            ArrayList<VideoModel> topFiveVideos = DBService.getTopFiveVideos();
            i = 1;
            for (VideoModel vm: topFiveVideos) {
                String imageUrl = vm.getImgUrl().isEmpty() ? "https://img.youtube.com/vi/" + vm.getEmbedUrl() + "/0.jpg" : vm.getImgUrl();
        %>
        <div class="top5row">
            <img src="<%= imageUrl %>" alt="Failed to load resource"></img>
            <p class="headline"><%= vm.getTitle() %></p>
            <p class="votes">(<%= vm.getPositiveVotes()%>/<%= vm.getTotalVotes() %>)</p>
            <p class="rank"><%= i++ %></p>
        </div>
        <%
            }
        %>
    </div>
</div>
<script type="text/javascript" src="${pageContext.request.contextPath}/js/index.js"></script>
</body>
</html>
