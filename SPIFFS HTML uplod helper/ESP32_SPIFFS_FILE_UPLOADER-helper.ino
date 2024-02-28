const char indexHTML[] PROGMEM{ R"uniquetag(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Nexus Hera service</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no"/>
    <link rel="stylesheet" type="text/css" href="style.css">
    <link rel="icon" href="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADIAAAAyCAMAAAAp4XiDAAAAAXNSR0IB2cksfwAAAAlwSFlzAAAOxAAADsQBlSsOGwAAAY9QTFRFAAAAEXqZEoCfEoCfEXybDVxyEn+fEoKiEoGgEXuZEoGhEoGhEXqZEn6cEoGhEXqYEHCLEn6dEoGhEXqXEHKPEn+eEXmWEHSQEn+eEoGhEXqYEXiWEn+eEoGhEXyaEHSQEn+eEoGgEXuZEHmWEn+fEoCgEXuZEXeTEoCfEoCfEXmXEHWSEn+fEoCgEXmXEHKOEn+fEoCgEXaTEoCfEoCgEHWREHiUEoCfEHeUEHiWEoCfEoCfEXiWEXqXEoCfEoCfEXqYEHmXEoCgEn+fD2yGEXmWEoCgEXybEHaTEoGgEn+eC01gEXyaEoCfEHKOEXybC01hEX2bEn+fD22HEoCfEXqXEoGgEXaTEoCgEHaTEoCgEXmXEXuZEoGgEXyaEoGgEXqZEoGhEXuZEXuZEoGhEXqYEHGMEoGhEXuZD3CLEXmYEXqYEXqYDmV+EoGhEXmXD2uGEn+eEoKiEn2dEoGhEXeUEoGgEoGgEoCfEoGhEXybEHWREoCgEn+fEXuZEoCfEn+fEX2bEXybEn+eEoCfQDJxlAAAAIV0Uk5TADeutUwB2//pTPn0QZztOgWi9UYIq0IMofJAFablPxC45jIZvNU2FMDSLBHC3SIO0tgayeEXF88aIMTQHinIvyQl2cEHIdpZH+2gAXrDDXsBWsMHxyfoHt8i5Ckz2z3sOupISe9LBfhQBjlMMgHwQwWt/pf3NO/42exTGtvZOLK4UE7Lse2kyUQAAAFUSURBVHic3dVVUwNBDAfwQxeX4lrcrbiXFlrc3d0p7lKKfHAul6fezDH5vzHkcWd+s5vdbKJp/yhCQsPCIzASqVRUNEZilFKxcRCJ14lKSERIUjIZWwpiUtOMfdIRk5FJJisbMTm5ZPLyEWMvIFNYhJjiEjKlZYgpryBTWYWY6hoytXWIqW8g42hEjL2JTHMLYlrbjHzaEdPRSaarGzE9vWScfYhxucn0DyDG4yUziBBtaFgnI6OQGdPJ+AREJmHCB5sCBKc/DQi+5JlZueCnnJuXCy4Yt0suuCy9Hrng4l9YlAv+YkvLcsEfeWVVLrhdONbkgpvS+oZccOvb3JILbrDbO3LBbdy2Kxc8LPb25eLAGEmHR0GLxyenVnHm48F3fhEkLq+UZVzfGOP11pTH3b01UQ/ao1JPz6bDvrz+Qt40/3vgw2dO8DPwZRXffvk9/f34AYz7SMZiIB+zAAAAAElFTkSuQmCC">
</head>
  <body>
    <div class="topnav">
	<img class="logo" alt="" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADIAAAAyCAYAAAAeP4ixAAAAAXNSR0IB2cksfwAAAAlwSFlzAAAOxAAADsQBlSsOGwAABdlJREFUeJztmWtsk1UYxzsGwyHDcdN4yZboRJFgUENIlniLicGEmKgRNMFEPvBB4oxRE0QkJkoCHxTBTyoQNN41fvAS1ESMF/ASUNkQ5Rq2sTHo1nZv13bteznH3zMrqW/7tm+7tvND/8nJuvU9//N/nvOc53nOu0CghhpqqKEUHIuqxnBKzR2xdGvU1PMY82Xw+9VRS7eEUmrOEUNNnWidWeiNqysTtu4wHf2GpfQ+R+mTjKDSeoSfJkMxnPRn+ds5xgme/UHmMPdROK6quvD+uGqO2/peRGxHzHFdJggXnDvgvqcvoZsrIv74iDPJsPR1KUdvtJXuxNupchnghnCzxkFZS0LyeFRNKosRwaRuhXQb4RCulHgvsGaItV9GQ0vJBoRSunnU1s/ioWS1DXBDKZ0ULYNJPasoIwxTtxOze8YrAA6bMBlhGHxOqfHz/US43VzQACyeRhZ5Qo2Fqj/woE0InLYc/Q2H9RXS7CpCYfGPg85sN/9XA870gYRayDMPEDIv8fyXzO0VjmIMQuO6oaRqymnE2VHVDPl7POf4IZP4Tdp657Cpl/Qn1EVFbXkGmDtDOJKO3gVnxK//cMKnGDPXtROqhe0/XHA2+tneAzFLL98bdKaUKt4LXcOqAe6VrNHpx6FoPhlK6raxyVTha/HEqUKTID9Jjr87mFQXltsANwjNJqlVCO0upAvtPdgwL8AW7S2wCxYZYwuhlzsmwUe9dl04pS/hIN5C/D4H58cY/jNCjvFzAI4gn89J0WPsJYR3jVhqZcTUbYcN751lzRmsvVU05NPIet8HsMjzIb47w1Yv5eDW5VroaFQ1sdC6dGsyqItIEmknJaT4cT4298Rd8Z7Gr2GnDg13iRYvHjjMgO3xAOK+G0qprEL0Wb9dN2yqhXhhJ+TRYoTnA1wJON8yTLXo26Cd5TjOQgvf79Y5nIXWvgAe7cgsepIKmfAm236pmyySUlcQFptZ9Gy5DMhh0DnW2ESoXu5en6QkmXVHZrqWlgYbngx0x1Q9cb0Kqz6XQUp9vDOisuKW3H8ru3eoUga4wVq/c+ba3Tp+CzuTCcWn5VyYSn+NEasJy8m5wvI/6I459ekiWVKjOJ5qztxRsteaI4ZTX1BoPvQl1BQsXq/8F8mUHHy89RohsDa90/czVojn+Nt6adX5/Rc4TZ/G2Mx9CocW9roXELLBz0KEwX7ZNcJ0pl/u7riajbc7mHvAT4sC/zMlGdE/qi4u5DVEnIqaailtRkNJiwTGWpQG4bALFGXRctojRecF1fKmPKSSKTZBXLa7N1wNcG7MdxbJmjcWT0wzh5dibjLOwRAhsfzd7uxcL9hz1plC6ryd7Pc8HfHbkvsZXzDe4W8v8N0d+4KO5w5KayJ3/hy7H+MKPKNoQ8ZILX0fpEYG2SGqbM77gHSwiH09XeHzQpwhd35S+m25uFijnbX+zHjeEANLMkLQG1eTRky9iLz92KijV1HRL8vxzAV4eksRLfh5EEYGc7ey+43ZjlGthNojUuzQcINoKdmQQoik9HxSaVexBrgBxx9wLaiY0Hyge11sl/F1kNwtCLUlVTWC9npWOY3IMOYEV2HftWjc4OA9mE+Q5HxEHSFrvc/52iaDw/0h5+hYodpE4VtRTUMe8hIiZ4YQWdpHEnDPo+Vp5Ltl+a7VcD9cNUOGUrqV5stdY+SFwCc9MTW90Hy61SZ5Vrt6OKV0nDrTVg0bziP2T40ZToeSQ/hs5+z4vs/z7DTmvPjvqye5pMUstbySmj1xeNiZaph6/qmYyvnSuSvi1A2MqpmM5v2h3Ndlasgceq3r/zKya8n/AhIinBd5AXeG0c/n3aFqh814EbV0Gwf6qPsgS8pmB6+ZaH2+Qeyv9cpKXK42TLQ+35BO18sQduWDidbnG/L/FC9DMPLVidbnG7T/d8qLA7cR8tqJyr1sovX5xr4hpw7Bq6l24QwjIrTkaw5GnMq145WCwf0FGxbIiFoq64VbDTXUUEPR+Bugif5xpCqJYQAAAABJRU5ErkJggg==" />
	<h1> Hera web service</h1>
    </div>
    <div class="content">
      <div class="card-grid">
        <div class="card">
			<p class="card-title">
				<img class="logo" alt="logo" src="data:image/png;base64,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" />
				GPIO 7
			</p>
			<p class="cntr">
				<a href="on"><button class="button-on">ON</button></a>
				<a href="off"><button class="button-off">OFF</button></a>
			</p>
          <p class="state">State: %STATE%</p>
        </div>
      </div>
    </div>
  </body>
</html>
)uniquetag" };

