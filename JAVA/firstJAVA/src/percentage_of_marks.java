import java.util.Scanner;

public class percentage_of_marks {
    public static void main(String[] Args){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the marks in SUB 1 : ");
        int n1 = sc.nextInt();
        System.out.println("Enter the marks in SUB 2 : ");
        int n2 = sc.nextInt();
        System.out.println("enter marks in SUB3");
        int n3 = sc.nextInt();
        float perc = (n1 + n2 + n3) / 3 ;
        System.out.println("the precentage is :");
        System.out.println(perc+"%");
    }
}
