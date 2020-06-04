<?php 
include("vt.php"); // veritabanı bağlantımızı sayfamıza ekliyoruz. 
?>

<!doctype html>
<html>
<head>
<meta charset="utf-8">
<meta charset="UTF-8">
	<title>İletişim</title>
	<link rel="stylesheet" href="css/bootstrap.css">
	<link rel="stylesheet" href="css/stillerim.css">
</head>
<body>

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
<p><br>Burada şehrim, takımım veya benim hakkımda yorumlarda bulunabilirsiniz.</p>
</div>	


<div class="container">
<div class="col-md-6">
<form action="" method="post">
    
    <table class="table">
        
        <tr>
            <td>Ad Soyad</td>
            <td><input type="text" name="baslik" class="form-control" ></td>
        </tr>
		<tr>
            <td>E-Posta</td>
            <td><input type="email" name="eporsta" class="form-control" ></td>
        </tr>

        <tr>
            <td>Yorum</td>
            <td><textarea name="icerik" class="form-control" ></textarea></td>
        </tr>

        <tr>
            <td></td>
            <td><p><input class="btn btn-primary"  type="submit" value="Gönder"> <input class="btn btn-danger"  type="submit" value="Temizle"></p></td>
			
        </tr>

    </table>

</form>

<!-- Öncelikle HTML düzenimizi oluşturuyoruz. Daha sonra girdiğimiz verileri veritabanına eklemesi için PHP kodlarına geçiyoruz. -->

<?php 

if ($_POST) { // Sayfada post olup olmadığını kontrol ediyoruz.

    // Sayfa yenilendikten sonra post edilen değerleri değişkenlere atıyoruz
    $baslik = $_POST['baslik']; 
    $icerik = $_POST['icerik'];

    if ($baslik<>"" && $icerik<>"") { 
    // Veri alanlarının boş olmadığını kontrol ettiriyoruz. Başka kontrollerde yapabilirsiniz.
        
         // Veri ekleme sorgumuzu yazıyoruz.
        if ($baglanti->query("INSERT INTO makale (baslik, icerik) VALUES ('$baslik','$icerik')")) 
        {
            echo "Veri Eklendi"; // Eğer veri eklendiyse eklendi yazmasını sağlıyoruz.
        }
        else
        {
            echo "Hata oluştu";
        }

    }

}

?>
</div>
<!-- ############################################################## -->


</body>
</html>