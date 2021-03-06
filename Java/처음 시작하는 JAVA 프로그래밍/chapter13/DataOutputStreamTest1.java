package chapter13;

import java.io.*;
import java.util.Scanner;

public class DataOutputStreamTest1 {
	public static void main(String[] args) throws IOException{
		Scanner stdin = new Scanner(System.in);
		System.out.print("출력할 파일명을 입력하세요 : ");
		String s = stdin.nextLine(); stdin.close();
		FileOutputStream fos = new FileOutputStream(s);
		DataOutputStream dos = new DataOutputStream(fos);
		dos.writeBoolean(false);
		dos.writeByte(Byte.MAX_VALUE);
		fos.close();
		System.out.println(s+" 파일명으로 바이트 파일을 생성하였습니다.");
	}
}
