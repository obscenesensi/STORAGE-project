<%
// 한글처리
request.setCharacterEncoding("utf-8");
//자바빈생성 패키지 board, 파일이름 BoardDataBean
//액션태그 자바빈 객체 생성 board
//액션태그 폼 -> 자바빈 저장
%><jsp:useBean id="board" class="board.BoardDataBean"/>
<jsp:setProperty property="*" name="board"/>
<%
//수동으로 ip주소 reg_date 저장하게 해주고
board.setReg_date(new Timestamp(System.currentTimeMillis())); //현재 시간을 Reg_date에 저장
board.setIp(request.getRemoteAddr()); //ip주소를 받아서 IP에 저장
//디비파일생성 패키지 board, 파일이름 BoardDBBean
//디비객체생성 dbPro
BoardDBBean dbPro = new BoardDBBean();
//메서드 호출 reInsertBoard(board)
dbPro.reInsertBoard(board);
//이동 list.jsp
%>
<script type="text/javascript">
alert("게시판 답글쓰기 성공!");
location.href="list.jsp";
</script><%
%>
