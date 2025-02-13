import java.util.*;

public class WhileLoopPrintTable {
    public static void main(String args[]) {
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        int val=n*10;
        do
        {
         System.out.print(val+" ");
         val-=n;
        }while(val!=0);
        scanner.close();
    }
}