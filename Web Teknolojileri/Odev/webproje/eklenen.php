<?php 
include("vt.php"); // veritabanı bağlantımızı sayfamıza ekliyoruz. 
?>

<!DOCTYPE html>
<html lang="tr">
<head>
	<meta charset="UTF-8">
	<title>Gelen Yorumlar</title>
	<link rel="stylesheet" href="css/bootstrap.css">
	<link rel="stylesheet" href="css/stillerim.css">
		
</head>
<body>
	<div class="container">
	<div class="row">
	
	<div class="col-sm-3" id="baslik">
	<a href="index.html" class="degistir-link">Hakkımda</a></div>
	
	<div class="col-sm-3" id="baslik">
	<a href="sehrim.html" class="degistir-link">Şehrim</a></div>
	
	<div class="col-sm-3" id="baslik">
	<a href="takimimiz.html" class="degistir-link">Takımımız</a></div>
	
	<div class="col-sm-3" id="baslik">
	<a href="//localhost/webproje/ekle.php" class="degistir-link">İletişim</a></div>
	
	</div>
</div>

<div class="container">
<div class="row">
<div class="col-sm-3">
</div>

<!-- Veritabanına eklenmiş verileri sıralamak için önce üst kısmı hazırlayalım. -->
<div class="col-md-6">
<br>
<table class="table">
    
    <tr>
        <th>No</th>
        <th>Ad-Soyad</th>
        <th>Yorum</th>
        <th></th>
        <th></th>
    </tr>

<!-- Şimdi ise verileri sıralayarak çekmek için PHP kodlamamıza geçiyoruz. -->

<?php 

$sorgu = $baglanti->query("SELECT * FROM makale"); // Makale tablosundaki tüm verileri çekiyoruz.

while ($sonuc = $sorgu->fetch_assoc()) { 

$id = $sonuc['id']; // Veritabanından çektiğimiz id satırını $id olarak tanımlıyoruz.
$baslik = $sonuc['baslik'];
$icerik = $sonuc['icerik'];

// While döngüsü ile verileri sıralayacağız. Burada PHP tagını kapatarak tırnaklarla uğraşmadan tekrarlatabiliriz. 
?>
    
    <tr>
        <td><?php echo $id; // Yukarıda tanıttığımız gibi alanları dolduruyoruz. ?></td>
        <td><?php echo $baslik; ?></td>
        <td><?php echo $icerik; ?></td>
		<!--<td><a href="duzenle.php?id=<?php echo $id; ?>" class="btn btn-primary">Düzenle</a></td>-->
        <td><a href="sil.php?id=<?php echo $id; ?>" class="btn btn-danger">Sil</a></td>
    </tr>

<?php 
} 
// Tekrarlanacak kısım bittikten sonra PHP tagının içinde while döngüsünü süslü parantezi kapatarak sonlandırıyoruz. 
?>

</table>
</div>
<div class="col-sm-3">
</div>
</div>
</div>


</body>
</html>	