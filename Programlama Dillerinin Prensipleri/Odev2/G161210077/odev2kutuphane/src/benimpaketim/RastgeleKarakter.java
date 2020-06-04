/**
*
* @author Süleyman Furkan Binay suleyman.binay@ogr.sakarya.edu.tr
* @since 10.03.2019-17.03-2019
* <p>
* Programlama Dillerinin Prensipleri 2. ödev
* Rastgelelik için zaman kullanıldı.Bunun için de System.nanoTime() fonksiyonundan sistem zamanı getirildi.
* </p>
*/
package benimpaketim;

/**
 *
 * @author furkan
 */
public class RastgeleKarakter {
    
    public int rastgeleSayi()//harflere ASCII değer karşılığı için rastgele bir integer değer bulunuyor.
    {
        long baslaZaman = System.nanoTime();//baslangıç zamanı rastgele değer için
        long fark=0;//Zaman farkı
        for(int i=0;i<19999;i++)//Belirgin bir zaman farkı oluşması için sisteme iş yaptırlıyor.
        {
            System.out.print("");
        }
        long durZaman = System.nanoTime();//fark için durdurma zamanı
  
        fark = durZaman-baslaZaman;//Rastgele deger için iki zaman arası fark kullanılıyor.Böylece negatif değerde çıkmıyor.
        int son = (int)fark;
        
        return son;  
    }//public int rastgeleSayi son.
    
    public char rastgeleHarf()
    {
        if(rastgeleSayi()%2==1)//2 ye göre mod alınıyor.Sayı tek veya çift olma durumuna göre harf büyük veya küçük yazdırılıyor
            {                                      
                int rastgeleSayi = rastgeleSayi()%26+65;//büyük harflerde 27 ye göre mod alınıyor çıkan değere 65 eklenerek ASCII ye göre karşılığı bulunuyor     
                char harf = (char) rastgeleSayi;
                return harf;
            }
            
             else
            {                                      
                int rastgeleSayi = rastgeleSayi()%26+97;//küçük harflerde 27 ye göre mod alınıyor çıkan değere 97 eklenerek ASCII ye göre karşılığı bulunuyor     
                char harf = (char) rastgeleSayi;
                return harf;
            }       
    }//public char rastgeleHarf son.

