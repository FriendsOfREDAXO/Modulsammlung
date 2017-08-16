<?php
$fe         = '';
$be         = '';
$class      = '';
$galeriebreite  = 'REX_VALUE[2]';
$bilder_breite  = 'REX_VALUE[3]';
$bilder_hoehe   = 'REX_VALUE[4]';

if ($bilder_hoehe  == '') { $bilder_hoehe  = "200"; }
if ($bilder_breite == '') { $bilder_breite = "200"; }

if ($galeriebreite == '100% Browserbreite') {
  $container = 'container-fluid';
} else {
  $container = 'container';
}

// Medialist
if ("REX_MEDIALIST[1]" != '') {
  $imagelist = explode(',', "REX_MEDIALIST[1]");

// Art der Galerie
if ('REX_VALUE[1]' == 'columns') {
  $art   = 'Tiles - Columns';
  $class  = 'columns';
  $js     = 'gallery_theme: "tiles",
             tiles_col_width: '.$bilder_breite.'';
}

if ('REX_VALUE[1]' == 'justified') {
  $art   = 'Tiles - Justified';
  $class  = 'justified';
  $js     = 'gallery_theme: "tiles",
             tiles_type: "justified",
             tiles_justified_row_height: '.$bilder_hoehe.'';
}

if ('REX_VALUE[1]' == 'nested') {
  $art   = 'Tiles - Nested';
  $class  = 'nested';
  $js     = 'gallery_theme: "tiles",
             tiles_type: "nested",
             tiles_nested_optimal_tile_width: '.$bilder_breite.'';
}

if ('REX_VALUE[1]' == 'grid') {
  $art   = 'Tiles Grid';
  $class  = 'grid';
  $js     = 'gallery_theme: "tilesgrid",
             tile_width: '.$bilder_breite.',
              tile_height: '.$bilder_hoehe.'';
}

$fe .= '
  <section id="unite_gallery" class="'.$container.'">
   <div id="galerieREX_SLICE_ID" class="'.$class.'" style="display:none;">
';

foreach ($imagelist as $file) {
  $media = rex_media::get($file);
  if ($media) {
    $mediatitle = $media->getValue('title');
    $mediadesc = str_replace(array("\r\n", "\n", "\r"), ' ', $media->getValue('med_description'));
    $mediawidth =  $media->getValue('width');
    $mediaheight =  $media->getValue('height');

    $fe .= '<img alt="' . $mediatitle . '" src="index.php?rex_media_type=galerie_thumb&rex_media_file='.$file.'" data-image="index.php?rex_media_type=galerie_big&rex_media_file='.$file.'" data-description="' . $mediadesc . '">';

    $be .= '<div class="item">
              <img src="index.php?rex_media_type=rex_mediapool_preview&rex_media_file='.$file.'" alt="'.$file.'">
            </div>';
    }
  }

$fe .= '
    </div>
  </section>';

$fe .= "
  <script type='text/javascript'>
    $(document).ready(function(){
      $('#galerieREX_SLICE_ID').unitegallery({
        ".$js."
      });
    });
  </script>
";
}

if (!rex::isBackend()) {
  echo $fe;
} else {
echo '
 <div id="unite_gallery">
    <div class="form-horizontal output">
     <h2>Galerie</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Art der Galerie</label>
         <div class="col-sm-9">
         '.$art.'
         </div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Breite der Galerie</label>
         <div class="col-sm-9">REX_VALUE[2]</div>
       </div>';

  if ('REX_VALUE[1]' == 'justified' || 'REX_VALUE[1]' == 'grid') {
    echo '<div class="form-group">
            <label class="col-sm-3 control-label">Höhe der Bilder</label>
            <div class="col-sm-9">'.$bilder_hoehe.' px</div>
          </div>';
  }

  if ('REX_VALUE[1]' == 'columns' || 'REX_VALUE[1]' == 'nested' || 'REX_VALUE[1]' == 'grid') {
    echo '<div class="form-group">
            <label class="col-sm-3 control-label">Breite der Bilder</label>
            <div class="col-sm-9">'.$bilder_breite.' px</div>
          </div>';
  }

echo ' <div class="form-group">
         <label class="col-sm-3 control-label">Bilder</label>
         <div class="col-sm-9">'.$be.'</div>
       </div>';

echo '</div>
  </div>
<style>
#unite_gallery .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#unite_gallery .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#unite_gallery h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

#unite_gallery .item {
  position: relative;
  display: inline-block;
  width: 90px;
  height: 90px;
  border: 1px solid #9da6b2;
  margin: 0 5px 0 0;
  background: #DFE3E9;
}

#unite_gallery .item img {
    position:absolute;
    top:0;
    bottom:0;
    left: 0;
    right: 0;
    margin: auto;
}

</style>'.PHP_EOL;
}


?>

<?php
/*
  Der folgende Abschnitt gehört eighentlich nicht in die Modulausgabe.
  Bitte die JS und CSS Dateien selbst im Frontend Template implementieren und diesen Abschnitt hier löschen.
*/
if (!rex::isBackend()) {
  echo '
    <link href="'.rex_url::base('assets/unitegallery/css/unite-gallery.css').'" type="text/css" rel="stylesheet"/>
    <script src="'.rex_url::base('assets/unitegallery/themes/default/ug-theme-default.js').'" type="text/javascript" ></script>
    <link href="'.rex_url::base('assets/unitegallery/themes/default/ug-theme-default.css').'" type="text/css" rel="stylesheet" />
    <script src="'.rex_url::base('assets/unitegallery/js/unitegallery.min.js').'" type="text/javascript" ></script>
    <script src="'.rex_url::base('assets/unitegallery/themes/tiles/ug-theme-tiles.js').'" type="text/javascript"></script>
    <script src="'.rex_url::base('assets/unitegallery/themes/tilesgrid/ug-theme-tilesgrid.js').'" type="text/javascript"></script>
  ';
}