const char wifimanager[] PROGMEM{ R"uniquetag(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Nexus Wi-Fi Manager</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no"/>
    <link rel="stylesheet" type="text/css" href="style.css">
    <link rel="icon" href="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADIAAAAyCAMAAAAp4XiDAAAAAXNSR0IB2cksfwAAAAlwSFlzAAAOxAAADsQBlSsOGwAAAY9QTFRFAAAAEXqZEoCfEoCfEXybDVxyEn+fEoKiEoGgEXuZEoGhEoGhEXqZEn6cEoGhEXqYEHCLEn6dEoGhEXqXEHKPEn+eEXmWEHSQEn+eEoGhEXqYEXiWEn+eEoGhEXyaEHSQEn+eEoGgEXuZEHmWEn+fEoCgEXuZEXeTEoCfEoCfEXmXEHWSEn+fEoCgEXmXEHKOEn+fEoCgEXaTEoCfEoCgEHWREHiUEoCfEHeUEHiWEoCfEoCfEXiWEXqXEoCfEoCfEXqYEHmXEoCgEn+fD2yGEXmWEoCgEXybEHaTEoGgEn+eC01gEXyaEoCfEHKOEXybC01hEX2bEn+fD22HEoCfEXqXEoGgEXaTEoCgEHaTEoCgEXmXEXuZEoGgEXyaEoGgEXqZEoGhEXuZEXuZEoGhEXqYEHGMEoGhEXuZD3CLEXmYEXqYEXqYDmV+EoGhEXmXD2uGEn+eEoKiEn2dEoGhEXeUEoGgEoGgEoCfEoGhEXybEHWREoCgEn+fEXuZEoCfEn+fEX2bEXybEn+eEoCfQDJxlAAAAIV0Uk5TADeutUwB2//pTPn0QZztOgWi9UYIq0IMofJAFablPxC45jIZvNU2FMDSLBHC3SIO0tgayeEXF88aIMTQHinIvyQl2cEHIdpZH+2gAXrDDXsBWsMHxyfoHt8i5Ckz2z3sOupISe9LBfhQBjlMMgHwQwWt/pf3NO/42exTGtvZOLK4UE7Lse2kyUQAAAFUSURBVHic3dVVUwNBDAfwQxeX4lrcrbiXFlrc3d0p7lKKfHAul6fezDH5vzHkcWd+s5vdbKJp/yhCQsPCIzASqVRUNEZilFKxcRCJ14lKSERIUjIZWwpiUtOMfdIRk5FJJisbMTm5ZPLyEWMvIFNYhJjiEjKlZYgpryBTWYWY6hoytXWIqW8g42hEjL2JTHMLYlrbjHzaEdPRSaarGzE9vWScfYhxucn0DyDG4yUziBBtaFgnI6OQGdPJ+AREJmHCB5sCBKc/DQi+5JlZueCnnJuXCy4Yt0suuCy9Hrng4l9YlAv+YkvLcsEfeWVVLrhdONbkgpvS+oZccOvb3JILbrDbO3LBbdy2Kxc8LPb25eLAGEmHR0GLxyenVnHm48F3fhEkLq+UZVzfGOP11pTH3b01UQ/ao1JPz6bDvrz+Qt40/3vgw2dO8DPwZRXffvk9/f34AYz7SMZiIB+zAAAAAElFTkSuQmCC">
</head>
<body>
  <div class="topnav">
   <img class="logo" alt="" src="data:image/png;base64,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" />
	<h1> NeXuS Wi-Fi picker</h1>
  </div>
  <div class="content">
    <div class="card-grid">
      <div class="card">
        <form action="picker" method="POST">
          <p> 
            <label for="ssid">Available</label>
            <select name="ssidL" id="ssidL" onChange="setSSID(this);">
                {{WIFI_NETWORKS}}
            </select>
            <label for="ssid">SSID</label>
            <input type="text" id ="ssid" name="ssid" required><br>
            <label for="pass">Password</label>
            <input type="text" id ="pass" name="pass" required><br>
            <label for="ip">IP Address</label>
            <input type="text" id ="ip" name="ip" value="192.168.1.127"><br>
            <label for="gateway">Gateway</label>
            <input type="text" id ="gateway" name="gateway" value="192.168.1.1"><br>
            <input type ="submit" value ="Submit" name="save">
          </p>
        </form>
      </div>
    </div>
  </div>
    <script>  
      function setSSID(sel) {
        var s = sel.options[sel.selectedIndex].value;
        document.getElementById("ssid").value = s;
        document.getElementById("pass").focus();
      }       
    </script>
</body>
</html>
)uniquetag" };

