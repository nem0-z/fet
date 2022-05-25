<%@ page import="com.example.hw2.DBService" %>
<%@ page import="com.example.hw2.VideoModel" %>
<%@ page import="java.util.ArrayList" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Video voting competition</title>
    <link rel="stylesheet" href="./styles/main.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
<div class="header">
    <a href="index.jsp">Video voting competition</a>
    <div class="header-right">
        <a class="active" href="index.jsp">Home</a>
        <a href="#">Voting</a>
        <a href="rankings.html">Rankings</a>
    </div>
</div>

<div class="container">
    <%
        //fetch videos here
        ArrayList<VideoModel> randomTwoVideos = DBService.getRandomVideos(2);
        for (VideoModel vm: randomTwoVideos) {
    %>
        <div class="video">
            <p><%= vm.getTitle() %></p>
            <iframe src="<%= vm.getEmbedUrl() %>"></iframe>
            <button class="vote" id="first">Vote</button>
        </div>
    <%
        }
    %>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/GgkASKg4fcE"></iframe>--%>
<%--        <button class="vote" id="second">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/qb9craaTuPI" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/wiMcIXihIlU" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/5FnCqdGsnB4" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/uJThEnfd_Xo" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/TSHEgUGw5rU" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/vYwlo0gYF80" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/yO5KCAgcQ-w" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/qXlEvG6Vuz0" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/s5vNM-8sDhk" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/GgkASKg4fcE" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/qb9craaTuPI" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/wiMcIXihIlU" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/5FnCqdGsnB4" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/uJThEnfd_Xo" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/TSHEgUGw5rU" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/vYwlo0gYF80" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/yO5KCAgcQ-w" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
<%--    <div class="video">--%>
<%--        <p>LZN</p>--%>
<%--        <iframe src="https://www.youtube.com/embed/qXlEvG6Vuz0" frameborder="0"></iframe>--%>
<%--        <button class="vote">Vote</button>--%>
<%--    </div>--%>
</div>

<div id="rankings">
    <p>Top 5 videos</p>
    <div id="rankingsContainer">
        <div class="top5header">
            <p>Headline</p>
            <p>Votes(positive/total)</p>
            <p>Rank</p>
        </div>
        <div class="top5row">
            <img src="https://img.youtube.com/vi/vYwlo0gYF80/0.jpg" alt=""></img>
            <p class="headline">Lud Zbunjen Normalan</p>
            <p class="votes">(5/10)</p>
            <p class="rank">1</p>
        </div>
        <div class="top5row">
            <img src="https://img.youtube.com/vi/5FnCqdGsnB4/0.jpg" alt=""></img>
            <p class="headline">Lud Zbunjen Normalan</p>
            <p class="votes">(2/10)</p>
            <p class="rank">2</p>
        </div>
        <div class="top5row">
            <img src="https://img.youtube.com/vi/qXlEvG6Vuz0/0.jpg" alt=""></img>
            <p class="headline">Lud Zbunjen Normalan</p>
            <p class="votes">(3/10)</p>
            <p class="rank">3</p>
        </div>
        <div class="top5row">
            <img src="https://img.youtube.com/vi/TSHEgUGw5rU/0.jpg" alt=""></img>
            <p class="headline">Lud Zbunjen Normalan</p>
            <p class="votes">(1/10)</p>
            <p class="rank">4</p>
        </div>
        <div class="top5row">
            <img src="https://img.youtube.com/vi/uJThEnfd_Xo/0.jpg" alt=""></img>
            <p class="headline">Lud Zbunjen Normalan</p>
            <p class="votes">(4/10)</p>
            <p class="rank">5</p>
        </div>
    </div>
</div>
<script type="text/javascript" src="./js/index.js"></script>
</body>
</html>