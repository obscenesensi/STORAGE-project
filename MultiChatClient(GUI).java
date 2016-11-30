package ch09.part02.gui; 

import java.awt.BorderLayout; 
import java.awt.Button; 
import java.awt.Color; 
import java.awt.Frame; 
import java.awt.Panel; 
import java.awt.TextArea; 
import java.awt.TextField; 
import java.awt.event.ActionEvent; 
import java.awt.event.ActionListener; 
import java.awt.event.KeyAdapter; 
import java.awt.event.KeyEvent; 
import java.awt.event.WindowAdapter; 
import java.awt.event.WindowEvent; 
import java.io.DataInputStream; 
import java.io.DataOutputStream; 
import java.io.IOException; 
import java.net.ConnectException; 
import java.net.Socket; 
import java.util.Scanner; 

/** 
 * // 실행 방법 // java MultichatGUIClient 대화명 
 *  
 * @since 2012. 07. 11. 
 * @author yanggun7201 
 */ 
public class MultichatGUIClient implements ActionListener {
     Frame f; 
    Panel p; 
    Button b1; 
    TextField tf; 
    TextArea ta; 
    // =============================== 
    String name; 
    ClientSender sender; 
    // =============================== 

    public MultichatGUIClient(String name) { 
        // =============================== 
        this.name = name; 
        f = new Frame(name); 
        // =============================== 

        p = new Panel(); 
        b1 = new Button("전송");
         tf = new TextField(); 
        ta = new TextArea(20, 50);
     } 

    public void launchTest() {
         f.addWindowListener(new WindowAdapter() {
             public void windowClosing(WindowEvent e) {
                 System.exit(0); 
            } 
        }); 

        // frame은 기본적으로 BorderLayout이다. 
        f.add(BorderLayout.SOUTH, p); 

        b1.addActionListener(this); 
        b1.setBackground(Color.yellow); 

        tf.setColumns(40); 
        tf.addKeyListener(new KeyAdapter() { 
            public void keyReleased(KeyEvent e) {
                 char keyCode = e.getKeyChar();
                 if (keyCode == KeyEvent.VK_ENTER) {
                     actionPerformed(null); 
                } 
            } 
        }); 

        p.setBackground(Color.green); 
        p.add(tf); 
        p.add(b1); 

        f.add(BorderLayout.CENTER, ta); 

        f.setVisible(true); 
        f.pack(); 

        // =================================================
         Socket socket = null; 
        try { 
            String serverIp = "127.0.0.1"; 
            socket = new Socket(serverIp, 7777); // 소켓을 생성하여 연결을 요청한다.
             System.out.println("서버에 연결되었습니다.");
 
            // 메시지 전송용 Thread 생성 
            sender = new ClientSender(socket);
 
            // 메시지 수신용 Thread 생성 
            Thread receiver = new Thread(new ClientReceiver(socket));
 
            receiver.start(); 
        } catch (ConnectException ce) { 
            ce.printStackTrace(); 
        } catch (Exception e) { 
        } 
        // =================================================
     } 

    @Override 
    public void actionPerformed(ActionEvent e) {
         // ========================= 
        sender.send(tf.getText()); 
        // ========================= 
        tf.setText(""); 
        tf.requestFocus(); 
    } 

    // =================================================
     public void setMessage(String message) {
         ta.append(message); 
        ta.append("\n"); 
    } 
    // =================================================
 
    // ===============================================================================
     // 메시지 전송용 객체  
    // Thread 아님!!! (GUI 버전이므로, Event를 받아서 처리함)
     class ClientSender { 
        Socket socket; 
        DataOutputStream out; 

        ClientSender(Socket socket) { 
            this.socket = socket; 

            try { 
                this.out = new DataOutputStream(socket.getOutputStream());
 
                // 시작하자 마자, 자신의 대화명을 서버로 전송 
                if (out != null) {
                     out.writeUTF(name); 
                } 

            } catch (Exception e) { 
            } 
        } 

        public void send(String message) {
             if (out != null) {
                 try { 
                    // 키보드로 입력받은 데이터를 서버로 전송
                     out.writeUTF("[" + name + "] " + message);
                 } catch (IOException e) { 
                } 
            } 
        } 
    } 

    // 메시지 수신용 Thread 
    class ClientReceiver implements Runnable {
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
                    MultichatGUIClient.this.setMessage(in.readUTF());
                 } catch (IOException e) { 
                } 
            } 
        } 
    } 

    // ===============================================================================
 
    // 실행 방법 
    // java MultichatGUIClient 대화명 
    public static void main(String[] args) {
 
        String name = null; 
        Scanner scanner = new Scanner(System.in);
 
        do { 
            System.out.println("대화명을 입력하세요.");
             System.out.print(">>> ");
             name = scanner.nextLine(); 
            if (name.isEmpty()) { 
                System.out.println("대화명은 한글자 이상 입력해야 합니다.\n\n");
             } 
        } while (name.isEmpty()); 

        new MultichatGUIClient(name).launchTest();
     } 
}
[출처] [ JAVA ] java chat 자바 채팅 프로그램 예제|작성자 soxoo

