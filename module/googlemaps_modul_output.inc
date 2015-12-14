<?php
$editor                 = 0;
if(!rex_addon::get('rex_redactor')->isAvailable() AND !rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "Redactor" oder das "MarkItUp" Addon!');
}
if(rex_addon::get('rex_redactor')->isAvailable()) {
  $editor = 'redactor';
 }
if(rex_addon::get('rex_markitup')->isAvailable()) {
  $editor = 'markitup';
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
$erklärungstext       = 'REX_VALUE[10]';

$text = '';
  if ($erklärungstext !='') {
    if ($editor == 'markitup' AND rex_addon::get('textile')->isAvailable()) {
     $erklärungstext = str_replace('<br />', '', $erklärungstext);
     $erklärungstext = rex_textile::parse($erklärungstext);
    }
  }
$text = $erklärungstext;



if(!rex::isBackend()) {


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
         <div class="col-sm-9">'.$sprache.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Zoom</label>
         <div class="col-sm-9">'.$zoom.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Markerfarbe</label>
         <div class="col-sm-9">'.$markerfarbe.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Infotext</label>
         <div class="col-sm-9">'.html_entity_decode($infotext).'</div>
       </div>


    <h2>Routenplaner</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Routenplaner anzeigen</label>
         <div class="col-sm-9">'.$routenplaner_anzeige.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Senden Button Text</label>
         <div class="col-sm-9">'.$sendenbutton.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Erklärungstext</label>
         <div class="col-sm-9">'.$erklärungstext.'</div>
       </div>
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

