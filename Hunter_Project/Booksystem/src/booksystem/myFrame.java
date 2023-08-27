package booksystem;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.sql.Date;
import java.sql.SQLException;

class MyJDialog extends JDialog {                           //创建新类继承JDialog类

    public MyJDialog(myFrame frame) {
        //实例化一个JDialog类对象，指定对话框的父窗体、窗体标题和类型
        super(frame, "JDialog窗体", true);

        Container container = getContentPane();                    //创建一个容器
        container.add(new JLabel("这是一个对话框"));           //在容器中添加标签
        setBounds(120, 120, 150, 100);          //设置对话框窗体大小
    }
}


public class myFrame extends JFrame
{
    JPanel root;
    static int flag=0;
    public void CreateJFrame() throws IOException ,Exception{                	//定义一个CreateJFrame()方法

        //this.getTitle();
        root = new JPanel();      //定义面板容器
        setContentPane(root);
        setLayout(null);         //设置面板为绝对布局
        root.setOpaque(false);

        Font fontButton = new Font("楷体",Font.PLAIN,20);
        Font fontButton2 = new Font("华文新魏",Font.PLAIN,17);

        //大标题
        JLabel top=new JLabel("高校教材管理系统");
        top.setBounds(200,20,450,50);
        Font f1 = new Font("隶书",Font.PLAIN,50);
        top.setForeground(Color.white);
        top.setFont(f1);
        root.add(top);

        //      结果输出框
        JTextArea show=new JTextArea("查询结果将显示于此");
        show.setBounds(50,170,700,200);
        show.setBackground(new Color(3, 17, 81 ));
        show.setBorder(BorderFactory.createLineBorder(new Color(15, 226, 221)));
        show.setForeground(Color.white);
        Font f4 = new Font("黑体",Font.PLAIN,16);
        show.setFont(f4);
        show.setEditable(false);
        root.add(show);

//        id
        JLabel JLid=new JLabel("书号：");
        JLid.setBounds(60,110,60,20);
        Font f2 = new Font("黑体",Font.PLAIN,20);
        JLid.setForeground(Color.white);
        JLid.setFont(f2);
        root.add(JLid);
//        书号输入框
        JTextField Input=new JTextField();
        Input.setBounds(120,105,300,30);
        Font f5 = new Font("黑体",Font.PLAIN,16);
        Input.setFont(f5);
        root.add(Input);
        //按钮书籍信息
        JButton messageButton = new JButton("书籍信息");        //定义显示文本内容的按钮
        messageButton.setBounds(440, 100, 100, 40);      //设置按钮显示位置和大小
        messageButton.setBorder(BorderFactory.createLineBorder(new Color(50, 4, 85)));
        messageButton.setBackground(new Color(1, 29, 109 ));
        messageButton.setFont(fontButton);
        messageButton.setForeground(Color.white);
        messageButton.addActionListener(new ActionListener() {//给按钮添加事件接收器
            @Override
            public void actionPerformed(ActionEvent e) {//接受到事件后,进行下面的处理
                String ans;
                try {
                    myJDBC.SeekInformation(Input.getText());
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
                show.setText(myJDBC.ans[0]);
                for(int i=1;i<20;i++)
                {
                    if(!myJDBC.ans[i].equals(""))
                        show.append(myJDBC.ans[0]);
                }

               // JOptionPane.showMessageDialog(null, "查询成功");// 弹出对话框,显示Hello World
            }
        });
        root.add(messageButton);
        //按钮订购记录
        JButton purchaseButton = new JButton("订购记录");        //定义显示文本内容的按钮
        purchaseButton.setBounds(550, 100, 100, 40);      //设置按钮显示位置和大小
        purchaseButton.setBorder(BorderFactory.createLineBorder(new Color(50, 4, 85)));
        purchaseButton.setBackground(new Color(1, 29, 109 ));
        purchaseButton.setFont(fontButton);
        purchaseButton.setForeground(Color.white);
        purchaseButton.addActionListener(new ActionListener() {//给按钮添加事件接收器
            @Override
            public void actionPerformed(ActionEvent e) {//接受到事件后,进行下面的处理
                try {
                    myJDBC.SeekPurchase(Input.getText());
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
                show.setText(myJDBC.ans[0]);
                for(int i=1;i<20;i++)
                {
                    if(!myJDBC.ans[i].equals(""))
                        show.append(myJDBC.ans[0]);
                }

                // JOptionPane.showMessageDialog(null, "查询成功");// 弹出对话框,显示Hello World
            }
        });
        root.add(purchaseButton);
        //按钮分发记录
        JButton distributeButton = new JButton("分发记录");        //定义显示文本内容的按钮
        distributeButton.setBounds(660, 100, 100, 40);      //设置按钮显示位置和大小
        distributeButton.setBorder(BorderFactory.createLineBorder(new Color(50, 4, 85)));
        distributeButton.setBackground(new Color(1, 29, 109 ));
        distributeButton.setFont(fontButton);
        distributeButton.setForeground(Color.white);
        distributeButton.addActionListener(new ActionListener() {//给按钮添加事件接收器
            @Override
            public void actionPerformed(ActionEvent e) {//接受到事件后,进行下面的处理
                try {
                    myJDBC.Seekdistribute(Input.getText());
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
                show.setText(myJDBC.ans[0]);
                for(int i=1;i<20;i++)
                {
                    if(!myJDBC.ans[i].equals(""))
                        show.append(myJDBC.ans[0]);
                }

                // JOptionPane.showMessageDialog(null, "查询成功");// 弹出对话框,显示Hello World
            }
        });
        root.add(distributeButton);

        //        信息输入框
        JTextField Input2=new JTextField();
        Input2.setBounds(90,400,600,30);
        Input2.setFont(f5);
        root.add(Input2);

//        增加书目
        JButton addInfButton = new JButton("增加书籍信息");        //定义显示文本内容的按钮
        addInfButton.setBounds(150, 440, 110, 40);      //设置按钮显示位置和大小
        addInfButton.setBorder(BorderFactory.createLineBorder(new Color(50, 4, 85)));
        addInfButton.setBackground(new Color(1, 29, 109 ));
        addInfButton.setFont(fontButton2);
        addInfButton.setForeground(Color.white);
        addInfButton.addActionListener(new ActionListener() {//给按钮添加事件接收器
            @Override
            public void actionPerformed(ActionEvent e) {//接受到事件后,进行下面的处理
                String id=Input.getText();

                String sen=Input2.getText();
                String[] a=sen.split(" ");
                int x=Integer.parseInt(a[3]);
                if(id.length()!=14)
                {
                    System.out.println("书号不符合规范！");
                    JOptionPane.showMessageDialog(null, "书号不符合规范！");
                    return;
                }
                System.out.println(id+" "+a[0]+" "+a[1]+" "+a[2]+" "+x);
                try {
                    myJDBC.AddInformation(id,a[0],a[1],a[2],(short)x);
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
                JOptionPane.showMessageDialog(null, "添加成功");// 弹出对话框,显示Hello World
            }
        });
        root.add(addInfButton);

        //        添加采购
        JButton addPurButton = new JButton("添加采购记录");        //定义显示文本内容的按钮
        addPurButton.setBounds(270, 440, 110, 40);      //设置按钮显示位置和大小
        addPurButton.setBorder(BorderFactory.createLineBorder(new Color(50, 4, 85)));
        addPurButton.setBackground(new Color(1, 29, 109 ));
        addPurButton.setFont(fontButton2);
        addPurButton.setForeground(Color.white);
        addPurButton.addActionListener(new ActionListener() {//给按钮添加事件接收器
            @Override
            public void actionPerformed(ActionEvent e) {//接受到事件后,进行下面的处理
                String id=Input.getText();

                String sen=Input2.getText();
                String[] a=sen.split(" ");
                String[] da=a[1].split("-");
                int x0=Integer.parseInt(a[0]);
                int x2=Integer.parseInt(a[2]);
                int y=Integer.parseInt(da[0]);
                int m=Integer.parseInt(da[1]);
                int d=Integer.parseInt(da[2]);
                Date date=new Date(y-1900,m,d);
                try {
                    myJDBC.AddPurchase(id,x0,date,x2);
                    myJDBC.UpdateInformation(id,"number=number+"+x2);
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }

                JOptionPane.showMessageDialog(null, "添加成功");// 弹出对话框,显示Hello World
            }
        });
        root.add(addPurButton);

        //        添加分发
        JButton addDisButton = new JButton("添加分发记录");        //定义显示文本内容的按钮
        addDisButton.setBounds(390, 440, 110, 40);      //设置按钮显示位置和大小
        addDisButton.setBorder(BorderFactory.createLineBorder(new Color(50, 4, 85)));
        addDisButton.setBackground(new Color(1, 29, 109 ));
        addDisButton.setFont(fontButton2);
        addDisButton.setForeground(Color.white);
        addDisButton.addActionListener(new ActionListener() {//给按钮添加事件接收器
            @Override
            public void actionPerformed(ActionEvent e) {//接受到事件后,进行下面的处理
                String id=Input.getText();

                String sen=Input2.getText();
                String[] a=sen.split(" ");
                String[] da=a[0].split("-");
                int x1=Integer.parseInt(a[1]);
                int y=Integer.parseInt(da[0]);
                int m=Integer.parseInt(da[1]);
                int d=Integer.parseInt(da[2]);
                Date date=new Date(y-1900,m,d);
                try {
                    myJDBC.Adddistribute(id,date,x1);
                    myJDBC.UpdateInformation(id,"number=number-"+x1);
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
                JOptionPane.showMessageDialog(null, "添加成功");// 弹出对话框,显示Hello World
            }
        });
        root.add(addDisButton);

        //        更新书目
        JButton updateInfButton = new JButton("更新书籍信息");        //定义显示文本内容的按钮
        updateInfButton.setBounds(510, 440, 110, 40);      //设置按钮显示位置和大小
        updateInfButton.setBorder(BorderFactory.createLineBorder(new Color(50, 4, 85)));
        updateInfButton.setBackground(new Color(1, 29, 109 ));
        updateInfButton.setFont(fontButton2);
        updateInfButton.setForeground(Color.white);
        updateInfButton.addActionListener(new ActionListener() {//给按钮添加事件接收器
            @Override
            public void actionPerformed(ActionEvent e) {//接受到事件后,进行下面的处理

                try {
                    myJDBC.UpdateInformation(Input.getText(),Input2.getText());
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
                JOptionPane.showMessageDialog(null, "修改成功");// 弹出对话框,显示Hello World
            }
        });
        root.add(updateInfButton);

        //        删除书目
        JButton delInfButton = new JButton("删除书目");        //定义显示文本内容的按钮
        delInfButton.setBounds(510, 500, 100, 40);      //设置按钮显示位置和大小
        delInfButton.setBorder(BorderFactory.createLineBorder(new Color(50, 4, 85)));
        delInfButton.setBackground(new Color(1, 29, 109 ));
        delInfButton.setFont(fontButton2);
        delInfButton.setForeground(Color.white);
        delInfButton.addActionListener(new ActionListener() {//给按钮添加事件接收器
            @Override
            public void actionPerformed(ActionEvent e) {//接受到事件后,进行下面的处理

                try {
                    myJDBC.DelInformation(Input.getText());
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
                JOptionPane.showMessageDialog(null, "删除成功");// 弹出对话框,显示Hello World
            }
        });
        root.add(delInfButton);

//        提示信息
        JLabel text1=new JLabel("1.增加书籍时候，请按照（书名 出版社 类型 数量）的顺序添加，并以空格间隔");
        text1.setBounds(20,490,410,12);
        Font f3 = new Font("黑体",Font.PLAIN,11);
        text1.setFont(f3);
        text1.setForeground(Color.orange);
        root.add(text1);
        JLabel text2=new JLabel("2.添加订购记录时候，请按照（订货量 日期 到货量）的顺序添加，并以空格间隔");
        text2.setBounds(20,504,410,11);
        text2.setForeground(Color.orange);
        text2.setFont(f3);
        root.add(text2);
        JLabel text3=new JLabel("3.添加分发记录时候，请按照（日期 数量）的顺序添加，并以空格间隔");
        text3.setBounds(20,518,410,11);
        text3.setForeground(Color.orange);
        text3.setFont(f3);
        root.add(text3);
        JLabel text4=new JLabel("4.可修改的值有：name press type number，多值修改请用&连接");
        text4.setBounds(20,532,410,11);
        text4.setForeground(Color.orange);
        text4.setFont(f3);
        root.add(text4);

//        背景设置
        ImageIcon image = new ImageIcon(ImageIO.read(new File("F:\\课程设计\\Booksystem\\img\\background1.jpg")));
        JLabel background=new JLabel(image);
        background.setBounds(0,0,800,600);
        root.add(background,JLayeredPane.DEFAULT_LAYER);

        //设置窗口风格
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(400,100,800,600);
        setVisible(true);
    }

    public static void main(String args[]) throws IOException,Exception{

            //在主方法中调用createJFrame()方法
            myJDBC.init();
            myFrame mainWindow=new myFrame();
            mainWindow.setTitle("高校教材管理系统");
            mainWindow.CreateJFrame();
            myJDBC.release();

    }
}