const char landing[] PROGMEM{ R"uniquetag(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
    <title>NexXuS WiFi Picker</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no"/>
    <link rel="stylesheet" type="text/css" href="style.css">
    <link rel="icon" href="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADIAAAAyCAMAAAAp4XiDAAAAAXNSR0IB2cksfwAAAAlwSFlzAAAOxAAADsQBlSsOGwAAAY9QTFRFAAAAEXqZEoCfEoCfEXybDVxyEn+fEoKiEoGgEXuZEoGhEoGhEXqZEn6cEoGhEXqYEHCLEn6dEoGhEXqXEHKPEn+eEXmWEHSQEn+eEoGhEXqYEXiWEn+eEoGhEXyaEHSQEn+eEoGgEXuZEHmWEn+fEoCgEXuZEXeTEoCfEoCfEXmXEHWSEn+fEoCgEXmXEHKOEn+fEoCgEXaTEoCfEoCgEHWREHiUEoCfEHeUEHiWEoCfEoCfEXiWEXqXEoCfEoCfEXqYEHmXEoCgEn+fD2yGEXmWEoCgEXybEHaTEoGgEn+eC01gEXyaEoCfEHKOEXybC01hEX2bEn+fD22HEoCfEXqXEoGgEXaTEoCgEHaTEoCgEXmXEXuZEoGgEXyaEoGgEXqZEoGhEXuZEXuZEoGhEXqYEHGMEoGhEXuZD3CLEXmYEXqYEXqYDmV+EoGhEXmXD2uGEn+eEoKiEn2dEoGhEXeUEoGgEoGgEoCfEoGhEXybEHWREoCgEn+fEXuZEoCfEn+fEX2bEXybEn+eEoCfQDJxlAAAAIV0Uk5TADeutUwB2//pTPn0QZztOgWi9UYIq0IMofJAFablPxC45jIZvNU2FMDSLBHC3SIO0tgayeEXF88aIMTQHinIvyQl2cEHIdpZH+2gAXrDDXsBWsMHxyfoHt8i5Ckz2z3sOupISe9LBfhQBjlMMgHwQwWt/pf3NO/42exTGtvZOLK4UE7Lse2kyUQAAAFUSURBVHic3dVVUwNBDAfwQxeX4lrcrbiXFlrc3d0p7lKKfHAul6fezDH5vzHkcWd+s5vdbKJp/yhCQsPCIzASqVRUNEZilFKxcRCJ14lKSERIUjIZWwpiUtOMfdIRk5FJJisbMTm5ZPLyEWMvIFNYhJjiEjKlZYgpryBTWYWY6hoytXWIqW8g42hEjL2JTHMLYlrbjHzaEdPRSaarGzE9vWScfYhxucn0DyDG4yUziBBtaFgnI6OQGdPJ+AREJmHCB5sCBKc/DQi+5JlZueCnnJuXCy4Yt0suuCy9Hrng4l9YlAv+YkvLcsEfeWVVLrhdONbkgpvS+oZccOvb3JILbrDbO3LBbdy2Kxc8LPb25eLAGEmHR0GLxyenVnHm48F3fhEkLq+UZVzfGOP11pTH3b01UQ/ao1JPz6bDvrz+Qt40/3vgw2dO8DPwZRXffvk9/f34AYz7SMZiIB+zAAAAAElFTkSuQmCC">
</head>
  <body>
    <div class="topnav">
		<img class="logo" alt="" src="data:image/png;base64,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" />
      <h1>NeXuS WiFi picker</h1>
    </div>
    <div class="content">
      <div class="card-grid">
        <div class="card">
          <p class="card-title"> Press button "Scan" to find all available nearby networks.</p>
		  <p class="txt">During the procces, LED on <span><b>Hera©</b></span> board will be <span><b>ON</b></span>...</p>
          <p class="cntr"><a href="scan"><button class="button-on" onclick="setMsg()">SCAN</button></a></p>
          <p class="msg">
			<img class="img-futer" alt="" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADIAAAAyCAMAAAAp4XiDAAAAAXNSR0IB2cksfwAAAAlwSFlzAAAOxAAADsQBlSsOGwAAAY9QTFRFAAAAEXqZEoCfEoCfEXybDVxyEn+fEoKiEoGgEXuZEoGhEoGhEXqZEn6cEoGhEXqYEHCLEn6dEoGhEXqXEHKPEn+eEXmWEHSQEn+eEoGhEXqYEXiWEn+eEoGhEXyaEHSQEn+eEoGgEXuZEHmWEn+fEoCgEXuZEXeTEoCfEoCfEXmXEHWSEn+fEoCgEXmXEHKOEn+fEoCgEXaTEoCfEoCgEHWREHiUEoCfEHeUEHiWEoCfEoCfEXiWEXqXEoCfEoCfEXqYEHmXEoCgEn+fD2yGEXmWEoCgEXybEHaTEoGgEn+eC01gEXyaEoCfEHKOEXybC01hEX2bEn+fD22HEoCfEXqXEoGgEXaTEoCgEHaTEoCgEXmXEXuZEoGgEXyaEoGgEXqZEoGhEXuZEXuZEoGhEXqYEHGMEoGhEXuZD3CLEXmYEXqYEXqYDmV+EoGhEXmXD2uGEn+eEoKiEn2dEoGhEXeUEoGgEoGgEoCfEoGhEXybEHWREoCgEn+fEXuZEoCfEn+fEX2bEXybEn+eEoCfQDJxlAAAAIV0Uk5TADeutUwB2//pTPn0QZztOgWi9UYIq0IMofJAFablPxC45jIZvNU2FMDSLBHC3SIO0tgayeEXF88aIMTQHinIvyQl2cEHIdpZH+2gAXrDDXsBWsMHxyfoHt8i5Ckz2z3sOupISe9LBfhQBjlMMgHwQwWt/pf3NO/42exTGtvZOLK4UE7Lse2kyUQAAAFUSURBVHic3dVVUwNBDAfwQxeX4lrcrbiXFlrc3d0p7lKKfHAul6fezDH5vzHkcWd+s5vdbKJp/yhCQsPCIzASqVRUNEZilFKxcRCJ14lKSERIUjIZWwpiUtOMfdIRk5FJJisbMTm5ZPLyEWMvIFNYhJjiEjKlZYgpryBTWYWY6hoytXWIqW8g42hEjL2JTHMLYlrbjHzaEdPRSaarGzE9vWScfYhxucn0DyDG4yUziBBtaFgnI6OQGdPJ+AREJmHCB5sCBKc/DQi+5JlZueCnnJuXCy4Yt0suuCy9Hrng4l9YlAv+YkvLcsEfeWVVLrhdONbkgpvS+oZccOvb3JILbrDbO3LBbdy2Kxc8LPb25eLAGEmHR0GLxyenVnHm48F3fhEkLq+UZVzfGOP11pTH3b01UQ/ao1JPz6bDvrz+Qt40/3vgw2dO8DPwZRXffvk9/f34AYz7SMZiIB+zAAAAAElFTkSuQmCC" />
			<span id="msg"> Please be patient, scanning procces can take time...</span>
		  </p>
        </div>
      </div>
    </div>
  </body>
  <script>
    function setMsg() {
      document.getElementById("msg").innerHTML = " Scanner started..."
    }
  </script>
</html>
)uniquetag" };

