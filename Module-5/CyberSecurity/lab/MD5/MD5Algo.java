import java.nio.charset.StandardCharsets;


public class MD5Algo {
    private int A = 0x67452301;
    private int B = 0xEFCDAB89;
    private int C = 0x98BADCFE;
    private int D = 0x10325476;


    private int[] T = new int[64];
    private int[] m = new int[16];


    public MD5Algo() {
        initializeT();
    }


    public static void main(String[] args) {
        String message = "Gourav Suram";
        System.out.println("Message : " + message); 
        MD5Algo md5 = new MD5Algo();
        byte[] messageBytes = message.getBytes(StandardCharsets.UTF_8);
        md5.calculateMD5(messageBytes);
        System.out.println(md5.toHexString(md5.A) + md5.toHexString(md5.B) +
                md5.toHexString(md5.C) + md5.toHexString(md5.D));
    }


    private void initializeT() {
        for (int i = 0; i < 64; i++) {
            T[i] = (int) (long) ((1L << 32) * Math.abs(Math.sin(i + 1)));
        }
    }


    private String toHexString(int value) {
        String hex = Integer.toHexString(value);
        while (hex.length() < 8) {
            hex = "0" + hex;
        }
        return hex;
    }


    public void calculateMD5(byte[] message) {
        int messageLength = message.length;
        int numBlocks = (messageLength + 8) / 64 + 1;
        int totalLength = numBlocks * 64;
        byte[] paddedMessage = new byte[totalLength];


        System.arraycopy(message, 0, paddedMessage, 0, messageLength);


        paddedMessage[messageLength] = (byte) 0x80;


        long messageBits = (long) messageLength * 8;
        for (int i = 0; i < 8; i++) {
            paddedMessage[totalLength - 8 + i] = (byte) (messageBits >>> (i * 8));
        }


        for (int i = 0; i < numBlocks; i++) {
            int startIndex = i * 64;
            for (int j = 0; j < 16; j++) {
                m[j] = (paddedMessage[startIndex + j * 4] & 0xFF) |
                        ((paddedMessage[startIndex + j * 4 + 1] & 0xFF) << 8) |
                        ((paddedMessage[startIndex + j * 4 + 2] & 0xFF) << 16) |
                        ((paddedMessage[startIndex + j * 4 + 3] & 0xFF) << 24);
            }


            int AA = A;
            int BB = B;
            int CC = C;
            int DD = D;


            for (int j = 0; j < 64; j++) {
                int F, g;
                if (j < 16) {
                    F = (B & C) | ((~B) & D);
                    g = j;
                } else if (j < 32) {
                    F = (D & B) | ((~D) & C);
                    g = (5 * j + 1) % 16;
                } else if (j < 48) {
                    F = B ^ C ^ D;
                    g = (3 * j + 5) % 16;
                } else {
                    F = C ^ (B | (~D));
                    g = (7 * j) % 16; 
                }


                int temp = D;
                D = C;
                C = B;
                B = B + Integer.rotateLeft((A + F + T[j] + m[g]), s[j]);
                A = temp;
            }


            A += AA;
            B += BB;
            C += CC;
            D += DD;
        }
    }


    private static final int[] s = {
            7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
            5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
            4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
            6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
    };
}

