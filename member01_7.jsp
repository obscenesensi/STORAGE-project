<%
 String id;
 if(session.getAttribute("id")!=null){
  id = "세션값 있음";
 }else{
  id = "세션값 없음";
 }
%>
<h1>로그인</h1>
<form action="loginPro.jsp" method="post">
아이디: <input type="text" name="id"><br>
패스워드: <input type="password" name="passwd"><br>
<input type="submit" value="로그인">
<input type="button" value="로그아웃" onclick="location.href='logout.jsp'"><br>
</form>
<%=id %>
