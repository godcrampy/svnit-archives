import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
  private Socket socket;
  private ServerSocket server;
  private DataInputStream in;
  private boolean serverStarted = false;

  public Server(int port) {
    // setup server socket
    try {
      serverStarted = false;
      server = new ServerSocket(port);
      serverStarted = true;
    } catch (Exception e) {
      System.out.println(e);
    }
  }

  public void listen() throws IOException {
    if (!serverStarted) {
      // server socket not setup
      throw new IOException("Server not started on any port");
    }
    System.out.println("Server started");
    System.out.println("Waiting for a client ...");
    socket = server.accept();
    System.out.println("Client accepted");
    // listen for the client
    in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
    String line = "";
    // read message from client until "exit" is sent
    while (!line.equals("exit")) {
      try {
        line = in.readUTF();
        System.out.println(line);
      } catch (Exception i) {
        System.out.println(i);
      }
    }
    System.out.println("Closing connection");
    // close connection
    socket.close();
    in.close();
  }

  public static void main(String args[]) {
    Server server = new Server(5000);
    try {
      server.listen();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
