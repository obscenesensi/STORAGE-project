<%
//게시판 글개수
//디비객체생성 dbPro
BoardDBBean dbPro = new BoardDBBean();
int count=0;
//count=메서드 호출 getBoardCount()
count = dbPro.getBoardCount();
//한페이지에 몇개 글 가져오기
int pageSize=10;
//현페이지 몇페이지 가져오기
String pageNum = request.getParameter("pageNum");
if(pageNum == null){
 pageNum="1";
}
//현페이지 시작행 구하기
int currentPage = Integer.parseInt(pageNum);
int startRow = (currentPage-1)*pageSize+1;
int endRow = currentPage*pageSize;
List boardList = null;
if(count!=0){
 //boardList = 메서드 호출 getBoards(startRow,pageSize)
 boardList = dbPro.getBoards(startRow, pageSize);
}
%>
<h1>게시판 목록(전체글:<%=count %>)</h1>
<h3><a href="writeForm.jsp">글쓰기</a></h3>
<table border="1">
<tr><td>번호</td><td>제목</td><td>작성자</td>
 <td>작성일</td><td>조회</td><td>IP</td></tr>
<%
if(count!=0){
 for(int i=0; i<boardList.size(); i++){
  BoardDataBean board = (BoardDataBean) boardList.get(i);
  %>
  <tr><td><%=board.getNum() %></td>
  <td>
  <%
  int wid=0;
  if(board.getRe_level()>0){
   //답변글
   wid = 10*board.getRe_level();
   %>
   <img src="img/level.gif" width="<%=wid%>">
   <img src="img/re.gif">
   <%
  }
  %>
  <a href="content.jsp?num=<%=board.getNum()%>&pageNum=<%=currentPage%>"><%=board.getSubject() %></a></td>
  <td><%=board.getWriter() %></td>
  <td><%=board.getReg_date() %></td>
  <td><%=board.getReadcount() %></td>
  <td><%=board.getIp() %></td></tr>
<%}}
%>
</table>
<%
if(count>0){
 //페이징 작업을 하기 위해서는 전체 페이지수가 필요
 //전체 페이지수 구하기//50개=>5페이지, 51~59개=>6페이지
 int pageCount = count/pageSize+(count%pageSize==0?0:1);
 //한 페이지에 보여줄 페이지수 설정
 int pageBlock = 10;
 //한 페이지에 보여지는 시작페이지 구하기
 int startPage = ((int)(currentPage/pageBlock)-(currentPage%pageBlock==0?1:0))*pageBlock+1;
 //한 페이지에 보여지는 끝페이지 구하기
 int endPage = startPage+pageBlock-1;
 if(endPage>pageCount){
  endPage=pageCount;
 }
 //[이전]
 if(startPage>pageBlock){
  %><a href="list.jsp?pageNum=<%=startPage-pageBlock%>">[이전]</a><%
 }
 //[1]~[10]
 for(int i=startPage; i<=endPage; i++){
  %><a href="list.jsp?pageNum=<%=i%>">[<%=i %>]</a><%
 }
 //[다음]
 if(endPage<pageCount){
  %><a href="list.jsp?pageNum=<%=startPage+pageBlock%>">[다음]</a><%  
 }
}
%>
