<?php

$output_fe_bilder     = '';
$output_be_bilder     = '';
$output_fe_js         = '';
$breite               = 'REX_VALUE[5]';
$container            = '';
$autoplay             = 'false';
$paginierung          = 'false';
$navigation           = 'false';
$output_backend_text  = '';
$text                 = '';

if ($breite == '100% Browserbreite') {
    $container = 'container-fluid';
} else {
    $container = 'container';
}

// Medialist
if ("REX_MEDIALIST[1]" != '') {
    $imagelist = explode(',', "REX_MEDIALIST[1]");
    foreach ($imagelist as $file) {
        $media = rex_media::get($file);
        if ($media) {
            $mediatitle = $media->getValue('title');
            $mediadesc = str_replace(array("\r\n", "\n", "\r"), ' ', $media->getValue('med_description'));

            $output_fe_bilder .= '<img src="index.php?rex_media_type=owl_carousel&rex_media_file='.$file.'" alt="' . $mediatitle . ' width="100%" >';

            $output_be_bilder .= '
        <div class="item">
          <img src="index.php?rex_media_type=rex_mediapool_preview&rex_media_file='.$file.'" alt="'.$file.'">
        </div>';
        }
    }
} else {
    $output_be_bilder = '<div class="warning"><b>ACHTUNG:</b><br/>Sie haben keine Dateien für den Slider angegeben. Das ist recht sinnfrei wenn dieses Modul benutzt wird!</div>';
}

if ('REX_VALUE[1]' != 'nein') {
    $autoplay = '
    autoplay:true,
    autoplayTimeout:1000,
    autoplayHoverPause:true,';
} else{
    $autoplay = '';
}
if ('REX_VALUE[2]' != 'nein') {
    $paginierung = 'true';
}
if ('REX_VALUE[3]' != 'nein') {
    $navigation = 'true';
}
$anzahl = 'REX_VALUE[4]';

if('REX_VALUE[6]' != '') {
    $text = markitup::parseOutput ('textile', 'REX_VALUE[id=6 output="html"]');
    $output_backend_text = '
    <div class="form-group">
       <label class="col-sm-3 control-label">Text</label>
       <div class="col-sm-9">'.$text.'</div>
    </div>';
}


$output_fe_js = '
  <script>
    $(document).ready(function() {
      $("#owl-REX_SLICE_ID").owlCarousel({
        '.$autoplay.'
        dots: '.$paginierung.',
        nav : '.$navigation.',
        navigationText:  ["{{ prev }}","{{ next }}"],
        items: '.$anzahl.',
      });
    });
  </script>';

if (!rex::isBackend()) {
    echo '
  <div class="'.$container.'">
    <div class="row">';

    if ($text != '') {
        echo '
    <div class="col-xs-12 col-sm-6">';
        echo '<div id="owl-REX_SLICE_ID" class="owl-carousel owl-theme">';
        echo $output_fe_bilder;
        echo '</div>
    </div>
    <div class="col-xs-12 col-sm-6">
    '.$text.'
    </div>';

    } else {
        echo '<div id="owl-REX_SLICE_ID" class="owl-carousel owl-theme">';
        echo $output_fe_bilder;
        echo '</div>';
    }

    echo '</div>
  </div>';
    echo $output_fe_js;
} else {
    echo '
 <div id="slider_text">
    <div class="form-horizontal output">
     <h2>Slider mit/ohne Text</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Sliderbilder</label>
         <div class="col-sm-9">'.$output_be_bilder.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Automatisch abspielen</label>
         <div class="col-sm-9">REX_VALUE[1]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Paginierung anzeigen</label>
         <div class="col-sm-9">REX_VALUE[2]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Navigation anzeigen</label>
         <div class="col-sm-9">REX_VALUE[3]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Anzahl der Bilder</label>
         <div class="col-sm-9">REX_VALUE[4]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Breite des Sliders</label>
         <div class="col-sm-9">REX_VALUE[5]</div>
       </div>
       '.$output_backend_text .'
</div>
  </div>
<style>
#slider_text .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#slider_text .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#slider_text h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

#slider_text .item {
  position: relative;
  display: inline-block;
  width: 90px;
  height: 90px;
  border: 1px solid #9da6b2;
  margin: 0 5px 0 0;
  background: #DFE3E9;
}

#slider_text .item img {
    position:absolute;
    top:0;
    bottom:0;
    left: 0;
    right: 0;
    margin: auto;
}

 #slider_text .warning {
    color: #f00;
  }

</style>'.PHP_EOL;
}



?>


<?php
/*
  Der folgende Abschnitt gehört eigentlich nicht in die Modulausgabe.
  Bitte die JS und CSS Dateien selbst im Frontend Template implementieren und diesen Abschnitt hier löschen.
*/
if (!rex::isBackend()) {
    echo '
    <link rel="stylesheet" href="'.rex_url::base('assets/owl_carousel/owl.carousel.min.css').'" type="text/css" />
    <link rel="stylesheet" href="'.rex_url::base('assets/owl_carousel/owl.theme.default.min.css').'" type="text/css" />
    <script src="'.rex_url::base('assets/owl_carousel/owl.carousel.min.js').'" type="text/javascript" ></script>
  ';
}
