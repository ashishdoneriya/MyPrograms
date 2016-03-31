    import java.io.IOException;
    import java.io.OutputStreamWriter;
    import java.io.BufferedWriter;
    import java.util.InputMismatchException;
    import java.io.OutputStream;
    import java.io.PrintWriter;
    import java.io.Writer;
    import java.math.BigInteger;
    import java.io.InputStream;
     
    /**
    * Built using CHelper plug-in
    * Actual solution is at the top
    * @author Egor Kulikov (egor@egork.net)
    */
    public class Main {
    public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    TeamFormation solver = new TeamFormation();
    int testCount = Integer.parseInt(in.next());
    for (int i = 1; i <= testCount; i++)
    solver.solve(i, in, out);
    out.close();
    }
    }
     
    class TeamFormation {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
    int count = in.readInt();
    int maxDiff = in.readInt();
    int queryCount = in.readInt();
    int a = in.readInt();
    int b = in.readInt();
    int d = in.readInt();
    int[] skill = new int[count];
    for (int i = 0; i < count && i < 10000; i++)
    skill[i] = in.readInt();
    for (int i = 10000; i < count; i++)
    skill[i] = (a * skill[i - 1] + b * skill[i - 2] + d) & ((1 << 30) - 1);
    int[] total = new int[count + 1];
    int j = 1;
    int[] max = new int[count];
    int maxStart = 0;
    int maxEnd = 1;
    int[] min = new int[count];
    int minStart = 0;
    int minEnd = 1;
    for (int i = 0; i < count; i++) {
    if (i != 0) {
    if (max[maxStart] == i - 1)
    maxStart++;
    if (min[minStart] == i - 1)
    minStart++;
    }
    while (j < count) {
    if (minStart != minEnd && skill[j] - skill[min[minStart]] > maxDiff)
    break;
    if (maxStart != maxEnd && skill[max[maxStart]] - skill[j] > maxDiff)
    break;
    while (minEnd > minStart && skill[j] <= skill[min[minEnd - 1]])
    minEnd--;
    min[minEnd++] = j;
    while (maxEnd > maxStart && skill[j] >= skill[max[maxEnd - 1]])
    maxEnd--;
    max[maxEnd++] = j++;
    }
    total[j - i]++;
    }
    for (int i = count - 1; i >= 0; i--)
    total[i] += total[i + 1];
    for (int i = 0; i < queryCount; i++) {
    int canProcess = in.readInt();
    int left = 1;
    int right = count;
    while (left < right) {
    int middle = (left + right) >> 1;
    if (total[middle] > canProcess)
    left = middle + 1;
    else
    right = middle;
    }
    out.printLine(left, total[left]);
    }
    }
    }
     
    class InputReader {
     
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
     
    public InputReader(InputStream stream) {
    this.stream = stream;
    }
     
    public int read() {
    if (numChars == -1)
    throw new InputMismatchException();
    if (curChar >= numChars) {
    curChar = 0;
    try {
    numChars = stream.read(buf);
    } catch (IOException e) {
    throw new InputMismatchException();
    }
    if (numChars <= 0)
    return -1;
    }
    return buf[curChar++];
    }
     
    public int readInt() {
    int c = read();
    while (isSpaceChar(c))
    c = read();
    int sgn = 1;
    if (c == '-') {
    sgn = -1;
    c = read();
    }
    int res = 0;
    do {
    if (c < '0' || c > '9')
    throw new InputMismatchException();
    res *= 10;
    res += c - '0';
    c = read();
    } while (!isSpaceChar(c));
    return res * sgn;
    }
     
    public String readString() {
    int c = read();
    while (isSpaceChar(c))
    c = read();
    StringBuffer res = new StringBuffer();
    do {
    res.appendCodePoint(c);
    c = read();
    } while (!isSpaceChar(c));
    return res.toString();
    }
     
    public boolean isSpaceChar(int c) {
    if (filter != null)
    return filter.isSpaceChar(c);
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
     
    public String next() {
    return readString();
    }
     
    public interface SpaceCharFilter {
    public boolean isSpaceChar(int ch);
    }
    }
     
    class OutputWriter {
    private final PrintWriter writer;
     
    public OutputWriter(OutputStream outputStream) {
    writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }
     
    public OutputWriter(Writer writer) {
    this.writer = new PrintWriter(writer);
    }
     
    public void print(Object...objects) {
    for (int i = 0; i < objects.length; i++) {
    if (i != 0)
    writer.print(' ');
    writer.print(objects[i]);
    }
    }
     
    public void printLine(Object...objects) {
    print(objects);
    writer.println();
    }
     
    public void close() {
    writer.close();
    }
     
    }
     
