// import java.util.Scanner;
// package com.company;  // optional

/* 
public class App {   // class ke baad file ka naam aayega 

    public static void main(String[] args){
        System.out.println("first java");
    }
}

*/

// FUNCTIONS
// add,subtract, multiply

// CLASSES

// VARIABLE :  a container that stores a value, that value can be changed during the execution of the program 


// DATA TYPES
/*

// PRIMITVE DATA TYPES: 
int: integer - whole numbers (positive and negative) , 4 bytes 
float/double : floating point number - decimal numbers, takes 4 bytes 
char : character - 2 bytes, because it supports unicode
boolean : true or false
byte : 8 bits (-127 to +128)
short : 16 bits (-32768 to +32767)
double :  64 bit double precision float 
long : takes 8 bytes and only for integer

//  double for float and long for int

// NON PRIMITVE DATA TYPES

- String : sequence of characters
- Classes : user defined data type

 
*/

// wap for adding 3 variables
/*
public class App{
    public static void main(String[] Args){
        System.out.print("the sum of the numbers is :");
        int num1  = 3;
        int num2 = 4;
        int num3 = 5;
        int sum = num1 + num2 + num3;
        System.out.println(sum);
    }
}

 */



//  LITERALS 
//  literal is a value that remains unchanged throughout the program execution

//  there are two types of literals in java
//  1. Integer Literals
//  2. Floating Point Literals


// system.out.... sout and enter //short cut







// taking input form the user 

// adding 2 user input values

/* 
public class App{
    public static void main(String[] Args){


        System.out.println("taking input from the user ");

        Scanner sc = new Scanner(System.in);

        // boolean b = sc.hasNextInt();
        // System.out.println(b);
         System.out.println("enter number 1 ");
        
        float f = sc.nextFloat();
        // int a = sc.nextInt();
        
        System.out.println("enter number 2 ");
        
        // int b = sc.nextInt();
        float g = sc.nextFloat();
        

        // int sum = a + b ;
        float sum = f + g;



        
        System.out.print("sum: ");
        System.out.println(sum);

        
        String str = sc.nextLine();  // FOR INSERTING A LINE 
        System.out.println(str);
        

    }
}
*/



// OPERATORS
// arithmatic operators do not work with boolean values

//   % - modulo operator , gives the remainder 

//  *= also work in java 

//  == comaprison operator

// && , and operator  


//  ++ , --   increament and decrement operators are availaible in java 






// PRECEDENCE AND ASSOCIATIVITY

// if the precedence is same then  associativity decides how it will be executed, i.e. from left to right in java




// SRTINGS
/*
String s1="Hello";
String s2="World";
System.out.print("Concatenation : ");

System.out.println(s1+ " "+ s2); // concatenation of two strings

String name = new String("hello world");  // alterante method 


*/


// strings are immutable in java

// System.out.print();                //
// System.out.println() ;                  //  

// System.out.printf();          //simple c wala printf, format specifier  is used here




// System.out.println(name.charAt(0)); // returns first character of







// STRING METHODS

/* 
public class App{
    public static void main(String[] Args){
        String name = "harry";

        // length()
        int length = name.length();
        System.out.println("\nLength of the string: \t" + length);
        

        // charAt()
        char ch = name.charAt(4);
        System.out.println("\nCharacter at index 4:\t" +ch );


        // toLowerCase()
        String lowercaseName = name.toLowerCase();
        System.out.println("\nConverting all letters to Lower Case :\t"+lowercaseName);
        

        // toUpperCase()
        String uppercaseName = name.toUpperCase();
        System.out.println("Converting all letters to Upper Case :\t"+uppercaseName);


        // trim()    , remove leading and trailing spaces
        String spaceName = "   harry   ";
        String trimmedSpaceName= spaceName.trim();
        System.out.println("\nRemoving leading and trailing spaces from a string :\t"+trimmedSpaceName);
        

        //  name.substring(from_index, to_index)
        //to_index is optional
        //If not provided it will consider till end of the string

        String  str1 = "Hello World!";
        System.out.println("using substring : "+str1.substring(2,5));

        // name.replace(first , sec)
        // replaces first char with sec


        String  str2 ="I love coding in Java.";
        System.out.println("replacing characters : "+str2.replace("o", "ting"));



        // contains(string/char)
        // startsWith(string/char)
        // endsWith(string/char)
        // above func return bool values

        // indexOf(char), returns index of first appearance of char

        // indexOf(char,4)  , starts from index 4 , before ones are ignored

        // lastindexof(char)     , returns the last index of the char in the string  

        // name.equals(string)   , checks name and string and return bool values 

        // name.equalIgnoreCase(string), compares without taking case in consideration 

        // escape sequence characters contains 2 characters but represent only one,
        //  \t represents horizontal tab
        //   \n represents newline or line breaker

        String specialCharacters="This is a text containing some special characters like \\t for Horizontal Tab and \\n for New Line.\n" +"        //    \" represents double quote        //    \b represents backspace";
        System.out.println(specialCharacters);

        


    }
}



*/



// FOR EACH LOOP 

// in array 




// star pattern using recursion 
/*
public class App {

    static void printStarPattern(int n){
        if (n > 0 ) {
            printStarPattern(n-1);
            for(int i = 0; i< n; i++){
                System.out.print("*");
            }
            System.out.println();
        }

    }    
    public static void main(String[] Args){
        Scanner sc= new Scanner(System.in);
        System.out.println("enter a no. :");      
        int num =sc.nextInt();
        printStarPattern(num);
    }
}
 */


 



































