#ifndef BST_H
#define BST_H

class BSTDugum
{
public:
	int sayi;
	int soy_sayisi;
	BSTDugum *pSol;
	BSTDugum *pSag;

	BSTDugum(int yeniSayi);
	void ekle(int yeniSayi);
	void cikar(int cikacakSayi, BSTDugum * ebeveyn);
	int enBuyukGetir();
	
private:
};

#endif // !BST_H
