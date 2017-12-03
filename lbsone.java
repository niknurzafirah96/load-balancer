import java.io.*;

import java.net.*;



public class lbsone {
	
  public static void main(String []args)throws IOException {
	
    ServerSocket server1 = new ServerSocket(8888);
	
    while(true) {
	  
      Socket connectionsocket = server1.accept();
  	  
      BufferedReader msgfromlb = new BufferedReader(new InputStreamReader(connectionsocket.getInputStream()));
 	 
      String sentence = msgfromlb.readLine();
	  
      System.out.println("Received from client : " +sentence);
	  
    }
	
  }

}
