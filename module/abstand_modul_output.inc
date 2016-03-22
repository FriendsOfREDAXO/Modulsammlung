<?php
if ('REX_VALUE[1]' == '') {
  $abstand = 30;
} else {
  $abstand = 'REX_VALUE[1]';
}

$breite               = 'REX_VALUE[4]';
$container            = '';

  $abstand2 = ($abstand/2)-17;

if ($breite == '100% Browserbreite') {
  $container = 'container-fluid';
} else {
  $container = 'container';
}

if(!rex::isBackend()) {
  $klasse = '';
  $grafik = '';
  if ('REX_VALUE[2]' == 'ja') {
    $klasse = 'trennerlinie';
    $grafik = '';
  }
  if ('REX_VALUE[3]' == 'ja') {
    $klasse = 'trennerliniemitgrafik';
    $grafik = '<img src="index.php?rex_media_type=trenner&rex_media_file=trenner.png" width="30" height="30" alt= "">';
    if ('REX_VALUE[1]' <= 30) {
      $abstand = 30;
    }
  }

  echo '
    <div class="'.$container.'">
      <div class="row">
        <div class="trenner '.$klasse.'" style="height: '.$abstand.'px;">
            <span style="top: '.$abstand2.'px">'.$grafik.'</span>
        </div>
      </div>
  </div>'.PHP_EOL;

} else {

 echo '
  <div id="trennlinie" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Abstand oder Trennlinie mit/ohne Grafik</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Abstand in PX</label>
         <div class="col-sm-9">'.$abstand.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Linie anzeigen</label>
         <div class="col-sm-9">REX_VALUE[2]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Grafik anzeigen</label>
         <div class="col-sm-9">REX_VALUE[3]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Breite des Trenners</label>
         <div class="col-sm-9">'.$breite.'</div>
       </div>
    </div>
  </div>

<style>
#trennlinie .bereichswrapper {
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

</style>'.PHP_EOL;
}

?>
