//basic 3 sorting techniques [bubble, selection, insertion]
public class Main{
    public static void print(int arr[]){
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public static void main(String args[]){
        int arr[] = {7,8,3,1,2};

        //bubble sort //largest element ko last mai rakhte hai TC=O(n^2)
        for(int i = 0; i < arr.length - 1; i++){
            for(int j = 0; j < arr.length - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    //swap
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

        //selection sort //smallest element ko pick krte hai 1 pure iteration mai or use fir first position pe rakhte hai
        //starting se sort hote jata hai TC= Onsquare
        for(int i = 0; i < arr.length-1; i++){
            int s = i;
            for(int j = i + 1; j < arr.length; j++){
                if(arr[s] > arr[j]){
                    s = j;
                }
            }
            //swapping after one iteration
            int temp = arr[s];
            arr[s] = arr[i];
            arr[i] = temp;
        }

        //insertion sort //array ko divide krte hai sorted or unsorted mai
        //TC Onsquare
        for(int i = 1; i < arr.length; i++){
            int curr = arr[i];
            int j = i - 1;
            while(j>=0 && curr < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            //placement
            arr[j+1] = curr;
        }
        print(arr);
    }
}
