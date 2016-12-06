<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
    
<%@ include file="dbConnect.jsp" %>
<%	// include file="~"하면 매번 일일히 안써도 괜찮음! %>

<%
	String no = null;
	String title = null;
	String writtenby = null;
	String date = null;
%>

<%
	// DB로부터 값을 가져오기 위해 쿼리문 실행
	try{
		query = "select * from thp2015";
		pstmt = conn.prepareStatement(query);
		rs = pstmt.executeQuery(); //rs에 값 저장
%>
    
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

<table border=1 cellspacing=0 bordercolor=#538053 bgcolor=#CBB8EE>

	<tr>
		<td bordercolor=yeollow>번호</td>
		<td>제목</td>
		<td>작성자</td>
		<td>작성일</td>
	</tr>
	
	<%
	
		if(rs == null)
			out.print("rs is null.");
	
		else {
			rs.last();
			int rows = rs.getRow();
			
		while(rows != 0) {
			rs.absolute(rows--);
			no = rs.getString("ida");
			title = rs.getString("title");
			writtenby = rs.getString("writer");
			date = rs.getString("date"); %>
		
	<tr>
		<td><%=no %></td>
		<td><a href="view.jsp?pno=<%=no%>"><%=title %></a></td>
		<td><%=writtenby %></td>
		<td><%=date %></td>
	</tr>
		
		<%
		} }
	%>

</table>

<form method=post action="new.jsp">
	<input type=submit value="새글쓰기">
	<input type=submit value="새로고침"
	onClick="javascript:location.reload();">
</form>

<%
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
%>

</body>
</html>
