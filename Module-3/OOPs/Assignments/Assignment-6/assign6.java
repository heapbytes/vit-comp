import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.sql.ResultSet;

public class assign6 extends JFrame implements ActionListener
{

  JFrame jf;
  JLabel l1,l2,l3,l4,l5,l6,l7;
  JTextField t1,t3,t4,t5,t6;
  JPasswordField t2;
  JComboBox <String> c1;
  Connection con;
  PreparedStatement ps;
  Statement stmt;
  ResultSet rs;
  JRadioButton r1,r2,r3;
  JButton b0,b1,b2,b3,b4;
  assign6()
  {
      jf = new JFrame();

      l1=new JLabel("Profile");
      l1.setFont(new Font("Times New Roman",Font.BOLD,25));
      l1.setHorizontalAlignment(JLabel.CENTER);
      l1.setBounds(0,50,500,40);l1.setForeground(Color.black);
      jf.add(l1);


      l2=new JLabel("Username: ");
      l2.setFont(new Font("Times New Roman",Font.BOLD,20));
      l2.setBounds(50,100,150,30);l2.setForeground(Color.black);
      jf.add(l2);

      t1=new JTextField(22);
      t1.setBounds(200,105,250,25);t1.setToolTipText("Enter username");
      t1.setFont(new Font("Arial", Font.PLAIN, 15));jf.add(t1);t1.setForeground(Color.black);

      l3=new JLabel("Password: ");
      l3.setFont(new Font("Times New Roman",Font.BOLD,20));
      l3.setBounds(50,140,150,30);l3.setForeground(Color.black);
      jf.add(l3);

      t2=new JPasswordField();
      t2.setBounds(200,145,250,25);t2.setToolTipText("Enter Password");
      t2.setFont(new Font("Arial", Font.PLAIN, 15));jf.add(t2);t2.setForeground(Color.black);

      l4=new JLabel("PRN No: ");
      l4.setFont(new Font("Times New Roman",Font.BOLD,20));
      l4.setBounds(50,180,150,30);l4.setForeground(Color.black);
      jf.add(l4);

      t3=new JTextField(22);
      t3.setBounds(200,185,250,25);t3.setToolTipText("Enter PRN No");
      t3.setFont(new Font("Arial", Font.PLAIN, 15));jf.add(t3);t3.setForeground(Color.black);

      l5=new JLabel("Division: ");
      l5.setFont(new Font("Times New Roman",Font.BOLD,20));
      l5.setBounds(50,220,150,30);l5.setForeground(Color.black);
      jf.add(l5);

      // Combo Box for Division
      c1 = new JComboBox<>();
      c1.addItem("Select Division");
      c1.addItem("A");
      c1.addItem("B");
      c1.addItem("C");
      c1.addItem("D");


      c1.setBounds(200,225,250,25);c1.setToolTipText("Select Division");
      c1.setFont(new Font("Arial", Font.PLAIN, 15));jf.add(c1);c1.setForeground(Color.black);


      l6=new JLabel("Gender: ");
      l6.setFont(new Font("Times New Roman",Font.BOLD,20));
      l6.setBounds(50,260,150,30);l6.setForeground(Color.black);
      jf.add(l6);

      r1 = new JRadioButton("male");
      r1.setBounds(200,265,55,30);r1.setForeground(Color.black);
      jf.add(r1);

      r2 = new JRadioButton("female");
      r2.setBounds(260,265,75,30);r2.setForeground(Color.black);
      jf.add(r2);

      r3 = new JRadioButton("other");
      r3.setBounds(330,265,65,30);r3.setForeground(Color.black);
      jf.add(r3);

      ButtonGroup bg=new ButtonGroup();
      bg.add(r1);bg.add(r2);bg.add(r3);

      // Add button
      b0 = new JButton("Search");
      b0.setBounds(50,320,90,30);b0.setToolTipText("Add Record");
      b0.setFont(new Font("Arial", Font.PLAIN, 15));jf.add(b0);b0.setForeground(Color.black);
      b0.addActionListener(this);

      b1 = new JButton("Add");
      b1.setBounds(150,320,90,30);b1.setToolTipText("Add Record");
      b1.setFont(new Font("Arial", Font.PLAIN, 15));jf.add(b1);b1.setForeground(Color.black);
      b1.addActionListener(this);

      b2 = new JButton("Update");
      b2.setBounds(250,320,90,30);b2.setToolTipText("Add Record");
      b2.setFont(new Font("Arial", Font.PLAIN, 15));jf.add(b2);b2.setForeground(Color.black);
      b2.addActionListener(this);

      b3 = new JButton("Delete");
      b3.setBounds(350,320,90,30);b1.setToolTipText("Add Record");
      b3.setFont(new Font("Arial", Font.PLAIN, 15));jf.add(b3);b3.setForeground(Color.black);
      b3.addActionListener(this);


      jf.setSize(500, 500);
      jf.setLayout(null);
      jf.setVisible(true);
    }