const char success[] PROGMEM{ R"uniquetag(
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="utf-8">
    <title>NexXuS WEB SERVER</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="style.css">
    <link rel="icon" href="data:,">
  </head>
  <body>
    <div class="topnav">
      <img class="logo" alt="" src="data:image/png;base64,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" />
	  
    <h1> NeXuS WiFi picker</h1>
    </div>
    <div class="content">
      <div class="card-grid">
        <div class="card">
			<p class="card-title">✔  Done!</p>
			<p class="txt"> Network credentials are stored.</br> NeXus®  <span><b>Hera©</b></span> will attempt to connect to<b>: {{SSIDPH}} </b>. If successful, Wi-Fi (SSID):"Nexus-WiFi" will disappear.
			</br>You can access to device by typing IP address:<b> {{IPPH}} </b>into the browser of your smart device or PC.</p>
			<p class="msg">💗<b> Enjoy</b>, as much as we did while creating <b>Hera©</b></p>
        </div>
      </div>
    </div>
    <script>
      const rtOut = setTimeout(run, 1000);

      function run() {
        clearTimeout(rtOut);
        let xhr = new XMLHttpRequest();

        let url = '/success';
        xhr.open("GET", url, true);

        xhr.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
          }
        }
        xhr.send();
      }	
	</script>
  </body>
