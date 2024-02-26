let start = new  Date().getTime();

        function getrandomcolor(){
            const letters = '0123456789ABCDEF';
            let color = '#';
            for (let i=0;i<6;i++){
                color += letters[Math.floor(Math.random() * 16)];
            }
            return color;
        }
        
        function makeshappeappear(){
            let top = Math.random()*400; 
            let left = Math.random()*400;
            let width = Math.random()*400;

            if(Math.random()>0.5){
                document.getElementById("shape").style.borderRadius = "50%";
            }else{
                document.getElementById("shape").style.removeProperty('border-radius');
            }



            document.getElementById("shape").style.top = top+"px";
            document.getElementById("shape").style.backgroundColor = getrandomcolor();
            document.getElementById("shape").style.left = left+"px";
            document.getElementById("shape").style.width = width+"px";
            document.getElementById("shape").style.height = width+"px";
            document.getElementById("shape").style.display = "block";
            start = new Date().getTime();


        }   

        function appearafterdelay(){
            setTimeout(makeshappeappear, Math.random() * 2000);

        }
        appearafterdelay();
        
         
        document.getElementById("shape").onclick = function(){
            document.getElementById("shape").style.display = " none";
            let end = new Date().getTime();
            let timetaken = (end - start) / 1000;
            // alert(timetaken);
            document.getElementById("timetaken").innerHTML = timetaken + "s";

            // setTimeout();
            appearafterdelay();
        }