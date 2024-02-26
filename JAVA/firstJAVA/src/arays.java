import java.util.Scanner;

public class arays {

    public static void print_ar(int[] arr){
        for (int i = 0 ; i < arr.length ; i++){
            System.out.print(arr[i]+" ");
        }
    }
    public static void reverse_arr(int[] arr){
        int start = 0;
        int end = arr.length -1;
        int mid = arr.length/2;
        while (mid>0){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end]=temp;
            end--;
            start++;
            mid--;
        }

    }

    public static boolean is_sorted(int[]arr){
        boolean flag = true;
        for (int i=0; i<arr.length-1; i++ ){
            if (arr[i] > arr [i+1]){
                flag = false;
            }
        }
        return flag;
    }
    public static void print_arr(int[][] arr){
        for (int i = 0 ; i < arr.length ; i++){{
            for(int j =0; j < arr[i].length;j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println("");
        }
            
        }
    }
    public static void  main(String[] args) {

        // int [] marks = new int[5];
        // int [] marks = {1,2,43,45,345};
        // float [] marks = {23.4,234.23,2.23,23.134};
        // String [] students = {"harry","shubham","hero"};
        
        
        // taking user input values 


        // System.out.println("Enter the marks of five students");
        // for  (int i=0;i<marks.length;i++) {
        //     Scanner sc = new Scanner(System.in);
        //     marks[i] = sc.nextInt();

        // }

        
        
        // printing array 

//         for(int i = 0; i<marks.length;i++){
//             System.out.println(marks[i]);
//         }

    


    // FOR EACH LOOP 

    // for ( int element: marks){
    //     System.out.println(element);
    // }

    


    // MULTI DIM ARRAY 
 /*
 
    int [][] flats;
    flats = new int[2][3];
    System.out.println("\n\nElements in Multi Dim Array \n");
    for (int i=0 ; i <flats.length ; i++ ){
        for (int j=0 ; j <flats[i].length ; j++){
            Scanner sc = new Scanner(System.in);
            int a = sc.nextInt();
            flats [i][j]=a;
        }

    }
    for(int [] arr : flats){
        for( int element: arr){
            System.out.print(element+" ");
        }
        System.out.println(" ");
    }
    
    */ 

    /*
    int [][][] m2 = {
        {
            {1,2}, {3,4}
        },{
            {5,6},{7,8}
        }
    };

    for( int[][] arr : m2){
        for( int[] ar: arr){
            for( int a : ar){
                System.out.print(a+" ");
            }
            
        }
        System.out.println(" ");
    }

     */

     /* 
    int [][] m1 = {{1,2,3,},{4,5,6}};
    int [][] m2 = { {4,7,3},{2,27,8}};
    int [][] m3 = m1;

    print_arr(m1);
    System.out.println("");
    print_arr(m2);

    for(int i = 0; i<m1.length;i++){
        for(int j = 0;j<m1[i].length;j++){
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    System.out.println("");
    print_arr(m3);
    



    */


    // reverse array
    // int [] m1 = { 1,2,3,4,5,6};
    // reverse_arr(m1); 
    // print_ar(m1);


    // is sorted array 
    
/*
    int [] m1 = { 3,6,23,37,264,374};
    print_ar(m1);
    
    System.out.println("\n"+is_sorted(m1));

 */







}

}



