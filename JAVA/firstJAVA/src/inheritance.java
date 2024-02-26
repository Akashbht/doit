

class Base1{
    int x;
    public Base1(){
        System.out.println("I am a base1 class");
    }

    public Base1(int x){
        this.x = x;
        System.out.println("inside parameterised base class constructor");
    }
    
    public int get(){
        return x;
    }


    public void set(int x){
        this.x= x;
    }


    public void print(){
        System.out.println("i am constructor ");
    }
}



// INHERITED BASE CLASS INSIDE THE CHILD CLASS
class Child1 extends Base1{
    public Child1(){
        System.out.println("I am a child1 class");
    }

    public Child1(int y){
        super(y);   // ye super keyword base class ke constructor ko call kargega with parameters;

        System.out.println("Inside the parameterized child class constructor");
    }
    int x;
    int y;

    public int get(){
        return x;
    }
    public void set(int x){
        this.x = x + 100 ;
    }


}



class one{
    public void greet(){
        System.out.println("good morning");
    }

    public void name(){
        System.out.println("My Name is Class one");
    }
}
class two extends one{
    public void name(){
        System.out.println("I am class two ");
    }
    public void hello(){
        System.out.println("hellop from two class");
    }

}

public class inheritance {


    /* 
    public static void main(String[] Args){

        Child c = new Child();
        c.set(128);
        c.print();
        System.out.println(c.get());


        Base baseptr = new Child();


        baseptr.set(324);
        baseptr.print();
        System.out.println(baseptr.get());
    }
    */
    
    



    // CONSTRUCTOR TIME

    public static void main(String[] args) {
        // Child1 c = new Child1(5);  
        // Base1 b = new Base1();  
    
    

        // DYNAMIC METHOD DISPATCH  
        
        
        one obj = new two();

        // two t = new one();
        
        // not allowed  in java, it will give compile time error
        // because we are trying to assign an object of class 'one' ( parent)  into the reference variable of type 'two'(child ).


        obj.name();
        //  ye name child ka chalega , isi ko dynamic method dipatch kehte hain aur ye c++ main virtual function se karte the



        // obj.hello();

        // ye parent ka obj child wale methods ko call nahi kargea kyuki iska previous reference parent main nahi hai 
        // isko hi dynamic method dispatch kehte hain 
        //aur ye runtime pe chalta hai 
        // i.e. runtime polymorphism

        

    
    
    
    
    
    
    }
    
    // constructor can be overloaded for multiple arguments 




    
}
