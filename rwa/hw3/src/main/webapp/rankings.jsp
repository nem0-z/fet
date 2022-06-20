<%@ page import="com.example.hw2.VideoModel" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="com.example.hw2.DBService" %>
<%@ page import="com.example.hw2.Helper" %>
<!DOCTYPE html>
<html lang="en">
<head>
  <title>Rankings</title>
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

<div id="rankings">
  <p>Rankings</p>
  <div id="rankingsContainer">
    <div class="top5header">
      <p></p>
      <p>Headline/Description</p>
      <p>Votes(positive/total)</p>
      <p>Rank</p>
    </div>
    <%
      final long rowsCount = DBService.getRowsCount();
      int rpage = Helper.getRpage(request);
      final double pageSize = 20;
      ArrayList<VideoModel> videoModels = DBService.getVideosForRankingTable(rpage - 1, (int) pageSize);
      int i = 1;
      for (VideoModel vm: videoModels) {
        String imageUrl = vm.getImgUrl().isEmpty() ? "https://img.youtube.com/vi/" + vm.getEmbedUrl() + "/0.jpg" : vm.getImgUrl();
    %>
    <div class="top5row">
      <img src="<%= imageUrl %>" alt="Failed to load resource"></img>
      <p class="headline"><%= vm.getTitle()%>:"<%= vm.getDescription()%>"</p>
      <p class="votes">(<%= vm.getPositiveVotes()%>/<%= vm.getTotalVotes()%>)</p>
      <p class="rank"><%= String.format("%.5f", vm.getRank())%></p>
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
    <a href="${pageContext.request.contextPath}/routes/rankings?rpage=<%= moreBack ? rpage-1 : rpage%>" <% if (!moreBack) out.print("style=\"pointer-events: none\""); %>>
      Back
    </a>
    <a href="${pageContext.request.contextPath}/routes/rankings?rpage=<%= moreForward ? rpage+1 : rpage%>" <% if (!moreForward) out.print("style=\"pointer-events: none\""); %>>
      Next
    </a>
    <p>Page <%= rpage%> of <%= (int) Math.ceil(rowsCount / pageSize)%></p>
  </div>
</div>
</body>
</html>
