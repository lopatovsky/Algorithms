import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class routing {
    
        StringTokenizer st = new StringTokenizer("");
	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	void useLine(String s) { st = new StringTokenizer(s); }
	void useNextLine() throws Exception { useLine(input.readLine()); }
	String nextToken() throws Exception {
		while (!st.hasMoreTokens()) st = new StringTokenizer(input.readLine());
		return st.nextToken();
	}
	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}
    
    public static int[] ebenen = new int[601];

    public  void fillEbenen(){
        ebenen[0] = 0;
        int x = 0;
        for (int i = 1; i <= 600; i++){
            ebenen[i] = x;
            x+= 6*i;
        }
    }
    public  int getEbene(int n){
        if ( n==0 ) return 0;
        int i = 0;
        while( n > ebenen[i]) i++;
        return i-1;
    }

    public  int getCoord( int ebene, int n){

        int div = n - ebenen[ebene];
            int e = ebene;
        if ( div <= e ) return (-div);
            e += ebene;
        if ( div <= e) return ( - ebene );
            e += 2 * ebene;
        if ( div <= e) return ( ( -3 * ebene ) + div );
            e += ebene;
        if ( div <= e) return ebene ;
        else
                    return (6 * ebene) - div;
    }

    public  int transform ( int  n, int ebene){

        n -= ebene;
        if ( n <= ebenen[ebene]){
            n = ebenen[ebene+1] - ( ebenen[ebene] - n  );
        }
        return n;
    }


    public int[] getGrid( int n ) {

        int[] coord = new int[3];
        int ebene = getEbene(n);  coord[0] =  getCoord(ebene, n);
        n = transform ( n , ebene );  coord[1] =  getCoord(ebene, n);
        n = transform ( n , ebene );  coord[2] =  getCoord(ebene, n);
        
        return coord;
    }

    public  BigInteger comb ( int a, int b){
        BigInteger out = new BigInteger ("1");
        BigInteger to = BigInteger.valueOf(a + b);
        
        for (BigInteger bi = BigInteger.valueOf(b + 1);
            bi.compareTo( to ) <= 0;
            bi = bi.add(BigInteger.ONE)) {

            out = out.multiply(bi);
        }
        for (BigInteger bi = BigInteger.valueOf(a); 
             bi.compareTo(BigInteger.ONE) > 0; 
             bi = bi.subtract(BigInteger.ONE)){
            
            out = out.divide(bi);
        }
        return out;
    }

     public static void main(String[] args) throws Exception {
		routing inst = new routing();
		while ( inst.run() ) {  }
	}


	boolean run() throws Exception {
        
        fillEbenen();
        
        int[] x1 , x2 ,res = new int[3];
        int n, n1, r1, r2, r3;
        
            String in = input.readLine();
            useLine(in);
            
            n = nextInt(); n1 = nextInt();
            

            if ( n==0 && n1==0 ) {
                return false;
            }

            x1 = getGrid(n - 1);
            x2 = getGrid(n1 - 1);
            for (int i = 0; i < 3; i++)
                res[i] = Math.abs(x1[i] - x2[i]);
       
            Arrays.sort(res);
            
            BigInteger out;
            out = comb(res[0], res[1]);
            if ( out.compareTo( BigInteger.ONE ) == 0 )
                System.out.println("There is "+ out + " route of the shortest length " + (res[0] + res[1]) + ".");
            else
                System.out.println("There are "+ out + " routes of the shortest length " + (res[0] + res[1]) + ".");
        
        return true;
    }
}

