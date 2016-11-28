헤드
<!-- script.js 파일을 불러오는 자바스크립트 태그 -->
<script language="javascript" src="js/script.js"></script>
<!-- css파일을 불러오는 태그 -->
<link href="css/style.css" rel="stylesheet" type="text/css">
HTML
<h1>게시판 글쓰기</h1>
<form action="writePro.jsp" method="post" name="fr" onsubmit="return writeSave()">
<table border="1">
<tr><td>이름</td><td><input type="text" name="writer"></td></tr>
<tr><td>제목</td><td><input type="text" name="subject"></td></tr>
<tr><td>Email</td><td><input type="text" name="email"></td></tr>
<tr><td>내용</td><td><textarea name="content" rows="13" cols="40"></textarea></td></tr>
<tr><td>비밀번호</td><td><input type="text" name="passwd"></td></tr>
<tr><td><input type="submit" value="글쓰기">
<input type="reset" value="다시작성">
<input type="button" value="목록보기" onclick="location.href='list.jsp'"></td></tr>
</table>
</form>
