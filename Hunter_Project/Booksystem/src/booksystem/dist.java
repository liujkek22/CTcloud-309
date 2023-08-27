package booksystem;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet("/dist")
public class dist extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String name=req.getParameter("name");
        try {
            System.out.println(name);
            myJDBC.init();
            System.out.println("init finish");
            myJDBC.Seekdistribute(name);
            myJDBC.release();
        }catch (Exception e) {throw new RuntimeException(e);}
    }
}
