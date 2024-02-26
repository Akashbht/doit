import java.util.Random;
import java.util.Scanner;
import java.util.random.RandomGenerator;



class guess{
    // int n ;
    
    


    
}


public class guess_the_number {
    static boolean check_num(int n, int m ){
        if(n == m){
            return true;
        }
        else if(n>m){
            System.out.println("number entered is greater \n guess again ");
            return false;
        }
        else{
            System.out.println("number entered is smaller \n guess agaian");
            return false;
        }

    }
    public static void main(String[] args) {

    Random rnd = new Random();
    int n = rnd.nextInt(100);
    System.out.println(n);
    int score = 0;
    Scanner scnr = new Scanner(System.in);
    while(true){

        System.out.println("enter a guess :");
        score++;
        int num = scnr.nextInt();
        if(check_num(num,n)== true){
            
            System.out.println("You won ");
            System.out.println("score : "+score); 
            break;

        }
    }



    }    
}
