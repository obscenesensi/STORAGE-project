<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<%@ include file="dbConnect.jsp" %>

<%
	String pno = request.getParameter("pno");
%>


<%
	
	try {
		query = "select ida, title, writer, date, context"
		+ " from thp2015 where ida=?";
		
		pstmt = conn.prepareStatement(query);
		pstmt.setString(1, pno);
		rs = pstmt.executeQuery();
		
		if (rs == null)
			out.print("rs is null.");
		else {
			while(rs.next()) {
				String no = rs.getString("ida");
				String title = rs.getString("title");
				String writtenby = rs.getString("writer");
				String date = rs.getString("date");
				String context = rs.getString("context");
			

%>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

<table bgcolor=#FFD4DF>

<tr> 
	<td bgcolor=#FFFF96>No.</td><td><%=no %></td>
<td width=100 bgcolor=#FFFF96>제목</td>
	<td width=500>
	<%=title %>
	</td></tr>

<tr> <td bgcolor=#FFFF96>작성자</td>
	<td width=200><%=writtenby %></td>
	<td bgcolor=#FFFF96>작성일</td>
	<td width=300><%=date %></td>
	</tr>
	
<tr> <td bgcolor=#FFFF96>글내용</td>
	<td colspan=3 width=600 height=400>
	<%=context %>
	</td></tr>

</table>
<input type=submit value="뒤로가기"
	onclick="javascript:history.go(-1);">

</body>
</html>

<%
	
			}
		}
	}catch (Exception e) {
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
