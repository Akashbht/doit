public class methods {
    
    static int  add(int a, int b) {  // copies the values of the varianbles
        return a + b;
    }

    static int add(int a, int b, int c){
        return a + b + c;
    }


    static int sum1(int a , int b){
        return a + b;
    }

    static int sum(int ...arr){   //jitne bhi input honge wo array main daal do
        int sum = 0 ;
        for(int i : arr){
            sum += i;
        }
        return sum;

    }

    // static int sum(int x, int ...arr){   //ek input to dena hi hai 
    //     int sum = x ;
    //     for(int i : arr){
    //         sum += i;
    //     }
    //     return sum;

    // }

    public static void main(String[] Args){

        int a= 8;

        int b = 3;
        // System.out.println(add(a,b));

//  METHOD OVERLOADING 

        // method oveloading cannot be done by changing return types

        // it is done by changing number or type of parameters

        // System.out.println(add(1,2,3));
        // System.out.println(add(5,7));


        // varaible arguments

        
        // made a variable parameter method with name sum 
        // System.out.println(sum(2,3,45,3,34,5,456,45,6,45,6));

        System.out.println(sum(1,24));





    }
}
