package booksystem;

import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;


import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import static booksystem.myFrame.flag;


public class log extends JFrame {
    JTextField txtname = new JTextField("admin");
    JPasswordField txtpass = new JPasswordField();
    JButton bl = new JButton("登录");
    JButton bg = new JButton("关闭");

    //构造无参构造器把主要的方法放在构造器里,然后在main方法里面调
    public log() {
        setBounds(25, 25, 250, 250);
        Container c = getContentPane();
        c.setLayout(new GridLayout(4, 2, 10, 10));
        c.add(new JLabel("用户名"));
        c.add(txtname);
        c.add(new JLabel("密码"));
        c.add(txtpass);
        c.add(bl);
        c.add(bg);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);

        bg.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        //注意：此处是匿名内部类
        bl.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                String name = txtname.getText();
                String pass = txtpass.getText();
                if (name.equals("admin") && pass.equals("1234")) {
                    System.out.println("登陆成功");
                    flag=1;
                    setVisible(false);
                    dispose();
                } else {
                    System.out.println("登录失败");
                }
            }

        });

    }

    public static void dosome()throws IOException,Exception
    {
        myJDBC.init();
        myFrame mainWindow=new myFrame();
        mainWindow.setTitle("高校教材管理系统");
        mainWindow.CreateJFrame();
        myJDBC.release();
    }

    public static void main(String[] args) throws IOException,Exception {
        dosome();
        new log();
    }
}

