<%
// int num값, String pageNum값
int num = Integer.parseInt(request.getParameter("num"));
String pageNum = request.getParameter("pageNum");
%>
<h1>글삭제</h1>
<form action="deletePro.jsp?pageNum=<%=pageNum %>" method="post">
<input type = "hidden" name="num" value="<%=num %>">
<table border="1">
<tr><td>비밀번호 입력하세요</td></tr>
<tr><td><input type="password" name="passwd"></td></tr>
<tr><td>
<input type="submit" value="글삭제">
<input type="button" value="글목록" onclick="location.href='list.jsp?pageNum=<%=pageNum %>'">
</td></tr>
</table>
</form>
