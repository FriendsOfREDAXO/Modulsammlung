<?php

/*
Benötige CSS Angaben:

#map_canvas {
  width: 100%;
  height: 150px;
}

*/

if(!rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
}

$adresse              = 'REX_VALUE[1]';
$lat                  = 'REX_VALUE[2]';
$lng                  = 'REX_VALUE[3]';

$darstellung          = 'REX_VALUE[5]';
$sprache              = 'REX_VALUE[11]';
$zoom                 = 'REX_VALUE[6]';
$markerfarbe          = 'REX_VALUE[7]';
$infotext             = 'REX_VALUE[4]';

$routenplaner_anzeige = 'REX_VALUE[8]';
$sendenbutton         = 'REX_VALUE[9]';
$erklaerungstext      = '';

$breite               = 'REX_VALUE[12]';
$container            = '';

if ($breite == '100% Browserbreite') {
  $container = 'container-fluid';
} else {
  $container = 'container';
}

if ('REX_VALUE[id=10 isset=1]') {
    $textile = 'REX_VALUE[id=10 output=html]';
    $erklaerungstext = rex_textile::parse($textile);
}


if ($sprache == '') {
  $sprache = 'de';
}

if ($sendenbutton == '') {
  $sendenbutton = 'Bitte eine Bezeichnung (z.B: Route anzeigen) eingeben. ';
}

if(!rex::isBackend()) {

  if (!isset($REX['GoogleMap']['MapCounter'])) $REX['GoogleMap']['MapCounter'] = 0;
  $REX['GoogleMap']['MapCounter']++;
  $mapidx = $REX['GoogleMap']['MapCounter'];

  if ($mapidx==1) $mapidx = '';

  if ($mapidx==''){
    echo '<script type="text/javascript" src="http://maps.googleapis.com/maps/api/js?sensor=false&amp;language='.$sprache.'&amp;region='.strtoupper($sprache).'"></script>';
  }

  echo '<script type="text/javascript">';
  if ($routenplaner_anzeige == 'ja'){
    echo "
    var directionDisplay".$mapidx.";
    var directionsService".$mapidx." = new google.maps.DirectionsService();
    function calcRoute".$mapidx."(mapidx, zieladresse, lat, lng) {
      var mylatlng = new google.maps.LatLng(lat,lng);
      var start = document.getElementById('start'+mapidx).value;
      var end = mylatlng;
      var request = {
        origin: start,
        destination: end,
        travelMode: google.maps.DirectionsTravelMode.DRIVING
      };
      directionsService".$mapidx.".route(request, function(response, status){
        if (status == google.maps.DirectionsStatus.OK) {
          $('#directions-panel".$mapidx."').html('');
          directionsDisplay".$mapidx.".setDirections(response);
        } else if (status == google.maps.DirectionsStatus.NOT_FOUND) {
          $('#directions-panel".$mapidx."').html('<p>Adresse nicht gefunden!</p>');
        }
      });
    }
    ";
  }

echo "
    function initializemap".$mapidx."(){

      var myLatlng = new google.maps.LatLng(".$lat.",".$lng.");

      var myOptions = {
        zoom:".$zoom.",
        mapTypeId: '".$darstellung."',
        scrollwheel: false,
        center: myLatlng
      };
      var map".$mapidx." = new google.maps.Map(document.getElementById('map_canvas".$mapidx."'), myOptions);

      var marker = new google.maps.Marker({
        position: myLatlng,
        title: '".$adresse."',
        icon: 'https://maps.gstatic.com/mapfiles/ms2/micons/".$markerfarbe."-dot.png',
        map: map".$mapidx."
      });
";

 if ($routenplaner_anzeige == 'ja'){
 echo "
      directionsDisplay".$mapidx." = new google.maps.DirectionsRenderer();
      directionsDisplay".$mapidx.".setMap(map".$mapidx.");
      directionsDisplay".$mapidx.".setPanel(document.getElementById('directions-panel".$mapidx."'));
      ";
}

if ($infotext != ''){
echo "
      var contentString = '".$infotext."';
      var infowindow = new google.maps.InfoWindow({
        content: contentString
      });
      infowindow.open(map".$mapidx.", marker);
      google.maps.event.addListener(marker, 'click', function() {
        infowindow.open(map".$mapidx.", marker);
      });
";
}

echo "

 };
    google.maps.event.addDomListener(window, 'load', initializemap".$mapidx.");
  </script>";


echo "

  <!-- Google Maps (+ Routenplaner) ".$mapidx." -->
    <div class='".$container."'>
      <di class='row'>
        <div id='googelmapsroutenplaner".$mapidx."' class='googelmapsroutenplaner'>
        <div class='row'>
        <div id='map_canvas".$mapidx."' class='map_canvas'></div>
        </div>
      </div>
    </div>
  ";

  if ($routenplaner_anzeige == 'ja'){

  echo '
  <div class="container">
  <div class="row">';
    $formularausgabe = "
        <form id='routenplaner".$mapidx."' class='routenplaner' action='javascript:void(0);' onsubmit=\"return calcRoute".$mapidx."('".$mapidx."', '".$adresse."', '".$lat."', '".$lng."')\">
          <fieldset>
            <input type='text' id='start".$mapidx."' value='' />
            <input name='submit' type='submit' class='submit' value='".$sendenbutton."' />
          </fieldset>
        </form>
    ";

    if ($erklaerungstext != ''){
      echo '<div class="col-xs-6">'.$erklaerungstext.'</div>';
      echo '<div class="col-xs-6">'.$formularausgabe.'</div>';
    } else {
      echo '<div class="col-xs-12">'.$formularausgabe.'</div>';
    }
    echo "
    </div>
    </div>
    <div class='container'>
        <!-- Ausgabe der Wegbeschreibung -->
          <div id='directions-panel".$mapidx."' class='directions-panel'></div>
    </div>
    <!-- /Google Maps Routenplaner ".$mapidx." -->";
  }
} else {

 echo '
  <div id="trennlinie" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Adresse</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Adresse</label>
         <div class="col-sm-9">'.$adresse.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Lat</label>
         <div class="col-sm-9">'.$lat.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Lng</label>
         <div class="col-sm-9">'.$lng.'</div>
       </div>

 <h2>Karte / Marker</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Darstellung</label>
         <div class="col-sm-9">'.$darstellung.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Breite der Karte</label>
         <div class="col-sm-9">'.$breite.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Sprache</label>
         <div class="col-sm-9">'.$sprache.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Zoom</label>
         <div class="col-sm-9">'.$zoom.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Markerfarbe</label>
         <div class="col-sm-9">'.$markerfarbe.'</div>
       </div>';

if ($infotext != '') {
echo ' <div class="form-group">
         <label class="col-sm-3 control-label">Infotext</label>
         <div class="col-sm-9">'.html_entity_decode($infotext).'</div>
       </div>';
}

if ($routenplaner_anzeige == 'ja') {

echo'  <h2>Routenplaner</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Routenplaner anzeigen</label>
         <div class="col-sm-9">'.$routenplaner_anzeige.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Senden Button Text</label>
         <div class="col-sm-9">'.$sendenbutton.'</div>
       </div>';

  if ($erklaerungstext != '') {
  echo'  <div class="form-group">
           <label class="col-sm-3 control-label">erklaerungstext</label>
           <div class="col-sm-9">'.$erklaerungstext.'</div>
         </div>';
  }
}
echo'
    </div>
  </div>


<style>
#trennlinie.bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#trennlinie .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#trennlinie  h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

</style>

  '.PHP_EOL;
}

?>
