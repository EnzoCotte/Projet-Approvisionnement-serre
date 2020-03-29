
<html>
    <head>
		<meta charset="UTF-8">
		<link rel="stylesheet" href="style.css" />
        <link rel="icon" type="jpg" href="Lowranceonglet.jpg" />
        <title>Station Meteo</title>
        <?php 
            include 'fonction.php'; 
            Menu()
        ?>
	</head>

	<body>
        <div class="cadre">
            <div class="titre">
                <p>Serre Autonome</p>
            </div>
            <hr>
            <div class="sousTitre">
                <p>Température en temps réel :</p>  
            </div>   
            <div class="temperature">
                <p>15°C</p>


 <?php                
$ip = '109.219.28.79';
$port = 502;  //ex: 80 pour le http, 21 pour le ftp, 22 pour le ssh
 
$fd = fsockopen ($ip, $port, $errno, $errstr, 30);
 
if($fd) {
    echo("connexion ok" );
} else {
    echo("connexion hs" );
}
?>
            </div>
        </div>
    </body>
</html>