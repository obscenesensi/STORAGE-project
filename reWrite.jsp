<%
int num = Integer.parseInt(request.getParameter("num"));
int ref = Integer.parseInt(request.getParameter("ref"));
int re_step = Integer.parseInt(request.getParameter("re_step"));
int re_level = Integer.parseInt(request.getParameter("re_level"));
BoardDBBean dbPro = new BoardDBBean();
BoardDataBean board = dbPro.getboard(num);
%>
<h1>게시판 답글쓰기</h1>
<form action="reWritePro.jsp" method="post">
<input type="hidden" name="num" value="<%=num%>">
<input type="hidden" name="ref" value="<%=ref%>">
<input type="hidden" name="re_level" value="<%=re_level%>">
<input type="hidden" name="re_step" value="<%=re_step%>">
<table border="1">
<tr><td>이름</td><td><input type="text" name="writer"></td></tr>
<tr><td>제목</td><td><input type="text" name="subject" value="[답글] <%=board.getSubject() %>"></td></tr>
<tr><td>Email</td><td><input type="text" name="email"></td></tr>
<tr><td>내용</td><td><textarea name="content" rows="13" cols="40"></textarea></td></tr>
<tr><td>비밀번호</td><td><input type="text" name="passwd"></td></tr>
<tr><td><input type="submit" value="답글쓰기">
<input type="reset" value="다시작성">
<input type="button" value="목록보기" onclick="location.href='list.jsp'"></td></tr>
</table>
</form>
