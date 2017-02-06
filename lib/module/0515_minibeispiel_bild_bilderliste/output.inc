<?php
  $medium = rex_media::get("REX_MEDIA[1]");
  if($medium !=''){
    echo '<b>Bild</b>';
    $image  = '<img src="'.$medium->getUrl().'" alt="'.$medium->getTitle().'" height="'.$medium->getHeight().'" width="'.$medium->getWidth().'" /><p>'.$medium->getValue('copyright').'</p>';

    echo '<p>Bild mit allen Angaben</p>';
    echo $image;
    echo '<hr/>';
    echo '<p>Bild und Media Manager Typ</p>';
    $image2  = '<img src="index.php?rex_media_type=rex_mediapool_preview&rex_media_file=REX_MEDIA[1]" alt="'.$medium->getTitle().'" height="" width="" /><p>'.$medium->getValue('copyright').'</p>';
    echo $image2;
    echo '<br/><hr/><br/>';
  }

  echo '<b>Bilderliste</b><br/>';
  if ("REX_MEDIALIST[1]" != '') {
    $imagelist = explode(',', "REX_MEDIALIST[1]");
  }
  $bilderliste = '';
  foreach ($imagelist as $file) {
    $media = rex_media::get($file);
      if ($media) {
        $mediatitle   = $media->getValue('title');
        $mediadesc    = str_replace(array("\r\n", "\n", "\r"), ' ', $media->getValue('med_description'));
        // mediawidth   =  $media->getValue('width');
        // $mediaheight  =  $media->getValue('height');

        $bilderliste .= '<img alt="' . $mediatitle . '" title="' . $mediadesc . '" src="index.php?rex_media_type=rex_mediapool_detail&amp;rex_media_file='.$file.'" /><br/>';
      }
    }
    echo $bilderliste;
