package booksystem;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@WebServlet("/index-servlet")
public class login extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException{
        //        设置请求的编码格式
        req.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html;charset=UTF-8");

        //        获取参数（得到要下载的文件名）
        String name=req.getParameter("username");
        String pwd=req.getParameter("password");
        System.out.println(name);
        System.out.println(pwd);
        if(name.equals("111")&&pwd.equals("111"))
        {
            System.out.println("密码正确");
//            resp.sendRedirect("login.html");
//            req.getRequestDispatcher("login.html").forward(req,resp);
//            req.getRequestDispatcher("login.jsp").forward(req,resp);
            resp.sendRedirect("login.jsp");
        }
        else
        {
            ServletOutputStream out=resp.getOutputStream();
            out.write("<h2>密码错误</h2>".getBytes(StandardCharsets.UTF_8));
            System.out.println("密码错误");
        }
        return ;
    }
}
