<?php
    function Menu()
    {
?>
        <div class="topnav">
            <a href="index.php">Accueil</a>
            <a href="conso.php">consommation en temps réel</a>
            <a href="Electrique.php">consommation electrique en temps réel</a>
            <a href="temperature.php">Température en temps réel</a>
            <a href="historique.php">Historique de la consommation</a>
            <a href="parametre.php">Paramètres</a>
        </div>
<?php
    }
?>

<?php
    function Affichage_Temperature()
    {
        try
        {
            $db = new PDO('mysql:host=192.168.0.22;dbname=Consommation;charset=utf8','root','root');
        }
        catch(Exception $e)
        {
            die('Erreur : '.$e->getMessage());
        }
        
        $affiche = $db->query("SELECT * FROM Consommation");

        echo '<table id="customers">';
        echo '<tr>';
        echo '<th><center>ID</center></th>';
        echo '<th><center>Date</center></th>';
        echo '<th><center>ConsoEauCourante</center></th>';
        echo '<th><center>ConsoEauRecup</center></th>';
        echo '<th><center>ConsoElectrique (Kw)</center></th>';
        echo '</tr>';
        while ($donnee = $affiche->fetch())
        {
            echo '<tr>';
            echo "<td> ".$donnee['ID']."</td> ";
            echo "<td> ".$donnee['Date']."</td> ";
            echo "<td> ".$donnee['ConsoEauCourante']."</td> ";
            echo "<td> ".$donnee['ConsoEauRecup']."</td> ";
            echo "<td> ".$donnee['ConsoElectrique']."</td> ";
            echo '</tr>';
        }
        echo '</table>'; 
    }  
?>

<?php
    function Recherche()
    {
        try
        {
            $db = new PDO('mysql:host=192.168.0.22;dbname=Consommation;charset=utf8','root','root');
        }
        catch(Exception $e)
        {
            die('Erreur : '.$e->getMessage());
        }

        echo '<form method="POST" action="historique.php">';
        echo '<input type="text" name="annee1" id="annee1" placeholder="Année (0001 à ∞)">';
        echo '<p class="submit"><input name=rechercherAnnee type="submit" value="Filtrer par année"></p>';
        echo '</form>';

        echo '<form method="POST" action="historique.php">';
        echo '<select name="mois2" id="mois2" size="1">';
        echo '<option>1</option>';
        echo '<option>2</option>';
        echo '<option>3</option>';
        echo '<option>4</option>';
        echo '<option>5</option>';
        echo '<option>6</option>';
        echo '<option>7</option>';
        echo '<option>8</option>';
        echo '<option>9</option>';
        echo '<option>10</option>';
        echo '<option>11</option>';
        echo '<option>12</option>';
        echo '</select>';
        echo '<p class="submit"><input name=rechercherMois type="submit" value="Filtrer par mois"></p>';
        echo '</form>';

        if(isset($_POST['rechercherAnnee']))
        {
            $annee1=$_POST['annee1'];

            $affiche = $db->query("SELECT * FROM Consommation WHERE date LIKE '%$annee1%'");
        

            echo '<hr>';
            echo "<p>Tableau des températures reçues pour l'année ".$annee1."</p>";
            echo '<div class="tableau">';
            echo '<table id="customers">';
            echo '<tr>';
           echo '<th><center>ID</center></th>';
            echo '<th><center>Date de réception</center></th>';
            echo '<th><center>ConsoEauCourante</center></th>';
            echo '<th><center>ConsoEauRecup</center></th>';
            echo '<th><center>ConsoElectrique (Kw)</center></th>';
            echo '</tr>';
            while ($filtrage = $affiche->fetch())
            {
                echo '<tr>';
                echo "<td> ".$filtrage['ID']."</td> ";
                echo "<td> ".$filtrage['Date']."</td> ";
                echo "<td> ".$filtrage['ConsoEauCourante']."</td> ";
                 echo "<td> ".$filtrage['ConsoEauRecup']."</td> ";
                  echo "<td> ".$filtrage['ConsoElectrique']."</td> ";
                echo '</tr>';
            }
            echo '</table>'; 
            echo '</div>';
        }

        if(isset($_POST['rechercherMois']))
        {
            $mois2=$_POST['mois2'];

            $affiche = $db->query("SELECT * FROM Consommation WHERE date LIKE '%$mois2%'");
        
            echo '<hr>';
            echo "<p>Tableau des températures reçues pour le mois de ".$mois2."</p>";
            echo '<div class="tableau">';
            echo '<table id="customers">';
            echo '<tr>';
          echo '<th><center>ID</center></th>';
            echo '<th><center>Date</center></th>';
            echo '<th><center>ConsoEauCourante</center></th>';
            echo '<th><center>ConsoEauRecup</center></th>';
            echo '<th><center>ConsoElectrique (Kw)</center></th>';
            echo '</tr>';
            while ($filtrage = $affiche->fetch())
            {
                 echo '<tr>';
           echo "<td> ".$filtrage['ID']."</td> ";
                echo "<td> ".$filtrage['Date']."</td> ";
                echo "<td> ".$filtrage['ConsoEauCourante']."</td> ";
                 echo "<td> ".$filtrage['ConsoEauRecup']."</td> ";
                  echo "<td> ".$filtrage['ConsoElectrique']."</td> ";
            echo '</tr>';
            }
            echo '</table>'; 
            echo '</div>';
        }
    
    }
?>