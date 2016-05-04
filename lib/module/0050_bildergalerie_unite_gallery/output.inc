<?php

// blank.gif einbauen

$fe         = '';
$be         = '';
$class      = '';
$truncate   = '';
$hoehe      = 'REX_VALUE[2]';

if ("REX_MEDIALIST[1]" != '') {
  $imagelist = explode(',', "REX_MEDIALIST[1]");

  if ('REX_VALUE[1]' == 'fleximages') {
    $class = 'class="flex-images"';
  } else {
    $class = 'class="standard"';
  }


  if ($hoehe == '') {
      $hoehe = "200";
  }

  $fe .= '
  <section id="unite_gallery" class="container">
        <div id="galerieREX_SLICE_ID" '.$class.'>
  ';
        foreach ($imagelist as $file) {
          $media = rex_media::get($file);
          if ($media) {

            $mediatitle = $media->getValue('title');
            $mediadesc = str_replace(array("\r\n", "\n", "\r"), ' ', $media->getValue('med_description'));
            $mediawidth =  $media->getValue('width');
            $mediaheight =  $media->getValue('height');

            $fe .= '
            <div class="item" data-w="'.$mediawidth.'" data-h="'.$mediaheight.'">
              <a href="index.php?rex_media_type=galerie_big&amp;rex_media_file='.$file.'" title="' . $mediadesc . '">
                <img src="index.php?rex_media_type=galerie_thumb&amp;rex_media_file='.$file.'" alt="' . $mediatitle . '" />
              </a>
            </div>';

            $be .= '
              <div class="item">
                <img src="index.php?rex_media_type=rex_mediapool_preview&amp;rex_media_file='.$file.'" alt="'.$file.'">
              </div>';
          }
        }

      $fe .= '
    </div>
  </section><!--/Portfoliowrap -->';

  if ('REX_VALUE[3]' == 'verbergen') {
    $truncate = ', truncate: 1';
  } else {
    $truncate = '';
  }

  if ('REX_VALUE[1]' == 'fleximages') {
  echo "
    <script>
    $(document).ready(function() {
      $('#galerieREX_SLICE_ID').flexImages({rowHeight: ".$hoehe." ".$truncate."});

      $('#galerieREX_SLICE_ID a').simpleLightbox({
        overlay: true,
        closeText: 'hhh',
        animationSpeed: 1000,
        disableScroll: false
      });
    });
    </script>
  ";
  }

}

if (!rex::isBackend()) {
  echo $fe;
} else {
echo '
 <div id="galerie">
    <div class="form-horizontal output">
     <h2>Galerie</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Art der Galerie</label>
         <div class="col-sm-9">';

  if ('REX_VALUE[1]' == 'fleximages') {
    echo 'mosaik';
  } else {
    echo 'standard';
  }
echo '   </div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Breite der Galerie</label>
         <div class="col-sm-9">REX_VALUE[4]</div>
       </div>';



if ('REX_VALUE[1]' == 'fleximages') {

echo ' <div class="form-group">
         <label class="col-sm-3 control-label">Höhe der Bilder</label>
         <div class="col-sm-9">'.$hoehe.' px</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">unvollständige Zeilen</label>
         <div class="col-sm-9">REX_VALUE[3]</div>
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
  margin-bottom: 5px;
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
