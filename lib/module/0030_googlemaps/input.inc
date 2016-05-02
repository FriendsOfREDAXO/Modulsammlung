<?php
if(!rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
} else {
  if (!rex_markitup::profileExists('supersimple')) {
  rex_markitup::insertProfile('supersimple', 'Angelegt durch das Addon Modulsammlung', 'textile', 'bold,italic,underline');
  }
  if (!rex_addon::get('textile')->isAvailable()) {
      echo rex_view::error('Dieses Modul benötigt das "textile" Addon!');
  }
}

?>

<div class="modul-content">
  <div id="bereich1" class="">
    <div class="form-horizontal">
      <h3>Adresse</h3>
      <div class="form-group">
        <label class="col-sm-3 control-label">Adresse / Infotext</label>
        <div class="col-sm-9">
          <input id="address" class="form-control" name="REX_INPUT_VALUE[1]" value="REX_VALUE[1]" type="text" />
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Latitude</label>
        <div class="col-sm-9">
          <input  id="latitude" class="form-control" name="REX_INPUT_VALUE[2]" value="REX_VALUE[2]" type="text" />
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Longitude</label>
        <div class="col-sm-9">
          <input id="longitude" class="form-control" name="REX_INPUT_VALUE[3]" value="REX_VALUE[3]" type="text" />
        </div>
      </div>

      <h3>Karte / Marker</h3>

      <div class="form-group">
        <label class="col-sm-3 control-label">Karte</label>
        <div class="col-sm-9">
          <div id="map_canvas"></div>
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Darstellung</label>
        <div class="col-sm-9 ">
          <div class="rex-select-style">
            <select id="maptype" name="REX_INPUT_VALUE[5]">
            <?php
              foreach (array('roadmap', 'satellite', 'hybrid', 'terrain') as $value) {
                echo '<option value="'.$value.'" ';

                if ( "REX_VALUE[5]"=="$value" ) {
                  echo 'selected="selected" ';
                }
                echo '>'.$value.'</option>';
                }
            ?>
            </select>
          </div>
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Breite der Karte</label>
        <div class="col-sm-9 ">
          <div class="rex-select-style">
            <select id="maptype" name="REX_INPUT_VALUE[12]">
            <?php
              foreach (array('100% Browserbreite', 'So breit wie der Inhalt') as $value) {
                echo '<option value="'.$value.'" ';

                if ( "REX_VALUE[12]"=="$value" ) {
                  echo 'selected="selected" ';
                }
                echo '>'.$value.'</option>';
                }
            ?>
            </select>
          </div>
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Ausgabesprache</label>
        <div class="col-sm-9 ">
          <input id="longitude" class="form-control" name="REX_INPUT_VALUE[11]" placeholder="de" value="REX_VALUE[11]" type="text" />
        </div>
      </div>

      <div class="form-group">
       <label class="col-sm-3 control-label">Zoom</label>
         <div class="col-sm-9 ">
           <div class="rex-select-style">
            <select id="zoom" name="REX_INPUT_VALUE[6]">
            <?php
              foreach (array('4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20') as $value) {
                echo '<option value="'.$value.'" ';
                if ( 'REX_VALUE[6]'==$value) {
                  echo 'selected="selected" ';
                }
                echo '>'.$value.'</option>';
                }
            ?>
            </select>
          </div>
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Markerfarbe</label>
        <div class="col-sm-9">
          <div class="rex-select-style">
            <select id="marker" name="REX_INPUT_VALUE[7]">
            <?php
              foreach (array('red','green','blue','yellow','purple','pink') as $value) {
                echo '<option value="'.$value.'" ';
                if ( 'REX_VALUE[7]'==$value) {
                  echo 'selected="selected" ';
                }
                echo '>'.$value.'</option>';
                }
            ?>
            </select>
          </div>
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Infotext</label>
        <div class="col-sm-9">
          <textarea id="infotext" class="form-control" name="REX_INPUT_VALUE[4]">REX_VALUE[4]</textarea>
        </div>
      </div>


    <h3>Routenplaner</h3>

      <div class="form-group">
        <label class="col-sm-3 control-label">Routenplaner anzeigen</label>
        <div class="col-sm-9">
          <div class="rex-select-style">
            <select id="marker" name="REX_INPUT_VALUE[8]">
            <?php
              foreach (array('nein','ja') as $value) {
                echo '<option value="'.$value.'" ';
                if ( 'REX_VALUE[8]'==$value) {
                  echo 'selected="selected" ';
                }
                echo '>'.$value.'</option>';
                }
            ?>
            </select>
          </div>
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Senden Button Text</label>
        <div class="col-sm-9">
          <input  id="latitude" class="form-control" placeholder="Route anzeigen" name="REX_INPUT_VALUE[9]" value="REX_VALUE[9]" type="text" />
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Erklärungstext</label>
        <div class="col-sm-9">
           <textarea id="erklaerungstext markitup_textile_1" class="form-control markitup markitupEditor-supersimple" name="REX_INPUT_VALUE[10]">REX_VALUE[10]</textarea>
        </div>
      </div>

