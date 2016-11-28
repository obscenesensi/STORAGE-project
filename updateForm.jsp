<%
//int num    String pageNum
int num = Integer.parseInt(request.getParameter("num"));
String pageNum=request.getParameter("pageNum");
//디비객체생성 dbPro
BoardDBBean dbPro = new BoardDBBean();
//자바빈 board=메서드호출 getBoard(num)
BoardDataBean board = dbPro.getboard(num);
%>
<h1>게시판 글수정</h1>
<form action="updatePro.jsp?pageNum=<%=pageNum %>" method="post">
<input type="hidden" name="num" value="<%=num%>">
<table border="1">
<tr><td>이름</td>
<td><input type="text" name="writer" value="<%=board.getWriter()%>"></td></tr>
<tr><td>제목</td>
<td><input type="text" name="subject" value="<%=board.getSubject()%>"></td></tr>
<tr><td>Email</td>
<td><input type="text" name="email" value="<%=board.getEmail()%>"></td></tr>
<tr><td>내용</td>
<td><textarea name="content" rows="13" cols="40"><%=board.getContent()%></textarea></td></tr>
<tr><td>비밀번호</td>
<td><input type="password" name="passwd"></td></tr>
<tr><td><input type="submit" value="글수정">
<input type="reset" value="다시작성">
<input type="button" value="목록보기" onclick="location.href='list.jsp?pageNum=<%=pageNum%>'"></td></tr>
</table>
</form>