    public void miktarlıRastgeleHarf(int deger)//kaç karakter basılacağı dışarıdan (main den) parametre olarak alınıyor
    {
       System.out.print("Rastgele "+deger+" karakter:");
       for(int i=0;i<deger;i++)//verilen değer kadar döngü döner ve arka arkaya harfler basılır
       {
           System.out.print(rastgeleHarf());//basılan rastgele harfler için rastgeleHarf() fonksiyonu kullanıldı.
       }
       System.out.println();//harf basma işlemi bittikten sonra alt satıra geçilmesi için println kullanıldı.
    }//public void miktarlıRastgeleHarf son.
    
    
    public void ikiHarfArasi(char harf1,char harf2,int adet)
    {
        System.out.print("Verilen iki karakter("+harf1+","+harf2+"):");
        int deger1=(int)harf1;//harf1 ve harf2 ASCII karşılığının bulunması için integer a çevriliyor
        int deger2=(int)harf2;
        int sayac=1;//döngü içinde adetle ile eşleşme için.
        
        if(deger1>96 && deger1<123 && deger2>96 && deger2<123)//ASCII'ye göre küçük harflerler arasını bulma
        {
            while(true)//ara harfi bulana kadar döngü dönüyor
            {
                if(adet<1)//parametre olarak verilen kaç harf çıkarılacağı 1 den küçükse döngüden çıkılıyor.
                {
                    break;
                }
                
                int rastgeleDeger = (int) rastgeleHarf();//rastgeleHarf() fonksiyonundan getirilen harf integer a çevriliyor
                
                if(deger1<rastgeleDeger && rastgeleDeger<deger2)//iki harfin arasında olmasının integer şartı
                {
                    char araHarf = (char)rastgeleDeger;//şart sağlandıktan sonra integer deger char a çevriliyor ve ara harf bulunuyor.
                    System.out.print(araHarf);
                    
                    if(sayac==adet)//sayac basılacak harf sayısına ulaşına döngüden çıkılır
                    {
                        System.out.println("");
                        break;//ara harf bulunduğunda döngüden çıkılıyor                        
                    }
                    else
                    {
                        sayac++;
                    }
                }
            }            
        }
        
        else if(deger1>64 && deger1<91 && deger2>64 && deger2<91)//ASCII'ye göre büyük harfler arasını bulma
        {
           while(true)//ara harfi bulana kadar döngü dönüyor
            {
                if(adet<1)//parametre olarak verilen kaç harf çıkarılacağı 1 den küçükse döngüden çıkılıyor.
                {
                    break;
                }
               
                int rastgeleDeger = (int) rastgeleHarf();//rastgeleHarf() fonksiyonundan getirilen harf integer a çevriliyor
                
                if(deger1<rastgeleDeger && rastgeleDeger<deger2)//iki harfin arasında olmasının integer şartı
                {
                    char araHarf = (char)rastgeleDeger;//şart sağlandıktan sonra integer deger char a çevriliyor ve ara harf bulunuyor.
                    System.out.print(araHarf);
                    
                    if(sayac==adet)//sayac basılacak harf sayısına ulaşına döngüden çıkılır
                    {
                        System.out.println("");
                        break;//ara harf bulunduğunda döngüden çıkılıyor                        
                    }
                    else
                    {
                        sayac++;//1 tane ara harf bulundugunda baska ara harflerinde bulunmasi icin donguyu kontrol eden sayac 1 arttiriliyor.
                    }
                }
            } 
        }
                   
    }//public void ikiHarfArasi son.
    
      
    public void belirtilenKarakterler(char harf1,char harf2,char harf3,char harf4
                                       ,char harf5,char harf6,int adet)
    {
        System.out.print("Belirtilen Karakterler("+harf1+","+harf2+","+harf3+","
                        +harf4+","+harf5+","+harf6+"):");
        //Belirtilen harflerin ASCII karşılığı için integer tipe çevriliyor.
        int deger1 = (int)harf1;
        int deger2 = (int)harf2;
        int deger3 = (int)harf3;
        int deger4 = (int)harf4;
        int deger5 = (int)harf5;
        int deger6 = (int)harf6;
        
        int sayac = 1; //kaç adet harf basılacığının kontrolü için sayaç tutuluyor.
        
        while(true)
        {
            if(adet<1)//parametre olarak verilen kaç harf çıkarılacağı 1 den küçükse döngüden çıkılıyor.
            {
                break;
            }
            int rastgeleDeger = (int)rastgeleHarf();//rastgele harf fonksiyonundan bir harf getirilip integer degeere cevriliyor
            //rastgele harf ile belirtilen harflerin ASCII değerleri karşılaştırılıyor 
            if(rastgeleDeger == deger1 || rastgeleDeger == deger2 || rastgeleDeger == deger3
                    || rastgeleDeger == deger4 || rastgeleDeger == deger5 || rastgeleDeger == deger6)
            {
                char eslesme = (char)rastgeleDeger;//ASCII karşılıklar eşit çıkarsa eşleşen integer değer char tipine çevriliyor
                System.out.print(eslesme); //ekrana yazdırılıyor.
                
                if(sayac==adet)//eğer sayac istenen harf sayısıyla aynıysa döngüden çıkılıyor.
                {
                    System.out.println();
                    break;
                }
                else
                {
                    sayac++;
                }
            }
            
        }      
    }//public char belirtilenKarakterler son.
   
    
    public void cumle()
    {
        System.out.print("Rastgele Cumle: ");
        int kelimeSayisi=(rastgeleSayi()%7)+1;//Cumledeki kelime sayisi belirleniyor en fazla 7 kelimeden oluşacağı düşünüldü.
         
        for(int i=0;i<kelimeSayisi;i++)
        {
            int kelimeHarfSayisi = (rastgeleSayi()%9)+1;//bir kelimede en fazla 9 harf olacağı düşünüldü.
            
            if(i==0)//Cumlede ilk kelimenin ilk harfi buyuk olmalıdır bu yüzden o ayrıca çıkarılıyor.
            {
                char ilkHarf = (char)(rastgeleSayi()%26+65);//Rastgele sayı fonksiyonundan gelen sayı ASCII karşılığına göre büyük harfe çeviriliyor
                System.out.print(ilkHarf);
                
                if(kelimeSayisi==0 && kelimeHarfSayisi==0)
                {
                    System.out.print("!.");
                    break;
                }     
            }
            
            for(int j=0;j<kelimeHarfSayisi;j++)
            {
              if(i==0 && 1<kelimeHarfSayisi)
              {
                  j++;
              }            
              char ilkHarf = (char)(rastgeleSayi()%26+97);//Rastgele sayı fonksiyonundan gelen sayı ASCII karşılığına göre küçük harfe çeviriliyor
              System.out.print(ilkHarf);
            }
        
            if(i+1==kelimeSayisi)//Son kelimenin sonuna boşluk bırakılmadan nokta konulması için.
            {
                break;
            }
            System.out.print(" ");
            
        }
        
          System.out.println(".");
    }//public void cumle() son.
}//public class RastgeleKarakter()son.
