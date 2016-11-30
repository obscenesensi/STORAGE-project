package ch09.part01; 

import java.io.IOException; 
import java.net.ServerSocket; 
import java.net.Socket; 

public class SocketUtil {
 
    public static void close(Socket socket) {
         if (socket != null) {
             try { 
                socket.close(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
        } 
    } 

    public static void close(ServerSocket serverSoc) {
         if (serverSoc != null) {
             try { 
                serverSoc.close(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
        } 
    } 
}
