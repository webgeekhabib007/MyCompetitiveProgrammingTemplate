
import java.lang.*;
import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException{
        FileReader fileReader = new FileReader("./input.txt");
        FileWriter fileWriter = new FileWriter("./output.txt");
        Scanner  scan = new Scanner(fileReader);
        int n = scan.nextInt();
        fileWriter.write(String.valueOf(n));
        fileWriter.close();
        scan.close();
        return ;
    }
}

