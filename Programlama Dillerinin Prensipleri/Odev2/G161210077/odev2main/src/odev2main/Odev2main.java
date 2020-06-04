/**
*
* @author Süleyman Furkan Binay suleyman.binay@ogr.sakarya.edu.tr
* @since 10.03.2019-17.03.2019
* <p>
* Programlama Dillerinin Prensipleri 2.ödev.
* Fonksiyonlar parametre verilerek icra ettiriliyor.
* </p>
*/
package odev2main;
import benimpaketim.RastgeleKarakter;
/**
 *
 * @author furkan
 */
public class Odev2main {
    
    public static void main(String[] args) {
        
    RastgeleKarakter karakter = new RastgeleKarakter();//RastgeleKarakter sınıfından karakter adında nesne türetiliyor.

    //Rastgele büyük veya küçük harf üretilir.
    System.out.println("Rastgele Karakter:"+karakter.rastgeleHarf());
    System.out.println("Rastgele Karakter:"+karakter.rastgeleHarf());

    //Parametre olarak belirtilen değer kadar harf çıkarılır. 
    karakter.miktarlıRastgeleHarf(3);
    karakter.miktarlıRastgeleHarf(4);

    //Parametre olarak belirtilen 2 harf arasından yine parametre olarak verilen sayı kadar rastgele harf çıkarılır.
    //Bu işlemde büyük harfler kendi arasında küçük harfler kendi arasında düşünüldü.        
    karakter.ikiHarfArasi('a','k',1);
    karakter.ikiHarfArasi('b','k',2);
    
    //Parametre olarak belirtilen harfleri yine parametre olarak verilen sayı kadar rastgele çıkarır 
    karakter.belirtilenKarakterler('g', 'y', 'u', 'c','n', 'e',1);
    karakter.belirtilenKarakterler('g', 'y', 'u', 'c','n', 'e',1);
    karakter.belirtilenKarakterler('g', 'y', 'u', 'c','n', 'e',2);
    
    //Rastgele yazılan cümle
    karakter.cumle();
       
    }  
}
