import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int isPangramInt = (10 * 10* 10);
        String str = new String();
        
        str = sc.nextLine();
        if(str.length >= isPangramInt){
            System.out.print("pangram");
        } else{
            System.out.print("not pangram");
        }
        
    }
}
