// package com.company;

class myemployee{
    private int id ;
    private String name;
    public void set_name(String n){
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


public class access_modifiers {
    public static void main(String[] args) {
        myemployee harry = new myemployee();
        // harry.id =102;       //private members
        // harry.name = "lol";
        harry.set_id(19);
        harry.set_name("harry puttar");
        System.out.println(harry.get_id());
        System.out.println(harry.get_name());


    }
}