<div id="anleitung" class="tab-pane fade in active">
  <div class="form-horizontal">
  <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-allgemeines"><span class="caret"></span>Anleitung</h3></div>
  <div id="collapse-allgemeines" class="panel-collapse collapse">
        <div class="form-group">
          <label class="col-sm-3 control-label">Adresse</label>
            <div class="col-sm-9">
              <p>Hier wird die Adresse eingetragen an der der Marker positioniert werden soll.</p>
              <p>Es kann eine beleibige Adresse in Form von <i>Strasse Nr, PLZ Ort</i> angegeben werden. bei der Eingabe schlägt Gogole bereits gefundene Addressen vor die einfach ausgewählt werden können.</p><p>Auch die Angabe von z.B. 'Düsseldorf Flughafen' oder "Zoo Duisburg' funktionieren.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Latitude / Longitude</label>
            <div class="col-sm-9">
              <p>Diese Felder werden durch Angabe der Adresse bzw. durch verschieben des Markers auf der Karte automatisch ausgefüllt.</p>
            </div>
        </div>

        <div class="form-group">
          <label class="col-sm-3 control-label">Karte</label>
            <div class="col-sm-9">
              <p>Der Marker auf der Karte ist mit der Maus verschiebbar. Somit ändern sich die Koordinaten in den Feldern Latitude / Longitude sowie die Adresse.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Darstellung</label>
            <div class="col-sm-9">
              <p>Ändert die Darstellungsart der Karte.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Breite der Karte</label>
            <div class="col-sm-9">
              <p>Ändert die Breite der Karte.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Ausgabesprache</label>
            <div class="col-sm-9">
              <p>Die Wahl der Sprache trifft für alle auf einer Seite benutzten Karten zu. Es gilt die Einstellung der zuerst verwendeten Karte.</p>
              <p>Mögliche Sprachen:</p>
              <div class="col-xs-12 col-sm-6">
              <ul>
              <li><b>ar</b> - Arabic</li>
              <li><b>bg</b> - Bulgarian</li>
              <li><b>bn</b> - Bengali</li>
              <li><b>ca</b> - Catalan</li>
              <li><b>cs</b> - Czech</li>
              <li><b>da</b> - Danish</li>
              <li><b>de</b> - German</li>
              <li><b>el</b> - Greek</li>
              <li><b>en</b> - English</li>
              <li><b>es</b> - Spanish</li>
              <li><b>eu</b> - Basque</li>
              <li><b>fa</b> - Farsi</li>
              <li><b>fi</b> - Finnish</li>
              <li><b>fil</b> - Filipino</li>
              <li><b>fr</b> - French</li>
              <li><b>gl</b> - Galician</li>
              <li><b>gu</b> - Gujarati</li>
              <li><b>hi</b> - Hindi</li>
              <li><b>hr</b> - Croatian</li>
              <li><b>hu</b> - Hungarian</li>
              <li><b>id</b> - Indonesian</li>
              <li><b>it</b> - Italian</li>
              <li><b>iw</b> - Hebrew</li>
              <li><b>ja</b> - Japanese</li>
              </ul>
              </div>
              <div class="col-xs-12 col-sm-6">
              <ul>
              <li><b>kn</b> - Kannada</li>
              <li><b>ko</b> - Korean</li>
              <li><b>lt</b> - Lithuanian</li>
              <li><b>lv</b> - Latvian</li>
              <li><b>ml</b> - Malayalam</li>
              <li><b>mr</b> - Marathi</li>
              <li><b>nl</b> - Dutch</li>
              <li><b>no</b> - Norwegian</li>
              <li><b>pl</b> - Polish</li>
              <li><b>pt</b> - Portuguese</li>
              <li><b>ro</b> - Romanian</li>
              <li><b>ru</b> - Russian</li>
              <li><b>sk</b> - Slovak</li>
              <li><b>sl</b> - Slovenian</li>
              <li><b>sr</b> - Serbian</li>
              <li><b>sv</b> - Swedish</li>
              <li><b>ta</b> - Tamil</li>
              <li><b>te</b> - Telugu</li>
              <li><b>th</b> - Thai</li>
              <li><b>tl</b> - Tagalog</li>
              <li><b>tr</b> - Turkish</li>
              <li><b>uk</b> - Ukrainian</li>
              <li><b>vi</b> - Vietnamese</li>
              <li><b>zh-CN </b> - Chinese</li>
              </div>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Zoom</label>
            <div class="col-sm-9">
              <p>Ändert den Zoomfaktor.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Markerfarbe</label>
            <div class="col-sm-9">
              <p>Ändert die Farbe des Markers.</p>
            </div>
        </div>

        <div class="form-group">
          <label class="col-sm-3 control-label">Infotext</label>
            <div class="col-sm-9">
              <p>Dieser Text erscheint als Hinweistext über dem Marker auf der Karte. In diesem Feld ist die (eingeschränkte) Verwendung von HTML Befehlen möglich.</p><p>Durch die Eingabe von <i>&lt;br/&gt;</i> wird ein Zeilenumbruch dargestellt.
            </div>
        </div>

        <div class="form-group">
          <label class="col-sm-3 control-label">Routenplaner anzeigen</label>
            <div class="col-sm-9">
              <p>Blendet den Routenplaner ein oder aus.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Senden Button Text</label>
            <div class="col-sm-9">
              <p>Bezeichnung des Sendenbuttons.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Erklärungstext</label>
            <div class="col-sm-9">
              <p>Dieser Text erscheint neben dem Sendebutton (sofern der Routenplaner angezeigt wird).</p>
            </div>
        </div>

  </div>


  </div>
