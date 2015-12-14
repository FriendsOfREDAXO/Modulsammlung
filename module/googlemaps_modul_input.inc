<?php
$editor                 = 0;

if(!rex_addon::get('rex_redactor')->isAvailable() AND !rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "Redactor" oder das "MarkItUp" Addon!');
}
if(rex_addon::get('rex_redactor')->isAvailable()) {
  $editor = 'redactor';
    rex_redactor::insertProfile('simple', 'Grid Modul Builder Profil', 'bold,italic,underline,deleted,unorderedlist', 'rex_linkmap,rex_mediapool_link');
}
if(rex_addon::get('rex_markitup')->isAvailable()) {
  $editor = 'markitup';
  rex_markitup::insertProfile('simple', 'Grid Modul Builder Profil', 'textile', 'bold,italic,underline,deleted,quote,sub,sup,code,unorderedlist,link[internal|external|mailto],image');
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
        <label class="col-sm-3 control-label">Adresse</label>
        <div class="col-sm-9">
          <input id="address"  placeholder="" class="form-control" name="REX_INPUT_VALUE[1]" value="REX_VALUE[1]" type="text" />
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

      <div class="form-group">
        <label class="col-sm-3 control-label">Infotext</label>
        <div class="col-sm-9">
          <textarea id="infotext" class="form-control" name="REX_INPUT_VALUE[4]">REX_VALUE[4]</textarea>
        </div>
      </div>

      <h3>Karte</h3>

      <div class="form-group">
        <label class="col-sm-3 control-label">Karte</label>
        <div class="col-sm-9">
          <div id="map_canvas"></div>
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Darstellung</label>
        <div class="col-sm-9 ">
          <div class="select-style">
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
       <label class="col-sm-3 control-label">Zoom</label>
         <div class="col-sm-9 ">
           <div class="select-style">
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
          <div class="select-style">
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

    <h3>Routenplaner</h3>

      <div class="form-group">
        <label class="col-sm-3 control-label">Routenplaner anzeigen</label>
        <div class="col-sm-9">
          <div class="select-style">
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
        <label class="col-sm-3 control-label">Senden Button</label>
        <div class="col-sm-9">
          <input  id="latitude" class="form-control" name="REX_INPUT_VALUE[9]" value="REX_VALUE[9]" type="text" />
        </div>
      </div>

      <div class="form-group">
        <label class="col-sm-3 control-label">Erklärungstext</label>
        <div class="col-sm-9">
          <textarea id="erklaerungstext" class="form-control <?php echo $editor.' '.$editor; ?>Editor-simple" name="REX_INPUT_VALUE[10]">REX_VALUE[10]</textarea>
        </div>
      </div>

<div id="anleitung" class="tab-pane fade in active">
  <div class="form-horizontal">
  <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-allgemeines"><span class="caret"></span>Anleitung</h3></div>
  <div id="collapse-allgemeines" class="panel-collapse collapse">
        <div class="form-group">
          <label class="col-sm-3 control-label">Adresse</label>
            <div class="col-sm-9">
              <p>Lorem</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Karte</label>
            <div class="col-sm-9">
              <p>Lorem</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Routenplaner</label>
            <div class="col-sm-9">
              <p>Lorem</p>
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

.select-style {
  border: 1px solid #cccccc;
  width: 100%;
  overflow: hidden;
  background: #fff url("data:image/png;base64,R0lGODlhDwAUAIABAAAAAP///yH5BAEAAAEALAAAAAAPABQAAAIXjI+py+0Po5wH2HsXzmw//lHiSJZmUAAAOw==") no-repeat 98% 50%;
  margin-bottom: 6px;
}

.select-style select {
  padding: 5px 8px;
  width: 100%;
  border: none;
  box-shadow: none;
  background: transparent;
  background-image: none;
  -webkit-appearance: none;
  -moz-appearance:none;
  -webkit-border-radius: 0px;
}

.select-style select:focus {
  outline: none;
}

.select-style select:hover {
  cursor: pointer;
}

input.form-control,
select.form-control,
textarea.form-control {
  background: #fff !important;
}

#infotext {
    resize: none;
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
  text-align: right;
  margin-bottom: 20px;
  border: none;
}

#anleitung .panel-heading span {
  margin-right: 5px;
}

#anleitung .panel-heading:hover  {
  color: #000;
}

#map_canvas {
  width: 100%;
  height: 300px;
  margin: 0;
  border: 1px solid #afbcc2;
}

</style>

<script>
if(typeof google === "undefined") {
    document.write(unescape("%3Cscript src='http://maps.google.com/maps/api/js?libraries=places&amp;region=DE&amp;callback=initGoogleModul' type='text/javascript'%3E%3C/script%3E"));
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

  var latlng = new google.maps.LatLng(startlat, startlng);

  var options = {
    scrollwheel: false,
    mapTypeControl: false,
    streetViewControl : false,
    zoom: zoomer,
    center: latlng,
    mapTypeId: google.maps.MapTypeId.ROADMAP
  };

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

}


function initGoogleModul() {
  initialize();

 var input = /** @type {!HTMLInputElement} */(

    document.getElementById('address'));

    var autocomplete = new google.maps.places.Autocomplete(input);
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

  //Add listener to marker for reverse geocoding
  google.maps.event.addListener(marker,'dragend',function(event)  {
    geocoder.geocode({'latLng': marker.getPosition()}, function(results, status) {
      if (status == google.maps.GeocoderStatus.OK) {
        if (results[0]) {
          // $('#address').val(results[0].formatted_address);
          $('#latitude').val(marker.getPosition().lat());
          $('#longitude').val(marker.getPosition().lng());
        }
      }
    });
  });

  // Set Infowindow
  var infoWindow = new google.maps.InfoWindow();
  if (infotext !='' ) {
    infoWindow.setContent(infotext);
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


};

</script>



