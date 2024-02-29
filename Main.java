import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine().trim();
            int[] answer = calculatePinballTime(n, s);
            for (int i = 0; i < n; i++) {
                System.out.print(answer[i] + " ");
            }
            System.out.println();
        }
    }

    public static int[] calculatePinballTime(int n, String s) {
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            char[] grid = s.toCharArray();
            int seconds = 0;
            int pos = i;
            while (pos >= 0 && pos < n) {
                if (grid[pos] == '>') {
                    grid[pos] = '<';
                    pos++;
                } else {
                    grid[pos] = '>';
                    pos--;
                }
                seconds++;
            }
            answer[i] = seconds;
        }
        return answer;
    }
}