</html>
)uniquetag" };

const char style[] PROGMEM{ R"uniquetag(
html {
  font-family: Helvetica, sans-serif; 
  display: inline-block; 
  text-align: center;
}

h1 {
	font-size: 1.8rem;
	color: white;
    display: inline-block;
}

p { 
  font-size: 1rem;
  text-align: left;
  padding: 20px;
}

.topnav { 
  overflow: hidden; 
  background-color: #2b3760;// #0A1128; //#442b60; //ljubicasa //
}

body {  
  margin: 0;
}

.content { 
  padding: 5%;
}

.img-futer{ 
  display: inline-block;
  height: 0.85rem;
  vertical-align: text-bottom;
}

.card-grid { 
  max-width: 800px; 
  margin: 0 auto; 
  display: grid; 
  grid-gap: 2rem; 
  grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
}

.card { 
  background-color: white; 
  box-shadow: 2px 2px 12px 1px rgba(140,140,140,.5);
  padding.20px;
}

.card-title { 
  font-size: 1.2rem;
  font-weight: bold;
  color: #034078;
}

input[type=submit] {
  border: none;
  color: #FEFCFB;
  background-color: #034078;
  padding: 15px 15px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  width: 100px;
  margin-right: 10px;
  border-radius: 4px;
  transition-duration: 0.4s;
  }

input[type=submit]:hover {
  background-color: #1282A2;
}

input[type=text], input[type=number], select {
  width: 50%;
  padding: 12px 20px;
  margin: 18px;
  display: inline-block;
  border: 1px solid #ccc;
  border-radius: 4px;
  box-sizing: border-box;
  font-size: 1rem;
}

label {
	font-size: 1rem;
	display: inline-block;
    width: 35%;
}
}
.value{
  font-size: 1.2rem;
  color: #1282A2;  
}
.state {
  font-size: 1.2rem;
  color: #1282A2;
}
.msg {
  font-size: 0.85rem;
  line-height: 1.6;
  color: #1282A2;
}
.txt {
  font-size: 0.85rem;
}
.cntr {
  text-align:center;
}
.logo{
	display: inline-block;
    height: 1.8rem;
    margin-right: 5px;
	vertical-align: text-bottom;
}
span{
	color: #1282A2;
}
button {
  border: none;
  color: #FEFCFB;
  padding: 15px 32px;
  text-align: center;
  font-size: 16px;
  width: 100px;
  border-radius: 4px;
  transition-duration: 0.4s;
}
.button-on {
  background-color: #034078;
}
.button-on:hover {
  background-color: #1282A2;
}
.button-off {
  background-color: #858585;
}
.button-off:hover {
  background-color: #252524;
} 
)uniquetag" };

