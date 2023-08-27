package booksystem;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import java.sql.*;
import java.util.Scanner;

public class demo01  {
    public static void BookSearch() throws Exception{
        System.out.println("请输入书号：");
        Scanner xx = new Scanner( System.in );
        String id=xx.next();
        myJDBC.SeekInformation(id);
    }
    public static void PurchaseSearch() throws Exception{
        System.out.println("请输入书号：");
        Scanner xx = new Scanner( System.in );
        String id=xx.next();
        myJDBC.SeekPurchase(id);
    }
    public static void DistSearch() throws Exception{
        System.out.println("请输入书号：");
        Scanner xx = new Scanner( System.in );
        String id=xx.next();
        myJDBC.Seekdistribute(id);
    }
    public static void AddInf() throws Exception{
        Scanner xx = new Scanner( System.in );

        System.out.println("请输入书号：");
        String id=xx.next();
        if(id.getBytes().length!=14||!id.substring(0,4).equals("ISBN"))
            System.out.println("请输入正确的书号！！");
        System.out.println("请输入书名：");
        String name=xx.next();
        System.out.println("请输入出版社：");
        String press=xx.next();
        System.out.println("请输入类型：");
        String type=xx.next();
        System.out.println("请输入数量：");
        short num=xx.nextShort();
        myJDBC.AddInformation(id,name,press,type,num);
        System.out.println("书籍信息添加成功");
    }
    public static void DelInf() throws Exception{
        System.out.println("若删除，则采购记录和分发记录也将一并删除，是否继续：Y/N");
        Scanner xx = new Scanner( System.in );
        String id=xx.next();
        if(id.equals("N")||id.equals("n"))
            return;
        System.out.println("请输入书号：");
        myJDBC.DelInformation(id);
    }

    public static void UpdateInf() throws Exception{
        Scanner xx = new Scanner( System.in );
        System.out.println("请输入书号：");
        String id=xx.next();
        System.out.println("请输入要修改的数据（如：number=100）：");
        String order=xx.next();
        myJDBC.UpdateInformation(id,order);
    }

    public static void AddPur() throws Exception{
        Scanner xx = new Scanner( System.in );

        System.out.println("请输入书号：");
        String id=xx.next();
        System.out.println("请输入订购量：");
        short quan=xx.nextShort();
        System.out.println("请输入日期(年)：");
        short y=xx.nextShort();
        System.out.println("请输入日期(月)：");
        short m=xx.nextShort();
        System.out.println("请输入日期(日)：");
        short d=xx.nextShort();
        System.out.println("请输入到货量：");
        short arr=xx.nextShort();

        Date date=new Date(y-1900,m,d);

        myJDBC.AddPurchase(id,quan,date,arr);
        myJDBC.UpdateInformation(id,"num=num+"+arr);
    }

    public static void AddDist() throws Exception{
        Scanner xx = new Scanner( System.in );

        System.out.println("请输入书号：");
        String id=xx.next();
        System.out.println("请输入日期(年)：");
        short y=xx.nextShort();
        System.out.println("请输入日期(月)：");
        short m=xx.nextShort();
        System.out.println("请输入日期(日)：");
        short d=xx.nextShort();
        System.out.println("请输入到货量：");
        short num=xx.nextShort();

        Date date=new Date(y-1900,m,d);

        myJDBC.Adddistribute(id,date,num);
        myJDBC.UpdateInformation(id,"num=num-"+num);

    }

    public static void main(String[] args) throws Exception
    {
        int flag=0;
//      连接到数据库
        myJDBC.init();
        System.out.println("=============================================");
        System.out.println("=============================================");
        System.out.println("===========欢迎来到高校书籍管理系统===============");
        System.out.println("===================菜单=======================");
        System.out.println("             1.书籍基本信息查询                 ");
        System.out.println("             2.采购记录查询");
        System.out.println("             3.分发记录查询");
        System.out.println("             4.增加新的书籍信息");
        System.out.println("             5.删除书籍信息");
        System.out.println("             6.修改书籍信息");
        System.out.println("             7.增加新的采购记录");
        System.out.println("             8.增加新的分发记录");
        System.out.println("             0.退出系统");

        Scanner xx = new Scanner( System.in );
        System.out.println("请输入指令：");
        flag= xx.nextInt();
        while (flag!=0)
        {
            switch (flag){
                case 1: BookSearch();break;
                case 2: PurchaseSearch();break;
                case 3: DistSearch();break;
                case 4: AddInf(); break;
                case 5: DelInf(); break;
                case 6: UpdateInf();break;
                case 7: AddPur();break;
                case 8: AddDist();break;
                case 0: break;
                default:System.out.println("请输入正确的命令！");break;
            }

            System.out.println("请输入下一指令：");
            flag= xx.nextInt();
        }

        System.out.println("已退出书籍管理系统");
//        释放资源
        myJDBC.release();
    }
}
