f(size == -1){
        return false;
    }
    if(arr[size-1]==value){
        return true;
    }
    else{
        return linearsearch(arr,size-1,value);
    }

    