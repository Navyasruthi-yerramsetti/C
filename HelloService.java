import javax.jws.WebService;

@WebService(targetNamespace="http://soapdemo/")
public class HelloService {
    public String sayHello(String name) {
        return "Hello " + name + ", welcome to SOAP Web Service!";
    }
}
