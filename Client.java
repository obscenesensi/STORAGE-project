import java.io.*;
import java.net.*;

public class Client {
	public static void main(String[] args) {
		
		Socket socket = null;
		
		try {
			socket = new Socket("210.119.33.88", 9999); // 클라이언트 소켓 생성
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream())); // 서버로부터의 입력 스트림
			BufferedReader stin = new BufferedReader(new InputStreamReader(System.in)); // 키보드로부터의 입력 스트림
			BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())); // 서버로의 출력 스트림
			String outputMessage;
			while (true) {
				outputMessage = stin.readLine(); // 키보드에서 한 행의 문자열 읽음
				if (outputMessage.equalsIgnoreCase("byebyebye")) { // "bye"가 입력되면 메시지 전송 후 연결 종료
					out.write(outputMessage);
					out.flush();
					break;
				}
				out.write("클라이언트>"+outputMessage+"\n"); // 키보드에서 읽은 문자열 전송
				out.flush();
				String inputMessage = in.readLine(); // 서버에서 한 행의 문자열 읽음
				System.out.println(inputMessage); // 서버가 보낸 메시지 화면에 출력
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				socket.close(); // 클라이언트 소켓 닫기
			} catch (IOException e) {
				System.out.println("서버와 채팅 중 오류가 발생했습니다.");
			}
		}
	}
}