</div>

<style>
.controls {
  margin-top: 10px;
  border: 1px solid transparent;
  border-radius: 2px 0 0 2px;
  box-sizing: border-box;
  -moz-box-sizing: border-box;
  height: 32px;
  outline: none;
  box-shadow: 0 2px 6px rgba(0, 0, 0, 0.3);
}

.modul-content {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

.modul-content h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

.modul-content .control-label {
  font-weight: normal;
  font-size: 12px !important;
}

input.form-control,
select.form-control,
textarea.form-control {
  background: #fff !important;
}

#infotext {
    resize: none;
}

input[placeholder] {

}

.redactor-editor,
.markitup {
  min-height: 200px;
}
.redactor-box {
  border: 1px solid #ccc;
}



#anleitung .control-label {
  margin-top: -6px;
}

#anleitung {
  margin-top: 30px;
}

#anleitung .panel-heading {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  text-align: left;
  margin-bottom: 20px;
  border: none;
}

#anleitung .panel-heading span {
  margin-right: 5px;
}

#anleitung .panel-heading:hover  {
  color: #000;
}

#anleitung ul {
  list-style: none;
  margin: 5px 0 5px -15px;
}

#anleitung ul li {
  list-style: none;
  margin: 5px 0 5px -35px;
  border-bottom: 1px solid #DFE3E9;
}

#map_canvas {
  width: 100%;
  height: 300px;
  margin: 0;
  border: 1px solid #afbcc2;
}

</style>

<script>
function loadScript(src){
  var script = document.createElement("script");
  script.type = "text/javascript";
  document.getElementsByTagName("head")[0].appendChild(script);
  script.src = src;
}
if(typeof google === "undefined") {
  loadScript('http://maps.googleapis.com/maps/api/js?v=3&sensor=false&libraries=places&callback=initialize');
}

// vars
var geocoder;
var map;
var marker;
var infotext = 'REX_VALUE[4]';
var startlat  = 'REX_VALUE[2]';
var startlng  = 'REX_VALUE[3]';

