<?php /*
  D . Google Map 2 - Output
 * 
 * Hinweis
 * =======
 * 
 * Der Code kann beliebig geändert werden.
 * 
 * Alles was zwischen if ($infowindow) { ... } steht wird nur für die Darstellung als Infowindow gebraucht
 * Alles was zwischen if (!$infowindow) { ... } steht wird nur für die Darstellung als Overlay gebraucht
 * 
 * Die Styles und den JS Code auch gerne aus der Ausgabe entfernen und an geeigneter Stelle einbauen.
 * 
 * Fragen?
 * Wolfgang Bund
 * post@agile-websites.de
 * http://agile-websites.de
 *   
 */

$infowindow = "REX_VALUE[2]" == 'infowindow';
$iw_text = preg_replace("/\R/",'',"REX_VALUE[id=3 output=html]");
preg_match_all('/###(.*?)###/',$iw_text,$matches);
$fields = implode(',',$matches[1]);
$params = json_decode("REX_VALUE[id=4 output=html]", true);
$location_data = rex_sql::factory()->getArray('SELECT '.$fields.','.$params['field'].' gk FROM '.$params['table'].' WHERE CHAR_LENGTH('.$params['field'].') > 2');

if ($params['key'] == '') {
    echo '<p><strong>Hinweis! </strong>Im Datenfeld für die Geoposition ist kein Api key für Google Maps hinterlegt. Der Key kann <a href="https://developers.google.com/maps/documentation/javascript/get-api-key?hl=de" target="_blank">hier</a> generiert werden.</p>';
}
?>

<style>
    #map {
        width: 100%;
        height: 50vh;
    }
    #map p {
        line-height: 1.2;
        margin: 0;
    }
    #map p + p {
        margin-top: 6px;
    }
    
    <?php if (!$infowindow) : ?>
    #map_container {
        position: relative;
    }
    #map_overlays {
        list-style: none;
        margin: 0;
        padding: 0;
        position: absolute;
        width: 100%;
        z-index: 500;
    }
    #map_overlays li {
        box-sizing: border-box;
        display: none;
        left: 0;
        padding: 1.6rem;        
        position: absolute;
        top: 0;
        width: 100%;
    }
    #map_overlays li.active {
        display: block;
    }
    
    #map_overlays li .map_card {
        width: 100%;
        max-width: 480px;
        box-sizing: border-box;
        padding: 1.2rem;
        margin: 0 auto;
        text-align: center;
        background-color: rgba(255, 255, 255, 0.8);
        transition: background-color 0.3s, box-shadow 0.3s;
    }
    <?php endif ?>
</style>


<div id="map_container">
    <?php if (!$infowindow) : // für Overlay ?>
    <ul id="map_overlays">
        <?php foreach ($location_data as $location) : ?>
            <li data-geocode="<?= $location['gk'] ?>" class="aw_mapmarker">
                <div class="map_card">
                    <?= str_replace($matches[0],$location,$iw_text) ?>
                </div>
            </li>
        <?php endforeach ?>
    </ul>
    <?php endif // Ende für Overlay ?>
    <div id="map"></div>
</div>    

<script type="text/javascript">

    var maplocations = [], i;
    
    
    <?php if ($infowindow) : // für Infowindow ?>
    maplocations = [
      <?php  foreach ($location_data as $location) : ?>
            [<?= $location['gk'] ?>,'<?= str_replace("'","\'",str_replace($matches[0],$location,$iw_text)) ?>'],
      <?php endforeach ?>
    ];
    console.log(maplocations);
    <?php endif // Ende für Infowindow ?>
    
    
    <?php if (!$infowindow) : // für Overlay ?>
    aw_mapmarker = document.getElementsByClassName('aw_mapmarker');
    for (i = 0; i < aw_mapmarker.length; i++) {
        maplocations[i] = aw_mapmarker[i].dataset.geocode.split(',');
        aw_mapmarker[i].addEventListener("click",function(e) {
            for (i = 0; i < aw_mapmarker.length; i++) {
                aw_mapmarker[i].className = aw_mapmarker[i].className.replace('active','');
            }            
        });
    }
    <?php endif // end für Overlay ?>

    function initMap() {


        var bounds = new google.maps.LatLngBounds();

        var map = new google.maps.Map(document.getElementById('map'), {
            zoom: 9,
            center: new google.maps.LatLng(53.7687724, 12.833583),
            mapTypeId: google.maps.MapTypeId.ROADMAP
        });
        
        var infowindow = new google.maps.InfoWindow(); // nur bei Darstellung als Infowindow notwendig

        var markers = [], marker, i;

        for (i = 0; i < maplocations.length; i++) {
            marker = new google.maps.Marker({
                position: new google.maps.LatLng(maplocations[i][0], maplocations[i][1]),
                map: map,
                id: i
            });
            markers.push(marker);            
            bounds.extend(marker.position);
            
            <?php if (!$infowindow) : ?>
            showInfoWindow(marker,i);
            <?php endif ?>
            
            <?php if ($infowindow) : ?>
            google.maps.event.addListener(marker, 'click', (function(marker, i) {
              return function() {
                infowindow.setContent(maplocations[i][2]);
                infowindow.open(map, marker);
              }
            })(marker, i));
            <?php endif ?>
            

        }

        //extend the bounds to include each marker's position
        map.fitBounds(bounds);
        
        <?php if (!$infowindow) : ?>
        function showInfoWindow (marker, i) {
            marker.addListener('click', function() {
                // alle unsichtbar machen
                for (i = 0; i < aw_mapmarker.length; i++) {
                    aw_mapmarker[i].className = aw_mapmarker[i].className.replace('active','');
                }                
                e = aw_mapmarker[marker.id];
                e.className += ' active';
            });            
        }
        <?php endif ?>
        
    }
</script>

<script async defer
        src="https://maps.googleapis.com/maps/api/js?key=<?= $params['key'] ?>&callback=initMap">
</script>
