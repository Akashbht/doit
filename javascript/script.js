// console.log("print this ");


// variable and constant variables

var a = 12;
// const b = 13;

// b = "he";   // gives error cause changing const variable


let b = 12 ;

// variable function scoped hota hai
// var apne parent func main kahi bhi use ho sakta hai

function abcd(){
    for(var i = 0; i<11;i++){
        console.log(i);
    }
    console.log(i);  // 11 will be printed
}
abcd();


// function abcdf(){
//     for(let i = 0; i<11;i++){
//         console.log(i);
//     }
//     console.log(i);  // 11 will not be printed since let varibale is used
// }
// abcdf();

//1. var function scoped hota hai 
//1. let braces scoped hota hai
// 2. var adds itself to the window object
// 2. let doesn't add itself to the window object

// js main kahi saare features hain, par kuch features jo hum use karte hain wo nahi hain , par bhi use kar paate hain , kyuki wo features js lanaguge leti hai window se , aur window hai ek box of features given by browser to use with js 



// alert prompt console are not part of js
// they are browser functions
// console pe type window






// HOISTING 
// variables and fuctions are hoisted means that their
// declaration is moved to the top of code

// varibale ko banane se pehle use kar sakte hain 
// console.log(not_defined_variable_name);    // undefined

// var not_defined_variable_name = 12;


// undefined and not-defined 
// var a ;
// the above declaration is moved to the top of the code 

// a = 12;








// TYPES IN  JS
// primitives and reference

// primitives = number, string, null , undefined, bool
// reference = [] () { }


// aisi koi bhi value jisko copy karne par real copy
// nahi hota balki main value ka reference pass hota hai , use 
// refernce kehte hain, aur uska real value pass ho jaaye
// use primitive value kehte hain  


// var a = [12,13];
// var b = a;
// b.pop();

//b main changes a main affect karenge
//console.log(a) ;     // [12]



// reference type wale direct copy nahi ho sakte 
// console.log(a)     // [12]



// CONDITIONALS
// IF , ELSE  ,ELSEIF
// jab bhi baat agar magar main aayegi 
// ya aisa waisa ho jaaye to 

// a  = true;   
// if(a){
//     console.log("hello");
// }



// a = false;
// if("apple"){
//     a = "apple";
// }
// else if(a){
//     a = "mango";
// }
// else{
//     a = "else";
// }





// LOOPS
// for , while

// for(start,end,change)


// for(var i = 0;i<11;i++){
//     console.log(i);
// }



// for(var a = 25; a<51; a++){
//     console.log(a);
// }


// var a = 12;
// while(a<20){
//     a++;
//     console.log(a);
// }



// FUNCTIONS
// function name (parameters) {

//1. jab code at moment run nahi karna but future main run karna hai
//2. jab code ko reuse karna hai 
//3. jab code chalana chaahte hain with different data/variables/parameters
 
// kuch piece of code ko naam de diya and baad main usse use kar sakte hain with that name as many times



// function abcd(a,b,c){
//     console.log(a,b,c);
// }

// abcd("a","b","c"); // a b !
// abcd('c','d','e');  // c d e
// abcd('a','b');   // a b undefined


// arguments = real value jo hum dete hain func chalte waqt
// parameter = variables jinme value store hoti hai arguments wali




// ARRAYS = ek variable main jab humain ek se jyada value store karni ho to hum array use karte hain 


// var a = 12,13;  //error
// var a = [12,13];    //correct


// array = group of values

// var  a = [11,22,33,44,55,66,77];

// console.log(a[4]);


// push pop shift unshift  splice


// var arr = [1,2,3,4,5];
// arr.push(8); // last index pe value add karne ke liye
// arr.pop();   // last index se value nikaalne ke liye
// arr.unshift(7);    //first index pe value insert karne ke liye
// arr.shift();      // first index se value remove karne ke liye
// arr.splice(2,2);    // 2 index se next  2 values remove 


// OBJECTS 
// ek se jyada bande ki baat to hua array, ek bande ke baare main saaari baat ki to hua object

// object hai ke bande ki details ko hold karna , in a key value pair

// 1) blank object
//var a = {}





// jitne bhi variables ya data hum banate hain unke store kahi to karna padhta hai uske liye hai HEAP MEMORY




















// console.log(a);




















