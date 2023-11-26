import javax.crypto.KeyAgreement;
import javax.crypto.interfaces.DHPublicKey;
import javax.crypto.spec.DHParameterSpec;
import java.security.*;
import java.util.Arrays;


public class DiffieHellman {
    public static void main(String[] args) throws Exception {


        KeyPair aliceKeyPair = generateKeyPair();
        PublicKey alicePublicKey = aliceKeyPair.getPublic();
        PrivateKey alicePrivateKey = aliceKeyPair.getPrivate();


        KeyPair bobKeyPair = generateKeyPair();
        PublicKey bobPublicKey = bobKeyPair.getPublic();
        PrivateKey bobPrivateKey = bobKeyPair.getPrivate();


        KeyAgreement aliceKeyAgreement = KeyAgreement.getInstance("DiffieHellman");
        aliceKeyAgreement.init(alicePrivateKey);
        aliceKeyAgreement.doPhase(bobPublicKey, true);


        KeyAgreement bobKeyAgreement = KeyAgreement.getInstance("DiffieHellman");
        bobKeyAgreement.init(bobPrivateKey);
        bobKeyAgreement.doPhase(alicePublicKey, true);


        byte[] aliceSharedSecret = aliceKeyAgreement.generateSecret();
        byte[] bobSharedSecret = bobKeyAgreement.generateSecret();


        System.out.println("Alice's shared secret: " + Arrays.toString(aliceSharedSecret));
        System.out.println("Bob's shared secret: " + Arrays.toString(bobSharedSecret));
        System.out.println("Shared secrets match: " + Arrays.equals(aliceSharedSecret, bobSharedSecret));
    }


    private static KeyPair generateKeyPair() throws Exception {
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("DiffieHellman");
        keyPairGenerator.initialize(1024);
        return keyPairGenerator.generateKeyPair();
    }
}


