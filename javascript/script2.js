// execution context matlab jab bhi hum fucntion chalaenge func apna ek khudka ek imaginary container bana lega jismein uski teen cheeke hongi:
// 1. variables
// 2. functions inside that parent func
// 3. lexical environment of that function

// ye jp container hai imaginery ise hi hum execution context kehte hain


// function abcd(){
//     var a = 12;
//     function def(){
//         var b = 12;
//     }
// }

// EXECUTION CONTEXT
// execution context is a container where the function's code is executed whenever a fucntion is called, it contains  3 things , variables , fnuctions and lexical environment

// LEXICAL ENVIRONMENT
// lexical environment hota hai ek particular chart jisme ye likha hota hai ki aapka particular function kin cheejo ko access kar sakta hai , aur kinko nahi, it holds scope and scope chain 



// copying reference values 

// var a = [12,2,3,23,53,3];
// var b = [...a];

// ... = spread operator , copy karta hai values ko 

// b.pop();  // ab a se value pop nahi hogi


// var obj = {name:'harsh'};
// var copy = {...obj}; 




// TURTHY AND FALSEY

// js main kuch bhi likho wo mainly do prakaar main se kisi ko belong karti hain , truthy ya falsy 

// falsey values = false , 0 , undefined, null, NaN, document.all

// truthy values 
// -1 bhi truthy value hai 
// "" (empty string) also truthy value hai
// {} empty object is also truthy value
// [] empty array is also truthy value
// <tag> </tag> html tag ko truthy value hai

// if({}){
//     console.log("hey");
// }
// else{
//     console.log('hello');
// }





// FOREACH FORIN DO-WHILE


// foreach

// ye sirf array pe chalega , matlab sirf array ke saath use ho sakta hai 

// var a = [1,2,3,456,45,459,4,56];
// a.forEach(function(val){
//     // this inside forEach refers to window object
//     console.log(val+2);
// })

// foreach kabhi bhi by default array main changes NAHI karta wo appko changes karke deta ahi array ki temporary copy main jiski wajah se array humesha same rehta hai




// FORIN 

// objects par loop run karne ke liye hota hai forin loop 

// var obj = {
//     name: 'aka',
//     age : 12,
//     city : 'delhi'
// }


// for(var key in obj){
//     console.log(key, obj[key]);
//     // console.log(obj[name]);   // aise name print nahi hoga
// }




// CALLBACK FUNCTIONS

// jab bhi koi aisa code jo baad main chalta hai app likhoge, kyuki wo code baad main chalta hai js ko pata nhi hota ke wo complete hua ya nahi, aise code ke completion par js ko bataya jaata hai ke wo complete ho gaya hai aur app use chala sakte ho , ye batane ka kaam callback ka hai 

// setTimeout(function(){
//     console.log("2 sec baad ");

// },2000);

// set timeout ke ander wala function callback function hota hai 

// aisa code jo baad main chalta hai use hum ek function dedete hai, jab complete ho jaan to ye function chala dena, aur wo function jo hum dete hain wo ek normal func hi hota hai aur use kehte hain call back function 





// FIRST CLASS FUNCTION 

// js main function ko use kar sakte hain as a value

// var a = function(){};

// function abcd(a){
//     a();
// }

// abcd(function(){console.log('console');})



// why negative indeces in js

// var arr = [1,2,3,4];
// arr = {
//     0 : 1,
//     1 : 2,
//     2 : 3,
//     3 : 4 
// }
// arr[-1] = 2;



// deleting object prop


// var a = {
//     name:'harsh',
//     age:12
// }

// delete a.age;
// delete a.name;




















