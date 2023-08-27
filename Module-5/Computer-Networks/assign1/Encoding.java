import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Encoding extends JFrame implements ActionListener {

    int x1 = 300, x2 = 300, y1 = 100, y2 = 100;
    int[] baud;
    JTextField npData = new JTextField(12);
    JComboBox<String> techniques = null;
    JPanel drawPanel = new JPanel();

    public Encoding() {

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(1000, 400);
        setTitle("Line Encoding Visualization");
        initComponents();
    }

    private void initComponents() {

        JPanel topPanel = new JPanel();
        topPanel.add(new JLabel("Input Data:"));
        topPanel.add(npData);

        String[] list = {
            "Unipolar NRZ",
            "Polar NRZ",
            "NRZ Inverted",
            "Bipolar RZ",
            "Bipolar NRZ",
            "Manchester",
            "Differential Manchester"
        };

        techniques = new JComboBox<String>(list);
        topPanel.add(new JLabel("Technique: "));

        JButton encodeBtn = new JButton("Encode");
        JButton clrBtn = new JButton("Clear");

        topPanel.add(techniques);
        topPanel.add(encodeBtn);
        encodeBtn.addActionListener(this);
        topPanel.add(clrBtn);
        clrBtn.addActionListener(this);

        drawPanel.setBackground(Color.WHITE);
        add(drawPanel);
        add(topPanel, BorderLayout.NORTH);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new Encoding().setVisible(true);
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("Encode")) {
            encode();
        } else if (e.getActionCommand().equals("Clear")) {
            repaint();
        }
    }

    private void drawLine(int x1, int y1, int x2, int y2) {

        drawPanel.getGraphics().drawLine(x1, y1, x2, y2);
    }

    private void clearPanel() {

        drawPanel.getGraphics().clearRect(0, 0, drawPanel.getWidth(), drawPanel.getHeight());
    }

    private void drawTechniqueName(String techniqueName) {

        drawPanel.getGraphics().setColor(Color.BLACK);
        drawPanel.getGraphics().drawString(techniqueName + " Encoding", 400, 40);
    }

    private void encodeUnipolarNRZ(char[] data) {

        baud = new int[data.length + 2];
        baud[0] = 0;
        baud[baud.length - 1] = 0;

        for (int i = 0; i < data.length; i++) {
            baud[i + 1] = data[i] == '1' ? 50 : 0;
        }

        draw(baud);
    }

    private void encodePolarNRZ(char[] data) {

        baud = new int[data.length + 2];
        baud[0] = 0;
        baud[baud.length - 1] = 0;

        for (int i = 0; i < data.length; i++) {
            baud[i + 1] = data[i] == '1' ? 50 : -50;
        }

        draw(baud);
    }

    private void encodeNRZInverted(char[] data) {

        baud = new int[data.length + 2];
        baud[0] = 0;
        baud[baud.length - 1] = 0;

        for (int i = 0; i < data.length; i++) {
            baud[i + 1] = data[i] == '1' ? -50 : 50;
        }

        draw(baud);
    }

    private void encodeBipolarRZ(char[] data) {

        baud = new int[(data.length * 2) + 1];
        baud[0] = 0;

        boolean flag = true;
        int loop = 1;

        for (char c : data) {
            if (c == '1') {
                baud[loop] = flag ? 50 : -50;
                baud[loop + 1] = 0;
                flag = !flag;
            } else {
                baud[loop] = 0;
                baud[loop + 1] = 0;
            }
            loop += 2;
        }

        draw(baud);
    }

    private void encodeBipolarNRZ(char[] data) {

        baud = new int[data.length + 2];
        baud[0] = 0;
        boolean flag = true;

        for (int i = 0; i < data.length; i++) {
            baud[i + 1] = data[i] == '1' ? (flag ? 50 : -50) : 0;
            flag = !flag;
        }

        draw(baud);
    }

    private void encodeManchester(char[] data) {
        baud = new int[(data.length * 2) + 2];
        baud[0] = 0;
        int loop = 1;

        for (char c : data) {
            if (c == '1') {
                baud[loop] = -50;
                baud[loop + 1] = 50;
            } else {
                baud[loop] = 50;
                baud[loop + 1] = -50;
            }
            loop += 2;
        }

        draw(baud);
    }

    private void encodeDifferentialManchester(char[] data) {

        baud = new int[(data.length * 2) + 2];
        baud[0] = 0;
        boolean flag = true;
        int loop = 1;

        for (char c : data) {
            if (c == '1') {
                baud[loop] = flag ? -50 : 50;
                baud[loop + 1] = flag ? 50 : -50;
                flag = !flag;
            } else {
                baud[loop] = flag ? 50 : -50;
                baud[loop + 1] = flag ? -50 : 50;
                flag = !flag;
            }
            loop += 2;
        }

        draw(baud);
    }

    private void encode() {

        clearPanel();
        char[] data = npData.getText().toCharArray();
        String selectedTechnique = (String) techniques.getSelectedItem();
        drawTechniqueName(selectedTechnique);

        switch (selectedTechnique) {
            case "Unipolar NRZ":
                encodeUnipolarNRZ(data);
                break;
            case "Polar NRZ":
                encodePolarNRZ(data);
                break;
            case "NRZ Inverted":
                encodeNRZInverted(data);
                break;
            case "Bipolar RZ":
                encodeBipolarRZ(data);
                break;
            case "Bipolar NRZ":
                encodeBipolarNRZ(data);
                break;
            case "Manchester":
                encodeManchester(data);
                break;
            case "Differential Manchester":
                encodeDifferentialManchester(data);
                break;
            default:
                break;
        }
    }

  private void draw(int[] baud) {

    x1 = 300;
    x2 = 300;
    y1 = 100;
    y2 = 100;
    
    for (int i = 0; i < baud.length; i++) {

        y2 = 100 - baud[i];
        drawLine(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
        x2 = x1 + 30;

        drawLine(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;

    }
  }
}

