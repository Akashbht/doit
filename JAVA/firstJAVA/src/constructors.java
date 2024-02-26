
class mymemployee{
    private int id ;
    private String name;
    public void set_name(String n){
        name = n;

    }
    public mymemployee(int i, String n){
        id = i;
        name = n;
    }
    public String get_name(){
        return name;
    }
    public void set_id(int n){
        id=n;
    }
    public int get_id(){
        return id;
    }

}


public class constructors {
    public static void main(String[] args) {
        mymemployee emp  = new mymemployee(34,"nas");
        // argumented constructor invoked object initialised 


        System.out.println("Employee Name is " +emp.get_name());


        // constructor can also be overloaded 
        








    }   
}
