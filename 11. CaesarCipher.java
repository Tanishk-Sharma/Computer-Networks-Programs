/*
Encryption with Caesar code is based on an alphabet shift (move of letters further in the alphabet)
ie. a same letter is replaced with only one other (always the same for given cipher message). 
The most commonly used shift/offset is by 3 letters.
Source: https://www.dcode.fr/caesar-cipher
*/


import java.util.*;

public class CaesarCipher {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int shift = in.nextInt();
        StringBuffer str = new StringBuffer();
        for(char c : s.toCharArray()){
            if((c>='a' && c<='z') || (c>='A' && c<='Z')){
                int newchar = (int)c;
                int t = shift>26 ? shift%26 : shift;

                if(Character.isLowerCase(c))
                    if(newchar+t>122)
                        newchar = 96 + ((newchar+t)-122);
                    else
                        newchar = newchar+t;
                
                else
                    if(newchar+t>90)
                        newchar = 64 + ((newchar+t)-90);
                    else
                        newchar = newchar+t;
                
                str.append((char)newchar);
            }
            else
                str.append(c);
        }
        System.out.println(str);
    }
}
