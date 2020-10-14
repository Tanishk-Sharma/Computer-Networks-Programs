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
