package booksystem;
import java.sql.*;

public class myJDBC {
    public static Connection conn;
    //public static Statement stmt;
    public static PreparedStatement pstmt;
    public static ResultSet res;

    public static String[] ans=new String[20];
    //初始化，连接到数据库

    //初始化，连接到数据库
    public static void init() throws Exception{
        //注册驱动,mysql5之后，该注册语句可以省略不写
        Class.forName("com.mysql.cj.jdbc.Driver");

        //获取连接
//       url格式：jdbc:mysql://IP地址:端口号/数据库名称?参数键值对1&参数键值对2
//       useServerPrepStmts=true开启预编译
        String url="jdbc:mysql://localhost:3306/book_system?useServerPrepStmts=true";
        String username="root";
        String password="123456";

//        获取sql对象
        conn= DriverManager.getConnection(url,username,password);
    }
    //    收尾工作，释放资源
    public static void release ()throws Exception{
//         释放资源
        res.close();
        //stmt.close();
        conn.close();
        pstmt.close();

    }

    //    查找书籍的基本信息
    public static void SeekInformation(String SeekID)throws Exception{
        String sql="select * from book_information where ID=?";
        pstmt= conn.prepareStatement(sql);
//        设置？的值
        pstmt.setString(1,SeekID);
//        执行sql
        res=pstmt.executeQuery();

//        处理结果
        for(int j=0;j<20;j++)
        {
            ans[j]="";
        }
        int i=0;

        while (res.next()){
            String ID=res.getNString("ID");
            String name= res.getNString("name");
            String press= res.getNString("press");
            String type=res.getNString("type");
            int number= res.getInt("number");

            System.out.println("书号:"+ID+" 书名："+name+" 出版社："+press+" 类型："+type+" 数目："+number);
            ans[i]="书号:"+ID+" 书名："+name+" 出版社："+press+" 类型："+type+" 数目："+number+"\n";
            i++;
        }
    }
    //    更新书籍的基本信息
    public static void UpdateInformation(String SeekID,String order)throws Exception{
//        定义sql语句
        String sql="update book_information set "+order+" where ID=?";
        //       获取执行sql的对象Statement
        pstmt=conn.prepareStatement(sql);

        pstmt.setString(1,SeekID);
        //       执行sql
        int count=pstmt.executeUpdate();
        if(count!=0)
            System.out.println("update success!");
        else
        {
            System.out.println("something wrong!");
        }
    }
    //    删除书籍数据
    public static void DelInformation(String SeekID)throws Exception{
//        定义sql语句
        String sql="delete from book_information where ID=?";
        //       获取执行sql的对象Statement
        pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,SeekID);
        //       执行sql
        int count=pstmt.executeUpdate();
        if(count!=0)
            System.out.println("del success!");
        else
        {
            System.out.println("something wrong!");
        }
        //连带删除dis表中数据
        sql="delete from distribute where ID=?";
        pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,SeekID);
        count=pstmt.executeUpdate();
        //连带删除purchase表中数据
        sql="delete from purchase where ID=?";
        pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,SeekID);
        count=pstmt.executeUpdate();
    }
    //    增加新的书籍信息
    public static void AddInformation(String ID,String name,String press,String type,int number)throws Exception{
//        定义sql语句
        String sql="insert into book_information (ID,name,press,type,number) values (?,?,?,?,?)";

        //       获取执行sql的对象Statement
        pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,ID);
        pstmt.setString(2,name);
        pstmt.setString(3,press);
        pstmt.setString(4,type);
        pstmt.setInt(5,number);
        //       执行sql
        int count=pstmt.executeUpdate();
        if(count!=0)
        {
            System.out.println("update success!");
            System.out.println(count);
        }
        else
        {
            System.out.println("something wrong!");
        }
    }

    //    查询采购表
    public static void SeekPurchase(String SeekID)throws Exception{

        String sql="select * from purchase where (ID=?)";
        pstmt= conn.prepareStatement(sql);
//        设置？的值
        pstmt.setString(1,SeekID);
        // pstmt.setDate(2,SeekDate);
//        执行sql
        res=pstmt.executeQuery();
//        处理结果
        for(int j=0;j<20;j++)
        {
            ans[j]="";
        }
        int i=0;
        while (res.next()){
            String ID=res.getNString("ID");
            int order_quantity= res.getInt("order_quantity");
            java.sql.Date date= res.getDate("date");
            int volume_arrived=res.getInt("volume_arrived");

            System.out.println("书号："+ID+" 订购量："+order_quantity+" 日期："+date+" 实际到货量："+volume_arrived);
            ans[i]="书号："+ID+" 订购量："+order_quantity+" 日期："+date+" 实际到货量："+volume_arrived+"\n";
            i++;
        }
    }
    //    新增采购记录
    public static void AddPurchase(String ID,int order_quantity,java.sql.Date date,int volume_arrived)throws Exception{
//        定义sql语句
        String sql="insert into purchase (ID,order_quantity,date,volume_arrived) values (?,?,?,?)";
        //       获取执行sql的对象Statement
        pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,ID);
        pstmt.setInt(2,order_quantity);
        pstmt.setDate(3,date);
        pstmt.setInt(4,volume_arrived);
        //       执行sql
        int count=pstmt.executeUpdate();
        if(count!=0)
        {
            System.out.println("update success!");
            System.out.println(count);
        }
        else
        {
            System.out.println("something wrong!");
        }
    }

    //    查询分发表
    public static void Seekdistribute(String SeekID)throws SQLException{

        String sql="select * from distribute where (ID=?)";
        pstmt= conn.prepareStatement(sql);
//        设置？的值
        pstmt.setString(1,SeekID);
//        执行sql
        res=pstmt.executeQuery();
//        处理结果
        for(int j=0;j<20;j++)
        {
            ans[j]="";
        }
        int i=0;
        while (res.next()){
            String ID=res.getNString("ID");
            java.sql.Date date= res.getDate("date");
            int numvber=res.getInt("numvber");

            System.out.println("书号:"+ID+" 日期："+date+" 分发数目："+numvber);
            ans[i]="书号:"+ID+" 日期："+date+" 分发数目："+numvber+"\n";
            i++;
        }
    }
    //    新增分发记录
    public static void Adddistribute(String ID,java.sql.Date date,int number)throws Exception{
//        定义sql语句
        String sql="insert into distribute (ID,date,numvber) values (?,?,?)";
        //       获取执行sql的对象Statement
        pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,ID);
        pstmt.setDate(2,date);
        pstmt.setInt(3,number);
        //       执行sql
        int count=pstmt.executeUpdate();
        if(count!=0)
        {
            System.out.println("update success!");
            System.out.println(count);
        }
        else
        {
            System.out.println("something wrong!");
        }
    }

   public static void main(String[] args) throws Exception{

//      连接到数据库

            init();

//        增减采购记录
//        AddPurchase("ISBN1111111111",12,new Date(2020-1900,1,12),232);
//        删除书籍数据
//           DelInformation("ISBN1111111111");
//        更新书籍信息
//        UpdateInformation("ISBN7302120301","number=510");
//        SeekInformation("ISBN7302120301");
//        增加新的书籍
        AddInformation("ISBN1111111111","test","ggg","222",10);
//        通过书号查询
        SeekInformation("ISBN1111111111");
       DelInformation("ISBN1111111111");
//        SeekPurchase("ISBN7302120301");

//            Seekdistribute("ISBN7302120301");

//        释放资源
            release();

    }
}

