<h1>회원정보조회</h1>
<%
//세션값 가져오기
//세션값 없으면 loginForm.jsp이동
String id = (String)session.getAttribute("id");
if(id==null)response.sendRedirect("loginForm.jsp");
request.setCharacterEncoding("utf-8");
ResultSet rs = null;
Connection con = null;
String url = "jdbc:mysql://localhost:3306/jspbeginner";
String user = "jspid";
String pwd = "jsppass";
PreparedStatement pstmt = null;
String sql = "";
try{
//1단계 드라이버로더
Class.forName("com.mysql.jdbc.Driver");
//2단계 디비연결
con = DriverManager.getConnection(url, user, pwd);
//3단계 id에 해당하는 모든 데이터 가져오기
sql = "select * from member where id=?";
pstmt = con.prepareStatement(sql);
pstmt.setString(1, id);
//4단계 실행 => rs저장
rs = pstmt.executeQuery();
//5단계 데이터가 있으면 rs내용가져와서 출력
if(rs.next()){
 //id있음
 %>
 아이디:<%=rs.getString("id") %><br>
 비밀번호:<%=rs.getString("passwd") %><br>
 이름:<%=rs.getString("name") %><br>
 가입일:<%=rs.getTimestamp("reg_date") %><br><% 
}
}catch (Exception e) {
 e.printStackTrace();
}finally{
 //rs!=null : 기억장소가 확보되어 있다는 뜻
 if(rs!=null)try{rs.close();}catch(SQLException ex){}
 if(pstmt!=null)try{pstmt.close();}catch(SQLException ex){}
 if(con!=null)try{con.close();}catch(SQLException ex){}
}
%>
<a href="main.jsp">메인화면으로</a>
