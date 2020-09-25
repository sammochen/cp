
public class Main {
    public static void main(String args[]) {
        int a = 0, b = 25;
        System.out.println(a);
        System.out.println(b);

        int c = ++b; // c is 0, a is 1
        // c takes on a's value BEFORE adding 1

        System.out.println(a);
        a++;
        System.out.println(a);

    }
}



