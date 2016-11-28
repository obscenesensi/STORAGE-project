<%
// int num
int num = Integer.parseInt(request.getParameter("num"));
// String pageNum
String str = request.getParameter("pageNum");
int pageNum = Integer.parseInt(request.getParameter("pageNum"));
// String passwd
String passwd = request.getParameter("passwd");
// 디비객체생성  dbPro
BoardDBBean dbPro = new BoardDBBean();
// int check = 메서드 호출 deleteBoard(num,passwd)
int check = dbPro.deleteBoard(num, passwd);
// check==1 이면 list.jsp?pageNum=
// check==0 비밀번호틀림 뒤로 이동
if(check==1){
 response.sendRedirect("list.jsp?pageNum="+pageNum);
}else{
 %><script type="text/javascript">
 alert("비밀번호 틀렸어!");
 history.back();
 </script>
 <%
}
%>
 
