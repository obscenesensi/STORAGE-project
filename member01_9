<%
String id = (String)session.getAttribute("id");
if(id==null){
 response.sendRedirect("loginForm.jsp");
}
%>
<h1><%=id %>님이 로그인 하셨습니다!</h1>
<a href="info.jsp">회원정보조회</a><br>
<input type="button" value="뒤로가기" onclick="location.href='loginForm.jsp'"><br>
