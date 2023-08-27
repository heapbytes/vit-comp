import java.util.*;

public class DES {

	public static void main(String[] args) {
		int[] PT = {0,0,1,1,0,1,1,0},
		
		K = {0,0,1,0,0,1,0,1,1,1},
		P10 = {3,5,2,7,4,10,1,9,8,6},
		P8 = {6,3,7,4,8,5,10,9},
		P4 = {2,4,3,1},
		EP = {4,1,2,3,2,3,4,1},
		IP = {2,6,3,1,4,8,5,7},
		IPinverse = {4,1,3,5,7,2,8,6}; //IP inverse
		
		int[][] S0 = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}},
				S1 = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
		int[] p10=convert(P10, K);
		//LS-1
		LS1_5(p10);
		LS6_10(p10);
		int[] K1 = convert(P8, p10);							//KEY-1
		System.out.println("Key1 = " + Arrays.toString(K1) );

		//LS-2
		LS1_5(p10);		LS1_5(p10);
		LS6_10(p10);	LS6_10(p10);
		int[] K2 = convert(P8, p10);							//KEY-2
		System.out.println("Key2 = " + Arrays.toString(K2) );
		
		int[] ip = convert(IP,PT);
		int[] ep = convert(EP,Arrays.copyOfRange(ip, 4, 9));
		int[] xor = XOR(ep,K1);
		int[] s0s1 = S0S1(xor,S0,S1);
		int[] p4 = convert(P4, s0s1);
		int[] xor1 = XOR(p4, Arrays.copyOf(ip, 4));
		
		Swap(xor1, ip);				//SWAP
		
		ep = convert(EP,Arrays.copyOfRange(ip, 4, 9));		
		xor = XOR(ep,K2);
		s0s1 = S0S1(xor,S0,S1);
		p4 = convert(P4, s0s1);
		xor1 = XOR(p4, Arrays.copyOf(ip, 4));
		
		for(int i=0; i<4; i++) {
			ip[i]=xor1[i];
		}
		int[] C =convert(IPinverse, ip);
		System.out.print("\n--ENCRYPTION--\nCipher Text: ");
		for(int i=0;i<C.length;i++){System.out.print(C[i]);}
		
		//decryption
		int[] ip_dec = convert(IP,C);
		int[] ep_dec = convert(EP,Arrays.copyOfRange(ip_dec, 4, 9));
		int[] xor_dec = XOR(ep_dec,K2);
		int[] s0s1_dec= S0S1(xor_dec,S0,S1);		
		int[] p4_dec = convert(P4, s0s1_dec);
		
		int[] xor1_dec = XOR(p4, Arrays.copyOf(ip_dec, 4));
		
		Swap(xor1_dec, ip_dec);				//SWAP
		
		ep_dec = convert(EP,Arrays.copyOfRange(ip_dec, 4, 9));
		
		xor_dec = XOR(ep_dec,K1);
		
		s0s1_dec = S0S1(xor_dec,S0,S1);
		
		p4_dec = convert(P4, s0s1_dec);
		
		xor1_dec = XOR(p4_dec, Arrays.copyOf(ip_dec, 4));
		
		for(int i=0; i<4; i++) {
			ip_dec[i]=xor1_dec[i];
		}
		int[] P =convert(IPinverse, ip_dec);
		System.out.print("\n\n--DECRYPTION--\nPlain Text: ");
		for(int i=0;i<P.length;i++){System.out.print(P[i]);}
	}
	
	static void Swap(int[] xor, int[] ip) {
		for(int i=0; i<4; i++) {
			ip[i]=ip[i+4];
			ip[i+4]=xor[i];
		}
	}

	static int[] S0S1(int[] xor, int[][] s0, int[][] s1) {
		int[] ans = new int[4];
		String sr0 = xor[0]+""+xor[3],
			   sc0 = xor[1]+""+xor[2],
			   sr1 = xor[4]+""+xor[7],
			   sc1 = xor[5]+""+xor[6];
		int x = s0[Integer.parseInt(sr0,2)][Integer.parseInt(sc0,2)],
		    y = s1[Integer.parseInt(sr1,2)][Integer.parseInt(sc1,2)];
		if(x==0) {
			ans[0]=0; ans[1]=0;
		}
		else if (x==1) {
			ans[0]=0; ans[1]=1;
		}
		else if (x==2) {
			ans[0]=1; ans[1]=0;
		}
		else{
			ans[0]=1; ans[1]=1;
		}
		
		if(y==0) {
			ans[2]=0; ans[3]=0;
		}
		else if (y==1) {
			ans[2]=0; ans[3]=1;
		}
		else if (y==2) {
			ans[2]=1; ans[3]=0;
		}
		else if (y==3) {
			ans[2]=1; ans[3]=1;
		}
		return ans;
	}

	static int[] XOR(int[] ep, int[] k) {
		int[] ans = new int[ep.length];
		for(int i=0; i<ans.length; i++) {
			ans[i]= (ep[i]==k[i]) ? 0:1;
		}
		return ans;
	}


	static void LS6_10(int[] p10) {
		int temp=p10[5];
		for(int i=5; i<9; i++) {
			p10[i]=p10[i+1];
		}
		p10[9]=temp;
	}

	static void LS1_5(int[] p10) {
		int temp=p10[0];
		for(int i=0; i<4; i++) {
			p10[i]=p10[i+1];
		}
		p10[4]=temp;
	}
	
	static int[] convert(int[] p, int[] k)
	{
		int[] ans = new int[p.length];
		int i=0;
		for (int x : p) {
			ans[i++] = k[x-1];
		}
		return ans;
	}
}
