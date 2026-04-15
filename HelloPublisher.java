import javax.xml.ws.Endpoint;

public class HelloPublisher {
    public static void main(String[] args) {
        String url = "http://localhost:8080/hello";
        Endpoint.publish(url, new HelloService());
        System.out.println("SOAP Service running at: " + url + "?wsdl");
    }
}
