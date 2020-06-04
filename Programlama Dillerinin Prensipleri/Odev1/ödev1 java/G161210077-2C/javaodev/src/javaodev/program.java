/**
*
* @author Süleyman Furkan Binay suleyman.binay@ogr.sakarya.edu.tr
* @since 25.02.2019-03.03.2019
* <p>
* -
* </p>
*/
package javaodev;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author furkan
 */
public class program {
     ArrayList<String> satir = new ArrayList<>();//array list den satır adında nesne üretiliyor
    BufferedReader br = null;//okumak için BufferReader br nesnesi üretiliyor
    
    public program() {
    
        try {
            br = new BufferedReader(new FileReader("Program.c"));
            String line;
            while ((line = br.readLine()) != null) 
            {                
                satir.add(line);
            }
        } 
        catch (IOException e) 
            {
                
            }
        }
          
    public void bas(String yeni)//Fonksiyon isimlerini yazdırırken aralarda yorum satırı varsa onu siler.
    {                           //Yazacağı satırı harf harf char dizisine atar ona göre işlem yapar.
                                //En sonda da karakter karakter yazar.Bir satır da /* */ şeklinde birden fazla yorum olması düşünülmedi.
        int satirHarfSayisi = yeni.length();
        char harfler[] = new char [yeni.length()+1];        
        for(int i =0; i<yeni.length();i++)
        {
            harfler[i]=yeni.charAt(i);
        }  
        
         int baslangic=0;
         int son=0;
         
         for(int i=0;i<yeni.length();i++)
         {
             if(harfler[i]=='/'&&harfler[i+1]=='*')
             {
                 baslangic = i ;
             }
         }
         
         for(int i=0;i<yeni.length();i++)
         {
             if(harfler[i]=='*'&&harfler[i+1]=='/')
             {
                 son = i+1 ;
             }
         }
         
         for(int i=0;i<yeni.length();i++)
         {
             if(harfler[i]=='m')//0.indisde yorum satırı yok ve mainin m harfinin silinmemesi için.
             {
                 
             }
             else if(i>=baslangic && i<=son)
             {
                 continue;
             }
             else if(harfler[i]=='/' &&harfler[i+1]=='/')
             {
                 break;
             }
             System.out.print(harfler[i]);
         }
         System.out.println("");
    }
    
     
    public void parametreSayisi(){//önce parantez içinde virgul olanlara bakıldı virgül varsa virgül sayısı+1 den parametre hesaplandı
                                  //tek parametreleri olanlar yani virgül olmayanlar parantez içine göre işlem yapıldı          
        int sayac=0;
        for (int i = 0; i < satir.size(); i++) {
            
            //satır satır düşünüldüğünde fonksiyon yapısına benzerliği olanlar ihlal edildi.
            if(satir.get(i).contains("for")||satir.get(i).contains("while")||satir.get(i).contains("scanf")
                    ||satir.get(i).contains("printf")||satir.get(i).contains("malloc"))                                                                                       
            {
                continue;
            }
            
            if(satir.get(i).contains("void"))
               {
                   if(satir.get(i).contains(","))
                   {
                       String virgul ="[,]";
                        Pattern pattern = Pattern.compile(virgul);
                        Matcher eslesme = pattern.matcher(satir.get(i));

                        while(eslesme.find()) 
                        {
                            sayac++;   
                        }
                        sayac++;
                   }
                   else
                   {
                       int baslangic=0;
                       int son=0;
                       for(int j=0;j<satir.get(i).length();j++)
                       {
                           if(satir.get(i).charAt(j)=='(')
                           {
                             baslangic=j;
                           }
                           if(satir.get(i).charAt(j)==')')
                           {
                             son=j;
                           }
                       }
                       if((son-baslangic)>4)
                       {
                           sayac++;
                       }
                   }
                        
               }
            
            else if(satir.get(i).contains("int")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                    if(satir.get(i).contains(","))
                   {
                        String virgul ="[,]";
                        Pattern pattern = Pattern.compile(virgul);
                        Matcher eslesme = pattern.matcher(satir.get(i));

                        while(eslesme.find()) 
                        {
                            sayac++;   
                        }
                        sayac++;                    
                   }
                    else
                   {
                       int baslangic=0;
                       int son=0;
                       for(int j=0;j<satir.get(i).length();j++)
                       {
                           if(satir.get(i).charAt(j)=='(')
                           {
                             baslangic=j;
                           }
                           if(satir.get(i).charAt(j)==')')
                           {
                             son=j;
                           }
                       }
                       if((son-baslangic)>4)
                       {
                           sayac++;
                       }
                   }
               }
            else if(satir.get(i).contains("main")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {                   
                  if(satir.get(i).contains(","))
                   {
                        String virgul ="[,]";
                        Pattern pattern = Pattern.compile(virgul);
                        Matcher eslesme = pattern.matcher(satir.get(i));

                        while(eslesme.find()) 
                        {
                            sayac++;   
                        }
                        sayac++;
                   }
                  else
                   {
                       int baslangic=0;
                       int son=0;
                       for(int j=0;j<satir.get(i).length();j++)
                       {
                           if(satir.get(i).charAt(j)=='(')
                           {
                             baslangic=j;
                           }
                           if(satir.get(i).charAt(j)==')')
                           {
                             son=j;
                           }
                       }
                       if((son-baslangic)>4)
                       {
                           sayac++;
                       }
                   }
               }
            else if(satir.get(i).contains("float")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                    if(satir.get(i).contains(","))
                   {
                       String virgul ="[,]";
                        Pattern pattern = Pattern.compile(virgul);
                        Matcher eslesme = pattern.matcher(satir.get(i));

                        while(eslesme.find()) 
                        {
                            sayac++;   
                        }
                        sayac++;
                   }
                    else
                   {
                       int baslangic=0;
                       int son=0;
                       for(int j=0;j<satir.get(i).length();j++)
                       {
                           if(satir.get(i).charAt(j)=='(')
                           {
                             baslangic=j;
                           }
                           if(satir.get(i).charAt(j)==')')
                           {
                             son=j;
                           }
                       }
                       if((son-baslangic)>4)
                       {
                           sayac++;
                       }
                   }
               }
            else if(satir.get(i).contains("char")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                    if(satir.get(i).contains(","))
                   {
                       String virgul ="[,]";
                        Pattern pattern = Pattern.compile(virgul);
                        Matcher eslesme = pattern.matcher(satir.get(i));

                        while(eslesme.find()) 
                        {
                            sayac++;   
                        }
                        sayac++;
                   }
                    else
                   {
                       int baslangic=0;
                       int son=0;
                       for(int j=0;j<satir.get(i).length();j++)
                       {
                           if(satir.get(i).charAt(j)=='(')
                           {
                             baslangic=j;
                           }
                           if(satir.get(i).charAt(j)==')')
                           {
                             son=j;
                           }
                       }
                       if((son-baslangic)>4)
                       {
                           sayac++;
                       }
                   }
               }
            else if(satir.get(i).contains("double")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                    if(satir.get(i).contains(","))
                   {
                       String virgul ="[,]";
                        Pattern pattern = Pattern.compile(virgul);
                        Matcher eslesme = pattern.matcher(satir.get(i));

                        while(eslesme.find()) 
                        {
                            sayac++;   
                        }
                        sayac++;
                   }
                    else
                   {
                       int baslangic=0;
                       int son=0;
                       for(int j=0;j<satir.get(i).length();j++)
                       {
                           if(satir.get(i).charAt(j)=='(')
                           {
                             baslangic=j;
                           }
                           if(satir.get(i).charAt(j)==')')
                           {
                             son=j;
                           }
                       }
                       if((son-baslangic)>4)
                       {
                           sayac++;
                       }
                   }
               }
            else if(satir.get(i).contains("bool")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                    if(satir.get(i).contains(","))
                   {
                       String virgul ="[,]";
                        Pattern pattern = Pattern.compile(virgul);
                        Matcher eslesme = pattern.matcher(satir.get(i));

                        while(eslesme.find()) 
                        {
                            sayac++;   
                        }
                        sayac++;
                   }
                    else
                   {
                       int baslangic=0;
                       int son=0;
                       for(int j=0;j<satir.get(i).length();j++)
                       {
                           if(satir.get(i).charAt(j)=='(')
                           {
                             baslangic=j;
                           }
                           if(satir.get(i).charAt(j)==')')
                           {
                             son=j;
                           }
                       }
                       if((son-baslangic)>4)
                       {
                           sayac++;
                       }
                   }
               }
        } 
        System.out.println("Toplam Parametre Sayısı :"+sayac);
    }  
            
    
    public void fonksiyonAdi(){
    
        System.out.println("Fonksiyon İsimleri:");
        int sayac = 0;
        
        for (int i = 0; i < satir.size(); i++) {//satır satır fonksiyon yapısına benzer olanlar seçildi
            
            //satır satır düşünüldüğünde fonksiyon yapısına benzerliği olanlar ihlal edildi.
            if(satir.get(i).contains("for")||satir.get(i).contains("while")||satir.get(i).contains(";")
                    ||satir.get(i).contains("printf")||satir.get(i).contains("malloc"))                                                                                       
            {
                continue;
            }
            
            if(satir.get(i).contains("void"))
               {
                   String yeni;
                yeni = satir.get(i).replace("void", "");
        
                   yeni = yeni.replace("{", "");
                   yeni = yeni.replace("(", " - Parametreler:");
                   yeni = yeni.replace("int", "");
                   yeni = yeni.replace("double", "");
                   yeni = yeni.replace("float", "");
                   yeni = yeni.replace("char", "");
                   yeni = yeni.replace(")", "");
                   bas(yeni);
               }
            
            else if(satir.get(i).contains("int")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                   String yeni;
                yeni = satir.get(i).replace("int", "");
        
                   yeni = yeni.replace("{", "");
                   yeni = yeni.replace("(", " - Parametreler:");
                   yeni = yeni.replace("int", "");
                   yeni = yeni.replace("double", "");
                   yeni = yeni.replace("float", "");
                   yeni = yeni.replace("char", "");
                   yeni = yeni.replace(")", "");
                   bas(yeni);
               }
            else if(satir.get(i).contains("main")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                   String yeni;
                yeni = satir.get(i).replace("int", "");
        
                   yeni = yeni.replace("{", "");
                   yeni = yeni.replace("(", " - Parametreler:");
                   yeni = yeni.replace("int", "");
                   yeni = yeni.replace("double", "");
                   yeni = yeni.replace("float", "");
                   yeni = yeni.replace("char", "");
                   yeni = yeni.replace(")", "");
                   bas(yeni);
               }

            else if(satir.get(i).contains("float")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                   String yeni;
                yeni = satir.get(i).replace("int", "");
        
                   yeni = yeni.replace("{", "");
                   yeni = yeni.replace("(", " - Parametreler:");
                   yeni = yeni.replace("int", "");
                   yeni = yeni.replace("double", "");
                   yeni = yeni.replace("float", "");
                   yeni = yeni.replace("char", "");
                   yeni = yeni.replace(")", "");
                   bas(yeni);
               }
            else if(satir.get(i).contains("double")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                   String yeni;
                yeni = satir.get(i).replace("int", "");
        
                   yeni = yeni.replace("{", "");
                   yeni = yeni.replace("(", " - Parametreler:");
                   yeni = yeni.replace("int", "");
                   yeni = yeni.replace("double", "");
                   yeni = yeni.replace("float", "");
                   yeni = yeni.replace("char", "");
                   yeni = yeni.replace(")", "");
                   bas(yeni);
               }
            else if(satir.get(i).contains("char")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                   String yeni;
                yeni = satir.get(i).replace("int", "");
        
                   yeni = yeni.replace("{", "");
                   yeni = yeni.replace("(", " - Parametreler:");
                   yeni = yeni.replace("int", "");
                   yeni = yeni.replace("double", "");
                   yeni = yeni.replace("float", "");
                   yeni = yeni.replace("char", "");
                   yeni = yeni.replace(")", "");
                   bas(yeni);
               }
            else if(satir.get(i).contains("bool")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
               {
                   String yeni;
                yeni = satir.get(i).replace("int", "");
        
                   yeni = yeni.replace("{", "");
                   yeni = yeni.replace("(", " - Parametreler:");
                   yeni = yeni.replace("int", "");
                   yeni = yeni.replace("double", "");
                   yeni = yeni.replace("float", "");
                   yeni = yeni.replace("char", "");
                   yeni = yeni.replace(")", "");
                   bas(yeni);
               }
        }     
       }
    
    public void fonksiyonSayisi()//fonksiyon protitipini içeren satılar seçilerek fonksiyon sayısı belirlendi
    {                          
        int sayac=0;
        for(int i=0;i<satir.size();i++)
        {
            
            //fonksiyon protitipine benzer olan satırlar geçildi
            if(satir.get(i).contains("for")||satir.get(i).contains("while")||satir.get(i).contains(";")
                    ||satir.get(i).contains("printf")||satir.get(i).contains("malloc")||satir.get(i).contains("Scanf"))                                                                                       
            {
                continue;
            }
            
            
            if(satir.get(i).contains("void")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
            {
                sayac++;
            }
            else if(satir.get(i).contains("int")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
            {               
                sayac++;
            }
            else if(satir.get(i).contains("main")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
            {               
                sayac++;
            }
            else if(satir.get(i).contains("float")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
            {               
                sayac++;
            }
            else if(satir.get(i).contains("double")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
            {               
                sayac++;
            }
            else if(satir.get(i).contains("char")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
            {               
                sayac++;
            }
            else if(satir.get(i).contains("bool")&&satir.get(i).contains("(")&&satir.get(i).contains(")"))
            {               
                sayac++;
            } 
        }
        System.out.println("Toplam Fonksiyon Sayısı: "+sayac);
    }
    
    public void operatorSayisi()
    {
        String operator []={"[+]","[-]","[/]","[*]","[&]","[<]","[>]","[=]","[|]"};
        String ikiliOperator[]={"[+][+]","[-][-]","[=][=]","[|][|]","[&][&]"};
        String istisna = "[%][=]";
        int sayac = 0;
        
        //Tüm operatorler önce 1 er 1 er sayılıyor 
        //Sonra ikili fazlalık olanlar(++ -- ==..) 1 er azaltılıyor 
       
        for(int i=0;i<satir.size();i++)//array listte satir satir dönen for
        {
            for (String operator1 : operator) //satirda operatörleri döndüren for
            {
               if(satir.get(i).contains("#"))
                {
                    continue;
                }
                
                Pattern pattern = Pattern.compile(operator1);
                Matcher eslesme = pattern.matcher(satir.get(i));
                
                while(eslesme.find()) 
                {
                    sayac++;   
                }
            }
        }
        for(int i=0;i<satir.size();i++)//array listte satir satir dönen for
        {
            for (String ikiliOperator1 : ikiliOperator) //satirda operatörleri döndüren for
            {
                Pattern pattern = Pattern.compile(ikiliOperator1);
                Matcher eslesme = pattern.matcher(satir.get(i));
                
                while(eslesme.find()) 
                {
                    sayac--;   
                }
            }
        }
        for(int i=0;i<satir.size();i++)//array listte satir satir dönen for
        {
                Pattern pattern = Pattern.compile(istisna);
                Matcher eslesme = pattern.matcher(satir.get(i));
                
                while(eslesme.find()) 
                {
                    sayac=sayac+2;   
                }
            
        }
                 System.out.println("Toplam Operator Sayısı: "+sayac);      
    }     
}
