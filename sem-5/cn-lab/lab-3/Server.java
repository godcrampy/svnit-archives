import java.io.*;
import java.net.*;

public class Server {
  private ServerSocket server;
  private Socket socket;
  private PrintStream printStream;
  private BufferedReader clientReader;
  private BufferedReader keyReader;
  private boolean serverStarted = false;

  public Server(int port) {
    serverStarted = false;
    try {
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
    printStream = new PrintStream(socket.getOutputStream());
    clientReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    keyReader = new BufferedReader(new InputStreamReader(System.in));

    while (true) {
      String str, str1;

      // repeat as long as the client
      // read from client
      while ((str = clientReader.readLine()) != null) {
        System.out.println(str);
        str1 = keyReader.readLine();

        // send to client
        printStream.println(str1);
      }

      // close connection
      printStream.close();
      clientReader.close();
      keyReader.close();
      socket.close();
      server.close();

      // terminate application
      System.exit(0);

    }
  }

  public static void main(String[] args) {
    Server server = new Server(5000);
    try {
      server.listen();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}