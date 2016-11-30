<%
  // 한글처리
  request.setCharacterEncoding("utf-8");
  // id passwd name가져오기
  String id = request.getParameter("id");
  String passwd = request.getParameter("passwd");
  String name = request.getParameter("name");
  ResultSet rs = null;
  try {
   // 1단계 드라이버로더
   Class.forName("com.mysql.jdbc.Driver");
   // 2단계 디비연결
   Connection con = null;
   String url = "jdbc:mysql://localhost:3306/jspbeginner";
   String user = "jspid";
   String pwd = "jsppass";
   con = DriverManager.getConnection(url, user, pwd);
   // 3단계 : id에 해당하는 passwd를 가져오는 sql(sql 생성)
   PreparedStatement pstmt = null;
   String sql = "";
   
   sql = "select passwd from member where id=?";
   pstmt = con.prepareStatement(sql);
   pstmt.setString(1, id);
   // 4단계 실행 => rs저장
   rs = pstmt.executeQuery();
   // 5단계 rs 데이터있으면 id있음
   //   폼비밀번호 rs비밀번호 비교 맞으면 => 수정
   //                     틀리면 => 비밀번호틀림
   //            없으면 id없음
   if(rs.next()){
    //id있음
//     rs.getString(1);
    String dbPass=rs.getString("passwd");
    if(passwd.equals(dbPass)){
     //비밀번호 맞음 수정
     sql = "update member set name=? where id=? and passwd=?";
     pstmt=con.prepareStatement(sql);
     pstmt.setString(1, name);
     pstmt.setString(2, id);
     pstmt.setString(3, passwd);
        
     // 4단계 실행
     pstmt.executeUpdate(); //insert,update,delete
     out.println("정보수정 성공!");
    }else{
     out.println("비밀번호 틀림!");
    }    
   }else{
    out.println("id가 존재하지 않아여");//id없음
   }
   
  } catch (Exception e) {
   e.printStackTrace();
  }finally{
   
  }
 %>
