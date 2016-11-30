package ch09.part01; 

import java.io.DataInputStream; 
import java.io.IOException; 
import java.net.Socket; 

public class Client {
 
    public static void main(String[] args) throws IOException {
         String serverIp = "127.0.0.1";  
        Socket socket = null; 
        DataInputStream dis = null;  
        System.out.println("서버에 연결 중입니다. 서버 IP : " + serverIp);
         try { 
            socket = new Socket(serverIp, 7777);
             dis = new DataInputStream( socket.getInputStream() );
             // 문자열을 받는다.  
            System.out.println("서버로 부터 받은 MSG : " + dis.readUTF()); 
              
        } catch (Exception e) { 
            e.printStackTrace(); 
        } finally{ 
            System.out.println("연결 종료!"); 
            dis.close(); 
            socket.close(); 
        } 
         
    }//main  
} 
[출처] [ JAVA ] java chat 자바 채팅 프로그램 예제|작성자 soxoo

