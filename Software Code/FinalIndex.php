<html>

<body>

<form method="get">
<!-- 
Number of Cars: <input type="text" name="cars">
<br>
<input type="submit">
-->
</form>

</body>
</html>

<?php
//y = 8.2119ln(x) + 0.1826

        $cars = $_GET["cars"];
	if(! empty($_GET["cars"])){
                $cars = $_GET["cars"];
                $sec = 8.2119*(log($cars))+ 0.1826;
                
                $servername = "fdb17.biz.nf";
                $username = "2363855_seconds";
                $password = "trafficcontroller2017";
                $dbname = "2363855_seconds";
                
                // Create connection
                $conn = new mysqli($servername, $username, $password, $dbname);
                // Check connection
                if ($conn->connect_error) {
                    die("Connection failed: " . $conn->connect_error);
                } 

                $sql = "SELECT seconds FROM controller";
                $result = $conn->query($sql);
                
                if ($result->num_rows > 0) {
                   $row = $result->fetch_assoc();
                   $now = $row["seconds"];
                    echo "the number of seconds is currently ".$now. "<br>";
                } else {
                    echo "0 results". "<br>";
                }
                
                $myfile=fopen("TrafficController.txt", "w") or die("Unable to open file!");
                
                if($sec>$now)   //need to increase the seconds of green
                {
                        $now=$now+1;
                        fwrite($myfile,"2");
                        echo "need to increase". "<br>";
                } else if($sec<$now)   //need to decrease the seconds of green
                {
                        if($now>0)
                        {
                                $now=$now-1;
                                fwrite($myfile,"1");
                                echo "need to decrease". "<br>";
                        }
                }
                fclose($myfile);
                
                $sql = "UPDATE controller SET seconds='$now' WHERE ind=1";                
                          echo "the number of seconds is now ".$now. "<br>";
                
                if ($conn->query($sql) === TRUE) {
                    echo "Record updated successfully";
                } else {
                    echo "Error updating record: " . $conn->error;
                }
                $conn->close();
                
                sleep(5);
		$myfile = fopen("TrafficController.txt", "w") or die("Unable to open file!");
		fwrite($myfile,"0");
		fclose($myfile);
	}
?>


