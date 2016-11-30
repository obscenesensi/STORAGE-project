package ch09.part01; 

import java.io.DataOutputStream; 
import java.io.IOException; 
import java.net.ServerSocket; 
import java.net.Socket; 
import java.text.DateFormat; 
import java.text.SimpleDateFormat; 
import java.util.Date; 

public class Server {
 
    static DateFormat format = new SimpleDateFormat("[hh:mm:ss] ");
 
    public Server() throws IOException {
         ServerSocket serverSocket = null; 

        try { 
            serverSocket = new ServerSocket(7777);
             System.out.println(getTime() + " 서버가 준비 되었습니다.");
         } catch (IOException e) { 
        } 
         
        Socket client = null;  
        DataOutputStream dos = null;  
         
        while( true ) {  
            try{ 
                System.out.println(getTime() + " 연결 요청을 기다리는 중.. ");
                 // 서버 소켓은 클라이언트의 요결 요청이 올 때까지 실행을 멈추고 계속 기다린다.
                 // 클라이언트의 연결 요청이 오면 클라이언트 소켓과 통신할 새로운 소켓을 생성한다.
                 client = serverSocket.accept(); 
                System.out.println(getTime() +  client.getInetAddress()  
                        + " 로 부터 연결 요청이 들어왔습니다. ");
                  
                // 클라이언트로 메시지를 전송하기 위한 OutputStream 객체 획득 
                 dos = new DataOutputStream(client.getOutputStream()) ;
                  
                // 클라이언트에 메시지 전송.  
                dos.writeUTF("Notice : Test MSG"); 
                 System.out.println(getTime() + " 데이터를 전송 했습니다.");  
             } catch ( Exception ex ){ 
            } finally{ 
                dos.close(); 
                client.close(); 
            } 
        } // while  
    } 

    private String getTime() { 
        return format.format(new Date());
     } 

    public static void main(String[] args) throws IOException {
         new Server(); 
    } 

} 
 
[출처] [ JAVA ] java chat 자바 채팅 프로그램 예제|작성자 soxoo
