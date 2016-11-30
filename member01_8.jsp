<%
//id passwd가져오기
request.setCharacterEncoding("utf-8");
String id = request.getParameter("id");
String passwd = request.getParameter("passwd");
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
 //3단계 id에 해당하는 passwd가져오기
 sql = "select passwd from member where id=?";
   pstmt = con.prepareStatement(sql);
   pstmt.setString(1, id);
 //4단계 실행 => rs
 rs = pstmt.executeQuery();
 //5단계 데이터가 있으면 아이디있음
 if(rs.next()){
  //id있음
//   rs.getString(1);
  String dbPass=rs.getString("passwd");
  if(passwd.equals(dbPass)){
   //비밀번호비교 맞으면 세션값생성 "id"
   //    이동 main.jsp
   session.setAttribute("id", id);
   %>
   <script type="text/javascript">
   alert("세션값 생성");
   location.href="main.jsp";
   </script>
   <%
  }else{
   %>
   <script type="text/javascript">
   alert("비밀번호 틀려써여");
   history.back();
   </script><%
  }
 }else{
  %>
  <script type="text/javascript">
  alert("id가 존재하지 않아여");
  history.back();
  </script><%
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
