
class square{
    int side;
    public void setside(int a ){
        side = a;
    }
    public int getside(){
        return side; }
    public int getarea(){
        return side * side;

    }
    public int getperimeter(){
        return 4*side;
    }
    
}

public class square_class {
    public static void main(String[] Args){
        square sq = new square();
        sq.side = 10;
        System.out.println("Side of the square is " +sq.getside());
        System.out.println(sq.getarea());
        System.out.println(sq.getperimeter());

    }
        // sq.getarea();

}
