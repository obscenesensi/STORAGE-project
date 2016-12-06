<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
    
<!-- 1. DB 연결 -->
<%@ include file="dbConnect.jsp" %>

<%
	// request 객체로부터 변수값 가져오기
	request.setCharacterEncoding("EUC-KR");
	String title = request.getParameter("title");
	String writtenby = request.getParameter("writtenby");
	String txtDate = request.getParameter("txtDate");
	String ta = request.getParameter("ta");
	
	//2. 입력 데이터 쓰기 쿼리 명령어 전송
	
	try{
		
		query = "insert into thp2015(title,writer,date,context)"
		+ " values ('"+title+"','"+writtenby+"','"
		+			"'"+txtDate+"','"+ta+"')"	;
		

		// out.print(query); <!-- 이상이 없으면 필요 없는 구문 -->
		
		pstmt = conn.prepareStatement(query);
		pstmt.executeUpdate();
		
		
	} catch (Exception e) {
		e.printStackTrace();
	} finally {
		try {
			if(rs != null) rs.close();
			if(pstmt != null)    pstmt.close();
			if(conn != null)     conn.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
// 3. 글목록 페이지로 이동
	response.sendRedirect("list.jsp");
%>
    
    
