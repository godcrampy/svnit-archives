import java.io.*;
import java.net.*;

public class Client {

  private Socket socket = null;
  private DataInputStream input = null;
  private DataOutputStream out = null;

  public Client(String address, int port) {
    try {
      socket = new Socket(address, port);
      System.out.printf("Client connected to port: %d\n", port);

      // takes input from terminal
      input = new DataInputStream(System.in);

      // sends output to the socket
      out = new DataOutputStream(socket.getOutputStream());
    } catch (UnknownHostException u) {
      System.out.println(u);
    } catch (IOException i) {
      System.out.println(i);
    }

    String line = "";

    try {
      line = input.readLine();
      out.writeUTF(line);
    } catch (IOException i) {
      System.out.println(i);
    }

    try {
      input.close();
      out.close();
      socket.close();
    } catch (IOException i) {
      System.out.println(i);
    }
  }

  public static void main(String args[]) {
    System.out.print("Enter a port number: ");
    int port = Integer.parseInt(System.console().readLine());
    Client client = new Client("127.0.0.1", port);
  }
}
