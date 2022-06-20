<%@ page import="com.example.hw2.VideoModel" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="com.example.hw2.DBService" %>
<%@ page import="com.example.hw2.Helper" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <title>Manage videos</title>
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
<%--    <a href="${pageContext.request.contextPath}">Video voting competition</a>--%>
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

<div id="rankings">
    <p>Manage videos</p>
    <div id="rankingsContainer">
        <button id="addnew">Add</button>
        <div class="top5header">
            <p>Thumbnail</p>
            <p>Headline/Description</p>
            <p></p>
            <p></p>
        </div>
        <%
            final long rowsCount = DBService.getRowsCount();
            int rpage = Helper.getRpage(request);
            final double pageSize = 20;
            ArrayList<VideoModel> videoModels = DBService.getVideosForRankingTableOrderedById(rpage - 1, (int) pageSize);
            int i = 1;
            for (VideoModel vm: videoModels) {
                String imageUrl = vm.getImgUrl().isEmpty() ? "https://img.youtube.com/vi/" + vm.getEmbedUrl() + "/0.jpg" : vm.getImgUrl();
        %>
        <div class="top5row">
            <span style="display: none"><%= vm.getId()%></span>
            <img src="<%= imageUrl %>" alt="Failed to load resource"></img>
            <p class="headline"><%= vm.getTitle()%>:"<%= vm.getDescription()%>"</p>
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
        <a href="${pageContext.request.contextPath}/videos.jsp?rpage=<%= moreBack ? rpage-1 : rpage%>" <% if (!moreBack) out.print("style=\"pointer-events: none\""); %>>
            Back
        </a>
        <a href="${pageContext.request.contextPath}/videos.jsp?rpage=<%= moreForward ? rpage+1 : rpage%>" <% if (!moreForward) out.print("style=\"pointer-events: none\""); %>>
            Next
        </a>
        <p>Page <%= rpage%> of <%= (int) Math.ceil(rowsCount / pageSize)%></p>
    </div>
</div>
<script type="text/javascript" src="${pageContext.request.contextPath}/js/videos.js"></script>
</body>
</html>