#include <SPIFFS.h>


using namespace std;

#define FORMAT_SPIFFS_IF_FAILED true

void deleteFile(fs::FS &fs, const char * path){
    Serial.printf("Deleting file: %s\r\n", path);
    if(fs.remove(path)){
        Serial.println("- file deleted");
    } else {
        Serial.println("- delete failed");
    }
}

void saveFwToSPIFFS(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\r\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("- failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("- file written");
    } else {
        Serial.println("- write failed");
    }
    file.close();
}

void readFwFromSPIFFS(const char * path) {
  File file = SPIFFS.open(path, "r");
  if (!file) {
    Serial.println("Failed to open file for reading");
  }
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}


void setup() {
  Serial.begin(115200);
  if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  } else {
    Serial.println("Ukacio SPIFFS");
    //deleteFile(SPIFFS, "/index.html");
  }

  saveFwToSPIFFS(SPIFFS, "/style.css", style);
  readFwFromSPIFFS("/style.css");
  saveFwToSPIFFS(SPIFFS, "/index.html", indexHTML);
  readFwFromSPIFFS("/index.html");
  saveFwToSPIFFS(SPIFFS, "/wifimanager.html", wifimanager);
  readFwFromSPIFFS("/wifimanager.html");
  saveFwToSPIFFS(SPIFFS, "/landing.html", landing);
  readFwFromSPIFFS("/landing.html");
  saveFwToSPIFFS(SPIFFS, "/success.html", success);
  readFwFromSPIFFS("/success.html");

  // if (SPIFFS.exists("/index.html")) {
  //   Serial.println("Version file: OK");
  //   readFwFromSPIFFS();
  // } else {
  //   saveFwToSPIFFS(SPIFFS, "/index.html", indexHTML);
  //   Serial.println("Fle kreiran....");
  // }
}

void loop() {
  // put your main code here, to run repeatedly:
}
