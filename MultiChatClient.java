package ch09.part02; 

import java.net.*; 
import java.io.*; 
import java.util.*; 

// 실행 방법 
// java MultichatClient 대화명  
public class MultichatClient {
     public static void main(String[] args) {
 
        // 첫번째 실행 인자를 추출한다. 
        if (args.length != 1) {
             System.out.println("USAGE : java MultichatClient 대화명");
             System.exit(0);// 시스템 종료
         } 

        Socket socket = null; 
        try { 
            String serverIp = "127.0.0.1"; 
            socket = new Socket(serverIp, 7777); // 소켓을 생성하여 연결을 요청한다.
             System.out.println("서버에 연결되었습니다.");
 
            // 메시지 전송용 Thread 생성 
            Thread sender = new Thread(new ClientSender(socket, args[0]));
 
            // 메시지 수신용 Thread 생성 
            Thread receiver = new Thread(new ClientReceiver(socket));
 
            sender.start(); 
            receiver.start(); 
        } catch (ConnectException ce) { 
            ce.printStackTrace(); 
        } catch (Exception e) { 
        } 
    }// main 

    // 메시지 전송용 Thread 
    static class ClientSender implements Runnable {
         Socket socket; 
        DataOutputStream out; 
        String name; 

        ClientSender(Socket socket, String name) { 
            this.socket = socket; 
            this.name = name; 

            try { 
                this.out = new DataOutputStream(socket.getOutputStream());
             } catch (Exception e) { 
            } 
        } 

        public void run() {
             Scanner scanner = new Scanner(System.in);
             try { 

                // 시작하자 마자, 자신의 대화명을 서버로 전송 
                if (out != null) {
                     out.writeUTF(name); 
                } 

                while (out != null) { 
                    // 키보드로 입력받은 데이터를 서버로 전송
                     out.writeUTF("[" + name + "]" + scanner.nextLine());
                 } 
            } catch (IOException e) { 
            } 
        } 
    } 

    // 메시지 수신용 Thread 
    static class ClientReceiver implements Runnable {
         Socket socket; 
        DataInputStream in; 

        // 생성자 
        ClientReceiver(Socket socket) { 
            this.socket = socket; 

            try { 
                // 서버로 부터 데이터를 받을 수 있도록 DataInputStream 생성
                 this.in = new DataInputStream(socket.getInputStream());
             } catch (IOException e) { 
            } 
        } 

        public void run() {
             while (in != null) { 
                try { 
                    // 서버로 부터 전송되는 데이터를 출력 
                    System.out.println(in.readUTF()); 
                } catch (IOException e) { 
                } 
            } 
        } 
    } 
} 
[출처] [ JAVA ] java chat 자바 채팅 프로그램 예제|작성자 soxoo

