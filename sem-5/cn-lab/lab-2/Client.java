import java.net.ConnectException;
import java.net.Socket;
import java.util.Scanner;
import java.io.DataOutputStream;
import java.io.IOException;

class Client {
  private Socket socket;
  private Scanner input;
  private DataOutputStream output;
  private boolean connectionEstablished = false;

  public Client(String address, int port) {
    try {
      // Initialise socket and IO Streams
      connectionEstablished = false;
      socket = new Socket(address, port);
      System.out.println("Connected");

      input = new Scanner(System.in);
      output = new DataOutputStream(socket.getOutputStream());
      connectionEstablished = true;
    } catch (Exception e) {
      System.out.println(e);
    }
  }

  public void connect() throws ConnectException, IOException {
    if (!connectionEstablished) {
      // socket not setup
      throw new ConnectException("Connection Not Established");
    }
    String line = "";
    while (!line.equals("exit")) {
      try {
        line = input.nextLine();
        output.writeUTF(line);
      } catch (Exception e) {
        System.out.println(e);
        break;
      }
    }

    input.close();
    output.close();
  }

  public static void main(String[] args) {
    Client c = new Client("127.0.0.1", 5000);
    try {
      c.connect();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
