import java.io.*;
import java.net.*;

public class Server {

  private Socket socket = null;
  private ServerSocket server = null;
  private DataInputStream in = null;

  public Server(int port) {
    try {
      server = new ServerSocket(port);
      System.out.printf("Server started on port: %d\n", port);

      System.out.println("Waiting for a client ...");

      socket = server.accept();
      System.out.println("Client accepted");

      in =
        new DataInputStream(new BufferedInputStream(socket.getInputStream()));

      String line = "";

      line = in.readUTF();
      System.out.println(line);
      System.out.println("Closing connection");

      socket.close();
      in.close();
    } catch (IOException i) {
      System.out.println(i);
    }
  }

  public static void main(String args[]) {
    System.out.print("Enter a port number: ");
    int port = Integer.parseInt(System.console().readLine());
    Server server = new Server(port);
  }
}
