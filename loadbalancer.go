package main


import "net"


import "fmt"


import "bufio"


import "os"




func main() {


  fmt.Println("Launching server...")

  
  
  ln, _ := net.Listen("tcp", ":7777")

  
  
  conn, _ := ln.Accept()

 
  
  if(clientsentence.contains("boy")) {	
    
    conn, _ := net.Dial("tcp","192.168.40.134",8888)  
    
    reader := bufio.NewReader(os.Stdin)
    
    fmt.Print("Text to send: ")
  
    
    text, _ := reader.ReadString('\n')
    
    
    fmt.Fprintf(conn, text + "\n")

  
  }
  
  else if(clientsentence.contains("girl")) {	
    
    conn2, _ := net.Dial("tcp","192.168.40.135",9999)  
    
    reader := bufio.NewReader(os.Stdin)
 

    fmt.Print("Text to send: ")
 

    text, _ := reader.ReadString('\n')
    
    
    fmt.Fprintf(conn2, text + "\n")

   
  }
}