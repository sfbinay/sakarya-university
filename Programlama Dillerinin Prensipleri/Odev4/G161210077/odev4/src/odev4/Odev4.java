/**
*
* @author Süleyman Furkan BİNAY - suleyman.binay@ogr.sakarya.edu.tr
* @since 02.05.2019
* <p>
* Thread used in this program
* </p>
*/
package odev4;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 *
 * @author furkan
 */

class islem implements Runnable
{
    ArrayList<String> satir = new ArrayList<>();
    int deger,basamak;
    
    public islem(ArrayList parametreSatir,int parametreBasamak)
    {
        basamak = parametreBasamak;
        satir = parametreSatir;
    }
    
    @Override
    public void run()
    {   
        for(int i =0;i<satir.size();i++)
        {
            deger+=Character.getNumericValue(satir.get(i).charAt(basamak));
        }
    }
}

public class Odev4 {   
    public static void main(String[] args) {
        
        ArrayList<String> satir = new ArrayList<>();//array list den satir adında nesne üretiliyor
        BufferedReader br = null;//okumak için BufferReader br nesnesi üretiliyor        
        try 
        {
            br = new BufferedReader(new FileReader("Sayilar.txt"));
            String line;
            
            while ((line = br.readLine()) != null) 
            {                
                satir.add(line);//dosyadaki satirlar arraylist e ekleniyor.
            }
            
            br.close();//dosya kapatıldı.
        } 
        
        catch (IOException e) 
        {
            System.out.println("dosya okunamadi");
        }
           
           
        int binler=0,yuzler=0,onlar=0,birler=0;
        
        long basla = System.nanoTime();//seri hesaplama basliyor. 
        
        for(int i=0;i<satir.size();i++)
        {
            for (int j = 0; j < 4; j++) 
            {
             if(j==0)
             {
                 binler += Character.getNumericValue(satir.get(i).charAt(j));
             }
             else if(j==1)
             {
                yuzler += Character.getNumericValue(satir.get(i).charAt(j));
             }
             else if(j==2)
             {
                 onlar += Character.getNumericValue(satir.get(i).charAt(j));
             }
             else if(j==3)
             {
                 birler += Character.getNumericValue(satir.get(i).charAt(j));
             }
            }
        }
        long dur = System.nanoTime();//seri hesaplama bitti.
        double fark = (dur-basla)/1000000.0;
        
        
        System.out.println("Sonuc="+binler+yuzler+onlar+birler);
        System.out.println();
        System.out.println("Seri Hesaplama Süresi:"+fark+" milisaniye");
        System.out.println();
       
    
    ExecutorService havuz = Executors.newFixedThreadPool(4);//Havuzda 4 adet Thread olacagi tanimlaniyor.
    
    basla = System.nanoTime();//paralel hesaplama basladi.
    
    for (int i = 0; i < 4; i++) 
    {
        havuz.execute(new islem(satir,i));//Threadler icra ettiriliyor.
    }
    
    havuz.shutdown();//havuz kapatiliyor.
    dur=System.nanoTime();//paralel hesaplama bitti.
    fark =(dur-basla)/1000000.0;
    System.out.println("Paralel hesaplama suresi: "+fark+"milisaniye");
   
    }
    }
    

