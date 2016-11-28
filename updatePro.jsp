<%
//한글처리
request.setCharacterEncoding("utf-8");
//액션태그 자바빈 객체 생성 board
//액션태그 폼 => 자바빈 저장
%><jsp:useBean id="board" class="board.BoardDataBean"/>
<jsp:setProperty property="*" name="board"/>
<%
//pageNum 가져오기
String pageNum = request.getParameter("pageNum");
//디비객체 생성 dbPro
BoardDBBean dbPro = new BoardDBBean();
//int check=수정메서드 호출 updateBoard()
int check = dbPro.updateBoard(board);
// check==1이면 list.jsp?pageNum=로 이동 pageNum값 가지고 이동
// check==0 비밀번호 틀림 뒤로이동
if(check==1){
 response.sendRedirect("list.jsp?pageNum="+pageNum);
}else{
 %><script type="text/javascript">
 alert("비밀번호 틀림");
 history.back();
 </script><%
}
%>
