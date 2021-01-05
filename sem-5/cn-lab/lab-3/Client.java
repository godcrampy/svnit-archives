import java.io.*;
import java.net.*;

public class Client {
  private Socket socket;
  private DataOutputStream printStream;
  private BufferedReader serverReader;
  private BufferedReader keyReader;
  private boolean connectionEstablished = false;

  public Client(int port) {
    connectionEstablished = false;
    try {
      socket = new Socket("localhost", port);
      connectionEstablished = true;
    } catch (Exception e) {
      System.out.println(e);
    }
  }

  public void listen() throws IOException {
    if (!connectionEstablished) {
      // server socket not setup
      throw new IOException("Server not started on any port");
    }
    printStream = new DataOutputStream(socket.getOutputStream());
    serverReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    keyReader = new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Client Started...");

    String str, str1;

    // repeat as long as exit
    // is not typed at client
    while (!(str = keyReader.readLine()).equals("exit")) {

      // send to the server
      printStream.writeBytes(str + "\n");

      // receive from the server
      str1 = serverReader.readLine();

      System.out.println(str1);

    }
    // close connection.
    printStream.close();
    serverReader.close();
    keyReader.close();
    socket.close();
  }

  public static void main(String[] args) {
    Client server = new Client(5000);
    try {
      server.listen();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}