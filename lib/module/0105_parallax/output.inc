<?php

$output_fe[]     = '';
$output_be[]     = '';
$breite          = 'REX_VALUE[5]';
$hoehe           = 'REX_VALUE[4]';
$geschwindigkeit = 'REX_VALUE[3]';
$ueberschrift    = 'REX_VALUE[1]';
$text            = 'REX_VALUE[2]';
$output_backend_ueberschrift = '';
$output_backend_text = '';

if ($breite == '100% Browserbreite') {
  $container = 'container-fluid';
} else {
  $container = 'container';
}

if ($hoehe  == '') { $hoehe  = "350"; }
if ($geschwindigkeit  == '') { $geschwindigkeit  = "0.3"; }


if($ueberschrift != '') {
  $output_backend_ueberschrift = '
    <div class="form-group">
       <label class="col-sm-3 control-label">Überschrift</label>
       <div class="col-sm-9">'.$ueberschrift.'</div>
    </div>';
}


if($text != '') {
  $text = 'REX_VALUE[id=2 output=html]';
  $text = rex_textile::parse($text);
  $output_backend_text = '
    <div class="form-group">
       <label class="col-sm-3 control-label">Text</label>
       <div class="col-sm-9">'.$text.'</div>
    </div>';
}


if(!rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
}

$medium = rex_media::get("REX_MEDIA[1]");

  if ($medium != '') {
    $output_fe[] = '<div id="parallax_REX_SLICE_ID" class="prallax" data-enllax-ratio="'.$geschwindigkeit.'" style="height: '.$hoehe.'px; background-image: url(index.php?rex_media_type=parallax&rex_media_file=REX_MEDIA[1])">';

    if ($ueberschrift != '' || $text != '') {
      $output_fe[] = '
          <div class="parallax_text_wrapper">
            <h3 class="parallax_ueberschrift">'.$ueberschrift.'</h3>
            <span class="parallax_text">'.$ueberschrift.'</span>
          </div>';
    }

    $output_fe[] = '</div>';

  $output_be_bild = 'REX_MEDIA[1]<br/><br/><img src="index.php?rex_media_type=rex_mediapool_detail&rex_media_file=REX_MEDIA[1]" alt="'.$medium->getTitle().'" height="" width="" /><p>'.$medium->getValue('copyright').'</p>';

  } else {
  $output_be_bild = '<div class="warning"><b>ACHTUNG:</b><br/>Sie haben keine Dateie angegeben. Das ist recht sinnfrei wenn dieses Modul benutzt wird!</div>';

  }





if (!rex::isBackend()) {
  echo '
  <div class="'.$container.'">
    <div class="row">';


    echo '<div id="owl-REX_SLICE_ID" class="owl-carousel">';
      print implode($output_fe);
    echo '</div>';


  echo '</div>
  </div>
  <script>
   $(document).ready(function() {
      $("parallax_REX_SLICE_ID").enllax();
    });
  </script>
  ';



} else {
  echo '
    <div id="parallax">
      <div class="form-horizontal output">
        <h2>Parallax</h2>
        <div class="form-group">
          <label class="col-sm-3 control-label">Bild</label>
          <div class="col-sm-9">'.$output_be_bild.'</div>
        </div>
      '.$output_backend_ueberschrift.'
      '.$output_backend_text.'
       <div class="form-group">
         <label class="col-sm-3 control-label">Scrollgeschwindigkeit</label>
         <div class="col-sm-9">REX_VALUE[3]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Höhe</label>
         <div class="col-sm-9">'.$hoehe.'px</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Breite des Sliders</label>
         <div class="col-sm-9">'.$breite.'</div>
       </div>
      </div>
    </div>

<style>
#parallax .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#parallax .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#parallax h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

#parallax .item {
  position: relative;
  display: inline-block;
  width: 90px;
  height: 90px;
  border: 1px solid #9da6b2;
  margin: 0 5px 0 0;
  background: #DFE3E9;
}

#parallax .item img {
    position:absolute;
    top:0;
    bottom:0;
    left: 0;
    right: 0;
    margin: auto;
}

 #parallax .warning {
    color: #f00;
  }

</style>'.PHP_EOL;
}

/*
  Der folgende Abschnitt gehört eighentlich nicht in die Modulausgabe.
  Bitte die JS und CSS Dateien selbst im Frontend Template implementieren und diesen Abschnitt hier löschen.
*/
if (!rex::isBackend()) {
  echo '
    <script src="'.rex_url::base('assets/enllax/jquery.enllax.min.js').'" type="text/javascript" ></script>
  ';
}
