import java.util.Scanner;
import java.io.RandomAccessFile;
import java.io.IOException;
import java.io.FileNotFoundException;


/**
 * Created by probalchandradhar on 10/12/16.
 */
public class testUTF {

   public static void main(String[] args)
   {
      String s = "Hello World java";
      System.out.println("String size: " + s.length());
    
      try{
      
         RandomAccessFile ioStream = new RandomAccessFile("bytedata", "rw");
      
         ioStream.writeUTF(String.format("%50s",s));
      
      
         System.out.println("File Size: " + (int)ioStream.length() );
         ioStream.seek(0);
      
         String output = ioStream.readUTF();
         System.out.println(output);
         System.out.println(output.trim());
      
      }
      catch(FileNotFoundException e)
      {
         System.out.println("Problem opening file.");
      }
      catch(IOException e)
      {
         e.printStackTrace();
         System.out.println("Problems with file I/O.");
      }
   
   
   
   
   }



}
