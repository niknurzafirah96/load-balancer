import java.net.*;

import java.io.*;



public class loadbalancer {
    
  public static void main(String[] args) throws Exception {
        
    ServerSocket server1 = new ServerSocket(7777);
	
    while(true) {
	
      Socket connectionsocket = server1.accept();
	
      BufferedReader messagefromclient = new BufferedReader(new InputStreamReader(connectionsocket.getInputStream()));
	
      String clientsentence = messagefromclient.readLine();

	
      if(clientsentence.contains("boy")) {
	
         Socket server = new Socket("192.168.40.134",8888);
	
         DataOutputStream outtoserver = new DataOutputStream(server.getOutputStream());
	
         outtoserver.writeBytes(clientsentence+"\n");
	
         server1.close();
	
         }
	
      else if(clientsentence.contains("girl")) {
	
         Socket server2 = new Socket("192.168.40.135",9999);
	
         DataOutputStream outtoserver2 = new DataOutputStream(server2.getOutputStream());
	
         outtoserver2.writeBytes(clientsentence+"\n");
	
         server2.close();

         }

      else {
 	
         System.out.println("No Data");
	
         }
   
      }

   }

}
