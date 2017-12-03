import java.io.*;

import java.net.*;



public class lbstwo {
	
  public static void main(String []args)throws IOException {
	
    ServerSocket server2 = new ServerSocket(9999);
	
    while(true) {
	  
      Socket connectionsocket = server2.accept();
  	  
      BufferedReader msgfromlb = new BufferedReader(new InputStreamReader(connectionsocket.getInputStream()));
 	 
      String sentence = msgfromlb.readLine();
	  
      System.out.println("Received from client : " +sentence);
	  
    }
	
  }

}