  public void actionPerformed(ActionEvent ae){
    if(ae.getSource()==b0)
    {
      String username = t1.getText();
      String qual = " ";

      if(((t1.getText()).equals("")))
    {
        JOptionPane.showMessageDialog(this,"Please enter username !","Warning!!!",JOptionPane.WARNING_MESSAGE);
      }
      else
      {
        try{
          int foundrec = 0;
          Class.forName("org.mariadb.jdbc.Driver");
          con=DriverManager.getConnection("jdbc:mariadb://localhost:3306/oopassign","gourav", "mypassword");
          System.out.println("Connected to database.");
          ps=con.prepareStatement("SELECT * FROM profiles WHERE username=?;");
          ps.setString(1, username);
          rs=ps.executeQuery();
          while(rs.next())
        {
            t1.setText(rs.getString(2));
            t2.setText(rs.getString(3));
            t3.setText(rs.getString(4));
            c1.setSelectedItem(rs.getString(5));
            qual = rs.getString(6);
            if (qual.equals("male")) {
              r1.setSelected(true);
            }
            else if (qual.equals("female")) {
              r2.setSelected(true);
            }
            else{
              r3.setSelected(true);
            }
            foundrec = 1;
          }
          if (foundrec == 0)
        {
            JOptionPane.showMessageDialog(null,"Record is not available","Dialog",JOptionPane.WARNING_MESSAGE);
          }
          con.close();
        }

        catch(SQLException se)
      {
          System.out.println(se);
          JOptionPane.showMessageDialog(null,"SQL Error:"+se);
        }
        catch(Exception e)
      {
          System.out.println(e);
          JOptionPane.showMessageDialog(null,"Error:"+e);
        }
      }
    }

    if(ae.getSource()==b1)
    {
      String username = t1.getText();
      String password = new String(t2.getPassword());
      String PRN_no = t3.getText();
      String Division = (String)c1.getSelectedItem();
      String qual = " ";
      if (r1.isSelected()) {

        qual = "male";
      }

      else if (r2.isSelected()) {

  qual = "female";
      }
      else {

        qual = "other";
      }

    if(((t1.getText()).equals(""))||((t2.getPassword()).equals(""))||((t3.getText()).equals(""))||((c1.getSelectedItem()).equals(""))||((qual).equals("")))
      {
        JOptionPane.showMessageDialog(this,"* Detail are Missing !","Warning!!!",JOptionPane.WARNING_MESSAGE);
      }
      else
      {
        try
        {
          Class.forName("org.mariadb.jdbc.Driver");
          con=DriverManager.getConnection("jdbc:mariadb://localhost:3306/oopassign","gourav", "mypassword");
          System.out.println("Connected to database.");
          ps=con.prepareStatement("insert into profiles (username,password,PRN_no,`div`,gender)values(?,?,?,?,?)");
          ps.setString(1,t1.getText());
          ps.setString(2,password);
          ps.setString(3,t3.getText());
          ps.setString(4,Division);
          ps.setString(5,qual);
          ps.executeUpdate();

          int reply=JOptionPane.showConfirmDialog(null,"Profile Is added successfully! Do you want to another entry","Profile Added",JOptionPane.YES_NO_OPTION);

          if (reply == JOptionPane.YES_OPTION)
        {
            jf.setVisible(false);
            new assign6();
          }
          else if (reply == JOptionPane.NO_OPTION)
                    {
  jf.setVisible(false);
}
          con.close();
        }

        catch(SQLException se)
      {
          System.out.println(se);
          JOptionPane.showMessageDialog(null,"SQL Error:"+se);
        }
catch(Exception e)
      {
          System.out.println(e);
          JOptionPane.showMessageDialog(null,"Error:"+e);
        }
      }
}

    if(ae.getSource()==b2)
{
String username = t1.getText();
      String password = new String(t2.getPassword());
      String PRN_no = t3.getText();
      String Division = (String)c1.getSelectedItem();
      String qual = " ";
      if (r1.isSelected()) {

        qual = "male";
      }

      else if (r2.isSelected()) {

        qual = "female";
      }
      else {

        qual = "other";
      }

    if(((t1.getText()).equals(""))||((t2.getPassword()).equals(""))||((t3.getText()).equals(""))||((c1.getSelectedItem()).equals(""))||((qual).equals("")))
      {
        JOptionPane.showMessageDialog(this,"* Detail are Missing !","Warning!!!",JOptionPane.WARNING_MESSAGE);
      }
      else
      {
        try
        {
          Class.forName("org.mariadb.jdbc.Driver");
          con=DriverManager.getConnection("jdbc:mariadb://localhost:3306/oopassign","gourav", "mypassword");
          System.out.println("Connected to database.");
          ps=con.prepareStatement("update profiles set password=?, PRN_no=?, `div`=?, gender=? where username=?");
          ps.setString(5,t1.getText());
          ps.setString(1,password);
          ps.setString(2,t3.getText());
          ps.setString(3,Division);
          ps.setString(4,qual);
          ps.executeUpdate();

          int reply=JOptionPane.showConfirmDialog(null,"Profile Is updated successfully!","Profile Updated",JOptionPane.CLOSED_OPTION);

          if (reply == JOptionPane.CLOSED_OPTION)
        {
            jf.setVisible(false);
          }

          con.close();
        }

        catch(SQLException se)
      {
          System.out.println(se);
          JOptionPane.showMessageDialog(null,"SQL Error:"+se);
        }
        catch(Exception e)
      {
          System.out.println(e);
JOptionPane.showMessageDialog(null,"Error:"+e);
        }
      }
    }

    if(ae.getSource()==b3)
    {
      String username = t1.getText();
      String password = new String(t2.getPassword());
      String PRN_no = t3.getText();
      String Division = (String)c1.getSelectedItem();
      String qual = " ";
      if (r1.isSelected()) {

        qual = "male";
      }

      else if (r2.isSelected()) {

        qual = "female";
      }
      else {

        qual = "other";
      }

    if(((t1.getText()).equals("")))
      {
        JOptionPane.showMessageDialog(this,"* Detail are Missing !","Warning!!!",JOptionPane.WARNING_MESSAGE);
      }
      else
      {
        try
        {
          Class.forName("org.mariadb.jdbc.Driver");
          con=DriverManager.getConnection("jdbc:mariadb://localhost:3306/oopassign","gourav", "mypassword");
          System.out.println("Connected to database.");
          ps=con.prepareStatement("delete from profiles where username = ?");
          ps.setString(1,t1.getText());
          ps.executeUpdate();

          int reply=JOptionPane.showConfirmDialog(null,"Profile Is Deleted successfully!","Profile Deleted",JOptionPane.CLOSED_OPTION);

          if (reply == JOptionPane.CLOSED_OPTION)
        {
            jf.setVisible(false);
            new assign6();
          }

          con.close();
        }

        catch(SQLException se)
      {
System.out.println(se);
          JOptionPane.showMessageDialog(null,"SQL Error:"+se);
        }
        catch(Exception e)
      {
          System.out.println(e);
          JOptionPane.showMessageDialog(null,"Error:"+e);
        }
      }
    }
  }

  public static void main(String[] args) {
new assign6();
  }
}