var zoomer    = 'REX_VALUE[6]';
if (zoomer == '') {
  zoomer = 10;
  $('#zoom').val('10');
}
zoomer = parseInt(zoomer);

if (startlat == '') startlat = '51.35969024552221';
if (startlng == '') startlng = '7.130266910381351';
startlat = parseFloat(startlat);
startlng = parseFloat(startlng);

function initialize(){

  var latlng = new google.maps.LatLng(startlat, startlng),
      options = {
        scrollwheel: false,
        mapTypeControl: false,
        streetViewControl : false,
        zoom: zoomer,
        center: latlng,
        mapTypeId: google.maps.MapTypeId.ROADMAP
      },
      MapElement = document.getElementById("map_canvas");

  if(MapElement === null)
    return;

  map = new google.maps.Map(document.getElementById("map_canvas"), options);

  marker = new google.maps.Marker({
    map: map,
    draggable: true
  });

  geocoder = new google.maps.Geocoder();

  // Marker
  var location = new google.maps.LatLng(startlat, startlng);
  marker.setPosition(location);
  marker.setIcon('https://maps.gstatic.com/mapfiles/ms2/micons/' + $('#marker').val() + '-dot.png');

  // Set Maptype
  map.setMapTypeId($('#maptype').val());

  // Set Zoom
  zoomer = $('#zoom').val();
  zoomer = parseInt(zoomer);
  if (isNaN(zoomer)) {
    zoomer = 10;
  }
  map.setZoom(zoomer);

  //Add listener to marker for reverse geocoding
  google.maps.event.addListener(marker,'dragend',function(event)  {
    geocoder.geocode({'latLng': marker.getPosition()}, function(results, status) {
      if (status == google.maps.GeocoderStatus.OK) {
        if (results[0]) {
          $('#address').val(results[0].formatted_address);
          $('#latitude').val(marker.getPosition().lat());
          $('#longitude').val(marker.getPosition().lng());
        }
      }
    });
  });

  // Set Infowindow
  var infoWindow = new google.maps.InfoWindow();
  if (infotext !='' ) {
    infoWindow.setContent($('#infotext').val());
    infoWindow.open(map, marker);
  }

  $( "#infotext" ).change(function() {
    if ($('#infotext').val() =='' ) {
      infoWindow.close();
    } else {
      infoWindow.setContent($('#infotext').val());
      infoWindow.open(map, marker);
    }
  });

 // Map-Darstellung über Selectbox ändern
  $('#maptype').bind('change keypress', function(){
    map.setMapTypeId($('#maptype').val());
    map.setCenter(marker.getPosition());
  });

  // Map-Zoom geändert - Input ändern
  google.maps.event.addListener(map, 'zoom_changed', function(){
    $('#zoom').val(map.getZoom());
    if (map.getZoom() < 4) map.setZoom(4);
    if (map.getZoom() > 20) map.setZoom(20);
    map.setCenter(marker.getPosition());
  });

 // Map-Zoom über Eingabefeld ändern
 $('#zoom').change(function() {
   zoomer = $('#zoom').val();
   zoomer = parseInt(zoomer);
   map.setZoom(zoomer);
 });

  // Marker über Selectbox ändern
  $('#marker').bind('change keypress', function(){
    marker.setIcon('https://maps.gstatic.com/mapfiles/ms2/micons/' + $('#marker').val() + '-dot.png');
  });

  var input = document.getElementById('address'),
      autocomplete = new google.maps.places.Autocomplete(input);

  autocomplete.bindTo('map_canvas', map);

  autocomplete.addListener('place_changed', function () {
    var place = autocomplete.getPlace();
    if (place.geometry) {
      neulat = parseFloat(place.geometry.location.lat());
      neulng = parseFloat( place.geometry.location.lng());

      var location = new google.maps.LatLng(neulat,neulng);
      marker.setPosition(location);
      map.setCenter(location);

      $('#latitude').val(neulat);
      $('#longitude').val(neulng);

    } else {
      alert('Keinen darstellbaren Ort gefunden');
    }

  });

}

$(document).on('ready pjax:success',function(){
  if(typeof google !== "undefined")
    initialize();
});
</script>
