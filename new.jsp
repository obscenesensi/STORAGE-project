<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import="java.util.*, java.text.*"%>
<%// 날짜 정보를 받아옴 (위에 줄) %>
<%
	//현재 시스템 날짜 시간정보를 자동 생성
	SimpleDateFormat sdf = new SimpleDateFormat("yyyy년MM월dd일hh시mm분ss초");
	Date date = new Date();
	String today = sdf.format(date);
%>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

<form method=post action="write.jsp">
<table bgcolor=#FFD4DF>

<tr> <td width=50 bgcolor=#FFFF96>제목</td>
	<td colspan=3><input type=text name=title size=100 name=title></td></tr>

<tr> <td bgcolor=#FFFF96>작성자</td>
	<td><input type=text size=40 name=writtenby></td>
	<td bgcolor=#FFFF96>작성일</td>
	<td><input type=text size=40 name=txtDate
		value=<%=today%>></td></tr> <!-- 자바에서 받아온다! -->
	
<tr> <td bgcolor=#FFFF96>글내용</td>
	<td colspan=3><textarea cols=100 rows=40 name=ta></textarea></td></tr>

</table>

<input type=submit value="저장">
<input type=reset value="취소"
	onClick="javascript:history.go(-1);"> <!-- 한단계 뒤로 돌아감 -->
</form>

</body>
</html>
