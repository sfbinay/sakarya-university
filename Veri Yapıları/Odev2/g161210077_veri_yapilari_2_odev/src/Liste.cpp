/**************************************************************************** 
 **							SAKARYA UNIVERSITY 
 **					  BILGISAYAR MUHENDISLIGI BOLUMU 
 **					  	VERI YAPILARI DERSI 2.ODEV
 **     
 **				OGRENCI ISMI.....: Süleyman Furkan BİNAY , Yasin OK
 **				OGRENCI NUMARASI.: G161210077 , B181210506
 **             OGRENCI GRUBU....:  2 - C
 **             MAIL ADRESLERI...: suleyman.binay@ogr.sakarya.edu.tr , yasin.ok1@ogr.sakarya.edu.tr
 ****************************************************************************/

#include "Liste.hpp"

using namespace std;

Liste::Liste()
{
    ilkEleman = NULL;
    tumVeri = "";
    boyut = 0;
    ifstream dosya("icerik.txt", ios::in);
    string eklenecek = "";
    if (dosya.is_open())
    {
        while (!dosya.eof())
        {
            dosya >> eklenecek;
            Dugum *ekle = new Dugum(eklenecek);
            for (int i = 0; i < boyut; i++)
            {
                if (getir(i)->icerikGetir() == ekle->icerikGetir())
                {
                    ekle->icerikAta("");
                    ekle->yonlendirmeAta(i); //burada eşleşen değerin indisini tutuyor. Odev dokumanından biraz farklı oldu fakat aynı mantıkla calısıyor.
                    break;
                }
            }
            if (ilkEleman == NULL)
            {
                ilkEleman = ekle;
            }
            else
            {
                Dugum *tutucu = ilkEleman;

                while (tutucu->ileriGetir() != NULL)
                {

                    tutucu = tutucu->ileriGetir();
                }
                tutucu->ileriAta(ekle);
                ekle->geriAta(tutucu);
            }
            boyut++;
            tumVeri = tumVeri + eklenecek;
        }
    }
    dosya.close();
}

Dugum *Liste::getir(int index)
{

    Dugum *tutucu = ilkEleman;
    for (int i = 0; i < index; i++)
    {
        tutucu = tutucu->ileriGetir();
    }
    return tutucu;
}
void Liste::yazdir()
{
    int sayac = 0;
    Dugum *tutucu = ilkEleman;
    cout << "NULL"
         << "<-";
    while (tutucu->ileriGetir() != NULL)
    {
        if (tutucu->icerikGetir() == "")
        {
            cout << sayac-tutucu->yonlendirmeGetir() << ":" << tutucu->icerikGetir() << "<->";
            tutucu = tutucu->ileriGetir();
        }
        else
        {
            cout << tutucu->yonlendirmeGetir() << ":" << tutucu->icerikGetir() << "<->";
            tutucu = tutucu->ileriGetir();
        }
        sayac++;
    }
    if (tutucu->icerikGetir() == "")
    {
        cout << sayac-tutucu->yonlendirmeGetir() << ":" << tutucu->icerikGetir() << "->"
             << "NULL" << endl;
    }
    else
    {
        cout << tutucu->yonlendirmeGetir() << ":" << tutucu->icerikGetir() << "->"
             << "NULL" << endl;
    }

    cout << "Kazanc : " << kacByteKazanc() << " Byte" << endl;
}
int Liste::kacByteKazanc()
{
    int byte = 0;
    Dugum *tutucu = ilkEleman;
    while (tutucu->ileriGetir() != NULL)
    {
        if (tutucu->icerikGetir() == "")
        {
            byte = byte + getir(tutucu->yonlendirmeGetir())->icerikGetir().length() - 1;
        }
        tutucu = tutucu->ileriGetir();
    }
    if (tutucu->icerikGetir() == "")
    {
        byte = byte + getir(tutucu->yonlendirmeGetir())->icerikGetir().length() - 1;
    }
    return byte;
}