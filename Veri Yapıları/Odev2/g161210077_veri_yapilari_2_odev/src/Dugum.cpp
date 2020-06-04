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
#include "Dugum.hpp"

using namespace std;

Dugum::Dugum(string _icerik)
{
    ileri = NULL;
    geri = NULL;
    icerik = _icerik;
    yonlendirme = 0;
}
Dugum *Dugum::ileriGetir()
{
    return ileri;
}
void Dugum::ileriAta(Dugum *_ileri)
{
    ileri = _ileri;
}
Dugum *Dugum::geriGetir()
{
    return geri;
}
void Dugum::geriAta(Dugum *_geri)
{
    geri = _geri;
}
string Dugum::icerikGetir()
{
    return icerik;
}
void Dugum::icerikAta(string _icerik)
{
    icerik = _icerik;
}
int Dugum::yonlendirmeGetir(){
    return yonlendirme;
}
void Dugum::yonlendirmeAta(int _yonlendirme){
    yonlendirme = _yonlendirme;
}