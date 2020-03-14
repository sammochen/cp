import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Scanner; 

class Main { 
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();

		for (int t = 0; t < test; t++) {
			BigDecimal ans = BigDecimal.ZERO;
			while (true) {
				String s = sc.next();
				if (s.equals("0")) break;
				ans = ans.add(new BigDecimal(s));
			}
			
			String stringAns = ans.toPlainString();
			
			boolean hasdot = false;
			for (int i = 0; i < stringAns.length(); i++) {
				if (stringAns.charAt(i) == '.') hasdot = true;
			}
			if (!hasdot) {
				System.out.println(stringAns);
				continue;
			}

			// remove trailing zeros
			for (int i = stringAns.length() - 1; i >= 0; i--) {
				if (stringAns.charAt(i) == '.') {
					stringAns = stringAns.substring(0, i);
					break;
				} else if (stringAns.charAt(i) != '0') {
					stringAns = stringAns.substring(0, i+1);
					break;
				}
			}
			System.out.println(stringAns);

		}
		
    	sc.close();
    } 
} 