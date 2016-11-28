<%
//int num과 String pageNum 가져오기
String str = request.getParameter("num");
int num = Integer.parseInt(str);
String pageNum = request.getParameter("pageNum");
//디비객체 생성 dbPro
BoardDBBean dbPro = new BoardDBBean();
//조회수 1증가
dbPro.updateReadCount(num);
//자바빈 board = 메서드 호출 getBoard(num)
BoardDataBean board = dbPro.getboard(num);
%>
<h1>글내용보기</h1>
<table border="1">
<tr><td>글번호</td><td><%=board.getNum() %></td>
 <td>조회수</td><td><%=board.getReadcount() %></td></tr>
<tr><td>작성자</td><td><%=board.getWriter() %></td>
 <td>작성일</td><td><%=board.getReg_date()%></td></tr>
<tr><td>글제목</td><td colspan="3"><%=board.getSubject() %></td></tr>
<tr><td>글내용</td><td colspan="3"><%=board.getContent() %></td></tr>
<tr><td colspan="4">
<input type="button" value="글수정" onclick="location.href='updateForm.jsp?num=<%=num%>&pageNum=<%=pageNum%>'">
<input type="button" value="글삭제" onclick="location.href='deleteForm.jsp?num=<%=num%>&pageNum=<%=pageNum%>'">
<input type="button" value="답글쓰기" onclick="location.href='reWrite.jsp?num=<%=num%>&ref=<%=board.getRef() %>&re_step=<%=board.getRe_step()%>&re_level=<%=board.getRe_level()%>'">
<input type="button" value="글목록" onclick="location.href='list.jsp?pageNum=<%=pageNum%>'">
</td></tr>
</table>
