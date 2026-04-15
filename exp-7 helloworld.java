import java.io.IOException; 
import javax.servlet.http.*; 
public class HelloServlet extends HttpServlet { 
 public void doGet(HttpServletRequest req, HttpServletResponse resp) 
 throws IOException { 
 resp.setContentType("text/plain"); 
 resp.getWriter().println("Hello World from Google App Engine (Java - Local)");  } 
}
