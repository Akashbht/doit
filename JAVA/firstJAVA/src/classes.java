
class employee {
    int id;
    String name;
    public void print(){
        System.out.println(name);
        System.out.println(id);
    }

}


public class classes{


    public static void main(String[] args) {

        System.out.println("this is custom class");
        employee har = new employee();
        har.name = "lol";
        har.id = 23;


        // System.out.println(har.name);
        har.print();

    }
}

