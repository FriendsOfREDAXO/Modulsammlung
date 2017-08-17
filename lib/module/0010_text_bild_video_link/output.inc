<?php

$grid                              = 'REX_VALUE[20]';
$individuelle_css_klasse_container = 'REX_VALUE[16]';
$individuelle_css_id_container     = 'REX_VALUE[17]';
$individuelle_css_klasse1          = '';
$individuelle_css_klasse2          = '';
$individuelle_css_klasse3          = '';
$individuelle_css_klasse4          = '';
$individuelle_css_id1               = '';
$individuelle_css_id2              = '';
$individuelle_css_id3              = '';
$individuelle_css_id4              = '';
$mediamanagertyp                   = 'REX_VALUE[18]';
$out                               = '';
$zaehler                           = '';
$nummer                            = '';
$outback                           = '';
$abstandsklasse                    = '';
$bildposition                      = '';
$editor                            = '';
$downloads                         = '';
$outbackfiles                      = '';

if($mediamanagertyp == '') {
  $mediamanagertyp = 'standard';
}

if(!rex_addon::get('markitup')->isAvailable() && !rex_addon::get('rex_redactor2')->isAvailable()) {
  $editor = 'markitup';
  echo rex_view::error('Dieses Modul benötigt das "MarkItUp" oder das "Redactor 2" Addon!');
}

$html_block = array();
$values = array();

$values[1]                = rex_var::toArray('REX_VALUE[1]');
$values[1]['media_1']     = 'REX_MEDIA[id=1 output=1]';
$values[1]['link_intern'] = 'REX_LINK[id=1 output="id"]';
$values[1]['medialist_1'] = 'REX_MEDIALIST[id=1 output=1]';

$values[2]                = rex_var::toArray('REX_VALUE[2]');
$values[2]['media_1']     = 'REX_MEDIA[id=2 output=1]';
$values[2]['link_intern'] = 'REX_LINK[id=2 output="id"]';
$values[2]['medialist_1'] = 'REX_MEDIALIST[id=2 output=1]';

$values[3]                = rex_var::toArray('REX_VALUE[3]');
$values[3]['media_1']     = 'REX_MEDIA[id=3 output=1]';
$values[3]['link_intern'] = 'REX_LINK[id=3 output="id"]';
$values[3]['medialist_1'] = 'REX_MEDIALIST[id=3 output=1]';

$values[4]                = rex_var::toArray('REX_VALUE[4]');
$values[4]['media_1']     = 'REX_MEDIA[id=4 output=1]';
$values[4]['link_intern'] = 'REX_LINK[id=4 output="id"]';
$values[4]['medialist_1'] = 'REX_MEDIALIST[id=4 output=1]';

if ($grid == '12') {
    unset($values[2]);
    unset($values[3]);
    unset($values[4]);
}

if ($grid == '6_6' || $grid == '8_4' || $grid == '4_8') {
    unset($values[3]);
    unset($values[4]);
}

if ($grid == '4_4_4' || $grid == '6_3_3' || $grid == '3_6_3' || $grid == '3_3_6') {
    unset($values[4]);
}

if ($grid == '3_3_3_3') {}

if ('REX_VALUE[19]') {
  $reihenfolge = explode(',','REX_VALUE[19]');
} else {
  $reihenfolge = array('1','2','3','4');
}

foreach ($reihenfolge as $nummer) {
  if (isset($values[$nummer])) {

    $value = $values[$nummer];
    $zaehler = $zaehler + 1;

    $outback .= '<div class="bereichswrapper"><h2>Bereich '.$zaehler.'</h2>'.PHP_EOL;

/****
*
*     Link
*
****/
      $link           = '';
      $linkanfang     = '';
      $linkende       = '';
      $outback_link   = '';

      if ($value['link_intern'] OR $value['link_extern'] != '') {
        $outback_link .= '<h3>Link</h3>'.PHP_EOL;

        if ($value['link_intern'] != 0) {
          $linkanfang = '<a class="collink" href="'.rex_geturl($value['link_intern'], rex_clang::getCurrentId()).'">';
          $article=rex_article::get($value['link_intern']);
          $name=$article->getName();

          $outback_link .= '
            <div class="form-group">
             <label class="col-sm-3 control-label">Link intern</label>
             <div class="col-sm-9">
               <a href="index.php?page=content&article_id='.$value['link_intern'].'&mode=edit">'.$name.' (ID = '.$value['link_intern'].')</a>
             </div>
            </div>'.PHP_EOL;
        }

        if ($value['link_extern'] != '') {

          $linkanfang = '<a class="extern collink" href="'.$value['link_extern'].'">';

          $outback_link .= '
            <div class="form-group">
              <label class="col-sm-3 control-label">Link extern</label>
              <div class="col-sm-9">
                <a target="_blank" href="'.$value['link_extern'].'">'.$value['link_extern'].'</a>
              </div>
            </div>'.PHP_EOL;
        }

        if ($value['link_intern'] AND $value['link_extern'] != '') {
          $outback_link .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label"></label>
              <div class="col-sm-9 warning">
                ACHTUNG:<br/>Es wurde ein interner <u>und</u> ein externer Link angegeben.
              </div>
            </div>'.PHP_EOL;
        }

        if ($value['linkbezeichnung'] != '' ) {
          $outback_link .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label">Linkbezeichnung</label>
              <div class="col-sm-9">'.$value['linkbezeichnung'].'</div>
            </div>'.PHP_EOL;
        }

        if ($value['ueberschriftlink'] == 'ja' ) {
          $outback_link .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label">Überschrift verlinken</label>
              <div class="col-sm-9">Ja</div>
            </div>'.PHP_EOL;
        }

        if ($value['bildlink'] == 'ja' ) {
          $outback_link .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label">Bild verlinken</label>
              <div class="col-sm-9">Ja</div>
            </div>'.PHP_EOL;
        }

        $linkende = '</a>'.PHP_EOL;

        if ($value['linkbezeichnung'] != '' ) {
          $link = $linkanfang.$value['linkbezeichnung'].$linkende;
        }

      }


/****
*
*     Überschrift
*
****/
      $ueberschrift             = '';
      if ($value['ueberschrift']  != '') {

        if ($value['ueberschrift_art'] == 'faq') { // FAQ
          $ueberschrift .= '<div class="accordionueberschrift">'.$value['ueberschrift'].'</div>'.PHP_EOL;
        } else {
          $ueberschrift .= '<'.$value['ueberschrift_art'].' class="ueberschrift">'.$value['ueberschrift'].'</'.$value['ueberschrift_art'].'>'.PHP_EOL;
        }

        if ($value['ueberschriftlink'] == 'ja' AND $value['ueberschrift_art'] != 'faq') {
          $ueberschrift = $linkanfang.$ueberschrift.$linkende;
        }

        switch ($value['ueberschrift_art']) {
          case 'h1':  $art = 'Überschrift 1 (H1) - <i>Nur einmal pro Seite verwenden</i>'; break;
          case 'h2':  $art = 'Überschrift 2 (H2)';                                         break;
          case 'h3':  $art = 'Überschrift 3 (H3)';                                         break;
          case 'h4':  $art = 'Überschrift 4 (H4)';                                         break;
          case 'faq': $art = 'FAQ Überschrift - <i>Inhalt: Fließtext</i>';                break;
        }

        $outback .= '
          <h3>Überschrift</h3>

          <div class="form-group">
            <label class="col-sm-3 control-label">Überschrift</label>
            <div class="col-sm-9">
              '.$value['ueberschrift'].'
            </div>
          </div>

          <div class="form-group">
            <label class="col-sm-3 control-label">Art der Überschrift</label>
            <div class="col-sm-9">
              '.$art.'
            </div>
          </div>'.PHP_EOL;
      }


/****
*
*     Video
*
****/

      $video = '';

      if ($value['youtube_video_id'] !='' OR $value['vimeo_video_id'] !='' ) {
        $outback .= '<h3>Video</h3>';

        // Youtube
        if ($value['youtube_video_id'] !='') {
            $video = '
              <div class="responsive-video">
              <iframe src="https://www.youtube-nocookie.com/embed/'.$value['youtube_video_id'].'?rel=0&amp;showinfo=0"
              width="1600" height="900" frameborder="0" webkitAllowFullScreen
              mozallowfullscreen allowFullScreen></iframe>
              </div>'.PHP_EOL;
            $outback .= '
            <div class="form-group">
              <label class="col-sm-3 control-label">Youtube Video ID</label>
              <div class="col-sm-9">'.$value['youtube_video_id'].'</div>
            </div>'.PHP_EOL;
        }

        // Vimeo
        if ($value['vimeo_video_id'] !='') {
        $video = '
        <div class="responsive-video">
        <iframe src="http://player.vimeo.com/video/'.$value['vimeo_video_id'].'?title=0&amp
        ;byline=0&amp;portrait=0&amp;autoplay=0"
        width="1600" height="900" frameborder="0" webkitAllowFullScreen
        mozallowfullscreen allowFullScreen></iframe>
        </div>'.PHP_EOL;

        $outback .= '
            <div class="form-group">
              <label class="col-sm-3 control-label">Vimeo Video ID</label>
              <div class="col-sm-9">'.$value['vimeo_video_id'].'</div>
            </div>'.PHP_EOL;
        }

        if ($value['youtube_video_id'] !='' AND $value['vimeo_video_id'] !='') {
          $outback .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label"></label>
              <div class="col-sm-9 warning">
                ACHTUNG:<br/>Es kann nur eine YouTube ID oder eine Vimeo ID angegeben werden.
              </div>
            </div>'.PHP_EOL;
          }

      }


/****
*
*     Teasertext & Text
*
****/

      $teasertext = '';
      $text       = '';
      if ($value['teasertext'] !='' OR $value['text'] !='' ) {
        $outback .= '<h3>Text</h3>';

        // Teasertext
        if ($value['teasertext'] !='') {
            $teasertext = '<div class="teasertext">'.$value['teasertext'].'</div>'.PHP_EOL;
            $outback .= '
            <div class="form-group">
              <label class="col-sm-3 control-label">Teasertext</label>
              <div class="col-sm-9">'.$value['teasertext'].'</div>
            </div>'.PHP_EOL;
        }

        // Text
        $text = '';
        if ($value['text'] !='') {

          if (rex_addon::get('rex_redactor2')->isAvailable()) {
            $value['text'] = $value['text'];
          } else {
            $value['text'] = markitup::parseOutput ('textile',  $value['text']);
          }

          $text = '<div class="text">'.$value['text'].'</div>'.PHP_EOL;

          if ($value['ueberschrift_art'] == 'faq') {
            $text = '<div class="accordioninhalt">'.$value['text'].'</div>'.PHP_EOL;
          }

          $outback .= '
            <div class="form-group">
              <label class="col-sm-3 control-label">Text</label>
              <div class="col-sm-9">'.$value['text'].'</div>
            </div>'.PHP_EOL;
        }
      }


/****
*
*     Bild
*
****/

      $media = '';
      $bild  = '';
      $outbackbildinfos = '';
      $position = '';

      if ($value['media_1'] != '') {
        $file = rex_media::get($value['media_1']);
        $filename     = $file->getFilename();
        $titel        = $file->getTitle();
        $beschreibung = $file->getValue('description');
        $copyright    = $file->getValue('copyright');

        if ($value['bildanpassen'] == 'nein') {
          $width = '';
        } else {
          $width = 'width="100%"';
        }

        $bild_img  = '<img src="'.rex_url::frontendController().'?rex_media_type='.$mediamanagertyp.'&amp;rex_media_file='.$filename.'" alt="'.$value['alt'].'" '.$width.' />'.PHP_EOL;

        if ($value['bildlink'] == 'ja') {
          $bild_img = $linkanfang.$bild_img.$linkende;
        }

        if ($titel != '' ) {
          $outbackbildinfos .= '<br/><b>Titel:</b> '.$titel;
          $titel = '<figcaption class="titel">'.$titel.'</figcaption>'.PHP_EOL;
        } else {
          $titel = '';
        }
        if ($copyright != '') {
          $outbackbildinfos .= '<br/><b>Copyright:</b> '.$copyright;
          $copyright = '<figcaption class="copyright">'.$copyright.'</figcaption>'.PHP_EOL;
        } else {
          $copyright = '';
        }
        if ($beschreibung != '' ) {
          $outbackbildinfos .= '<br/><b>Beschreibung:</b> '.$beschreibung;
          $beschreibung = '<figcaption class="beschreibung">'.$beschreibung.'</figcaption>'.PHP_EOL;
        } else {
          $beschreibung = '';
        }

        if ($value['bildinformationen'] == 'ja' ) {
          $bild = '<figure class="image">'.PHP_EOL;
          $bild .= $bild_img;
          $bild .= $copyright;
          $bild .= $titel;
          $bild .= $beschreibung;
          $bild .= '</figure>'.PHP_EOL;
        } else {
          $bild = '<figure class="image">'.PHP_EOL;
          $bild .= $bild_img;
          $bild .= '</figure>'.PHP_EOL;
        }

        $outback .= '<h3>Bild</h3>';

        $outback .= '
          <div class="form-group">
            <label class="col-sm-3 control-label">Größe anpassen</label>
            <div class="col-sm-9">'.$value['bildanpassen'].'</div>
          </div>'.PHP_EOL;

        switch ($value['bildposition']) {
          case 'oben':             $bildpos = 'über dem Text';         break;
          case 'unten':            $bildpos = 'unter dem Text';        break;
          case 'nachueberschrift': $bildpos = 'unter der Überschrift'; break;
          case 'nachteaser':       $bildpos = 'unter dem Teasertext';  break;
        }

        $outback .= '
          <div class="form-group">
            <label class="col-sm-3 control-label">Position</label>
            <div class="col-sm-9">'.$bildpos.'</div>
          </div>'.PHP_EOL;

        $outback .= '
          <div class="form-group">
            <label class="col-sm-3 control-label">Bild</label>
            <div class="col-sm-9">
              '.$filename.'<br/>
              <img src="'.rex_url::frontendController().'?rex_media_type=rex_mediabutton_preview&rex_media_file='.$filename.'"  />
            </div>
          </div>'.PHP_EOL;

        if ($value['alt']) {
          $outback .= '
            <div class="form-group">
              <label class="col-sm-3 control-label">Alternativtext</label>
              <div class="col-sm-9">'.$value['alt'].'</div>
            </div>'.PHP_EOL;
        } else {
          $outback .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label"></label>
              <div class="col-sm-9 warning">
                ACHTUNG:<br/>Es wurde kein Alt-Text für das Bild angegeben.
              </div>
            </div>'.PHP_EOL;
        }

        $outback .= '
          <div class="form-group ">
            <label class="col-sm-3 control-label">Bildinfos ausgeben</label>
            <div class="col-sm-9">'.$value['bildinformationen'].'</div>
          </div>'.PHP_EOL;

        if ($value['bildinformationen'] == 'ja') {

        if ($titel != '' ) {
          $outback .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label">Titel</label>
              <div class="col-sm-9">'.$titel.'</div>
            </div>'.PHP_EOL;
          }

        if ($beschreibung != '' ) {
          $outback .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label">Beschreibung</label>
                <div class="col-sm-9">'.$beschreibung.'</div>
            </div>'.PHP_EOL;
        }

        if ($copyright != '') {
          $outback .= '
            <div class="form-group ">
              <label class="col-sm-3 control-label">Copyright</label>
              <div class="col-sm-9">'.$copyright.'</div>
            </div>'.PHP_EOL;
        }
      }
  }

/****
*
*     Download
*
***/

      if ($value['medialist_1'] !='') {
        $outback .= '<h3>Download</h3>';

        if (!function_exists('datei_groesse')) {
          function datei_groesse($URL) {
            $groesse = filesize($URL);
            if($groesse<1000) {
              return number_format($groesse, 0, ",", ".")." Bytes";
            } elseif($groesse<1000000) {
              return number_format($groesse/1024, 0, ",", ".")." kB";
            } else {
              return number_format($groesse/1048576, 0, ",", ".")." MB";
            }
          }
        }

        // Icon ermitteln
        if (!function_exists('parse_icon')) {
          function parse_icon($ext) {
            switch (strtolower($ext)) {
              case 'doc': return '<i class="fa fa-file-word-o"></i>';
              case 'pdf': return '<i class="fa fa-file-pdf-o"></i>';
              case 'zip': return '<i class="fa fa-archive-pdf-o"></i>';
              case 'jpg': return '<i class="fa fa-file-image-o"></i>';
              case 'png': return '<i class="fa fa-file-image-o"></i>';
              case 'gif': return '<i class="fa fa-file-image-o"></i>';
              // nach Belieben ergänzen, z.B. wie hier mit Icons von Font-Awesome
              default:
              return '';
            }
          }
        }

        $arr = explode(",",$value['medialist_1']);

        foreach ($arr as $value_dl) {

          $extension = substr(strrchr($value_dl, '.'), 1);
          $parsed_icon = parse_icon($extension);
          $downloadmedia = rex_media::get($value_dl);
          $file_desc = $downloadmedia->getValue('med_description');

          $outbackfiles .= '<p>'.$value_dl.'</p>';

          $downloads .='
          <li><a class="downloadlink" href="index.php?rex_media_type=download&amp;rex_media_file='.$value_dl.'">'.$parsed_icon;

           // Beschreibungstext als Linktext, falls vorhanden, ansonsten Dateiname
           if ($file_desc != "") {
             $downloads .= $file_desc;
           } else {
             $downloads .= $value_dl;
           }

           $downloads .= ' ('.datei_groesse(rex_path::media($value_dl)).')</a></li>';
           $downloads =  '<ul class="downloads">'.$downloads.'</ul>';
        }

        $outback .= '
          <div class="form-group">
            <label class="col-sm-3 control-label">Dateien</label>
            <div class="col-sm-9">'.$outbackfiles.'</div>
          </div>'.PHP_EOL;

      }

    $outback .= $outback_link;


  if ($value['individuelle_css_id'] !='' OR $value['individuelle_css_id'] !='') {
    $outback .='
      <h3>Sonstiges</h3>'.PHP_EOL;
  }

  if ($value['individuelle_css_id'] ) {
      $outback .='
      <div class="form-group">
        <label class="col-sm-3 control-label">Individuelle CSS ID</label>
        <div class="col-sm-9">
           '.$value['individuelle_css_id'].'
        </div>
      </div>'.PHP_EOL;
  }

  if ($value['individuelle_css_klasse'] ) {
      $outback .='
      <div class="form-group">
        <label class="col-sm-3 control-label">Individuelle CSS Klasse</label>
        <div class="col-sm-9">
           '.$value['individuelle_css_klasse'].'
        </div>
      </div>'.PHP_EOL;
  }

    $outback .= '</div>'.PHP_EOL;

    $individuelle_css_klasse[$zaehler] = $value['individuelle_css_klasse'];
    $individuelle_css_id[$zaehler] = ' ID = "'.$value['individuelle_css_id'].'" ';

    switch($value['bildposition']) {
	  case 'oben':
        $html_block[$zaehler] = '';
        $html_block[$zaehler] .= $bild;
        $html_block[$zaehler] .= $ueberschrift;
        $html_block[$zaehler] .= $teasertext;
        $html_block[$zaehler] .= $video;
        $html_block[$zaehler] .= $text;
        $html_block[$zaehler] .= $link;
        $html_block[$zaehler] .= $downloads;
      break;
      case 'unten':
         $html_block[$zaehler]  = '';
         $html_block[$zaehler] .= $ueberschrift;
         $html_block[$zaehler] .= $teasertext;
         $html_block[$zaehler] .= $video;
         $html_block[$zaehler] .= $text;
         $html_block[$zaehler] .= $link;
         $html_block[$zaehler] .= $bild;
         $html_block[$zaehler] .= $downloads;
      break;
      case 'nachueberschrift':
         $html_block[$zaehler]  = '';
         $html_block[$zaehler] .= $ueberschrift;
         $html_block[$zaehler] .= $bild;
         $html_block[$zaehler] .= $teasertext;
         $html_block[$zaehler] .= $video;
         $html_block[$zaehler] .= $text;
         $html_block[$zaehler] .= $link;
         $html_block[$zaehler] .= $downloads;
      break;
      case 'nachteaser':
         $html_block[$zaehler]  = '';
         $html_block[$zaehler] .= $ueberschrift;
         $html_block[$zaehler] .= $teasertext;
         $html_block[$zaehler] .= $bild;
         $html_block[$zaehler] .= $video;
         $html_block[$zaehler] .= $text;
         $html_block[$zaehler] .= $link;
         $html_block[$zaehler] .= $downloads;
      break;
      default:
         $html_block[$zaehler]  = '';
         $html_block[$zaehler] .= $ueberschrift;
         $html_block[$zaehler] .= $bild;
         $html_block[$zaehler] .= $teasertext;
         $html_block[$zaehler] .= $video;
         $html_block[$zaehler] .= $text;
         $html_block[$zaehler] .= $link;
         $html_block[$zaehler] .= $downloads;

      break;
    }
  }
}




// HTML

switch ($grid) {
  case '12':
    $out .= '
      <div class="col-xs-12 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>'.PHP_EOL;
  break;
  case '6_6':
    $out .= '
      <div class="col-xs-12 col-sm-6 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>
      <div class="col-xs-12 col-sm-6 '.$individuelle_css_klasse[2].'" '.$individuelle_css_id[2].'">
        '.$html_block[2].'
      </div>'.PHP_EOL;
  break;
  case '4_4_4':
    $out .= '
      <div class="col-xs-12 col-sm-4 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>
      <div class="col-xs-12 col-sm-4 '.$individuelle_css_klasse[2].'" '.$individuelle_css_id[2].'">
        '.$html_block[2].'
      </div>
      <div class="col-xs-12 col-sm-4 '.$individuelle_css_klasse[3].'" '.$individuelle_css_id[3].'">
        '.$html_block[3].'
      </div>'.PHP_EOL;
  break;
  case '3_3_3_3':
    $out .= '
      <div class="col-xs-12 col-sm-6 col-md-3 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>
      <div class="col-xs-12 col-sm-6 col-md-3 '.$individuelle_css_klasse[2].'" '.$individuelle_css_id[2].'">
        '.$html_block[2].'
      </div>
      <div class="col-xs-12 col-sm-6 col-md-3 '.$individuelle_css_klasse[3].'" '.$individuelle_css_id[3].'">
        '.$html_block[3].'
      </div>
      <div class="col-xs-12 col-sm-6 col-md-3 '.$individuelle_css_klasse[4].'" '.$individuelle_css_id[4].'">
        '.$html_block[4].'
      </div>'.PHP_EOL;
  break;

  case '6_3_3':
    $out .= '
      <div class="col-xs-12 col-sm-6 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>
      <div class="col-xs-12 col-sm-3 '.$individuelle_css_klasse[2].'" '.$individuelle_css_id[2].'">
        '.$html_block[2].'
      </div>
      <div class="col-xs-12 col-sm-3 '.$individuelle_css_klasse[3].'" '.$individuelle_css_id[3].'">
        '.$html_block[3].'
      </div>'.PHP_EOL;
  break;


  case '3_6_3':
    $out .= '
      <div class="col-xs-12 col-sm-3 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>
      <div class="col-xs-12 col-sm-6 '.$individuelle_css_klasse[2].'" '.$individuelle_css_id[2].'">
        '.$html_block[2].'
      </div>
      <div class="col-xs-12 col-sm-3 '.$individuelle_css_klasse[3].'" '.$individuelle_css_id[3].'">
        '.$html_block[3].'
      </div>'.PHP_EOL;
  break;

  case '3_3_6':
    $out .= '
      <div class="col-xs-12 col-sm-3 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>
      <div class="col-xs-12 col-sm-3 '.$individuelle_css_klasse[2].'" '.$individuelle_css_id[2].'">
        '.$html_block[2].'
      </div>
      <div class="col-xs-12 col-sm-6 '.$individuelle_css_klasse[3].'" '.$individuelle_css_id[3].'">
        '.$html_block[3].'
      </div>'.PHP_EOL;
  break;
  case '8_4':
    $out .= '
      <div class="col-xs-12 col-sm-8 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>
      <div class="col-xs-12 col-sm-4 '.$individuelle_css_klasse[2].'" '.$individuelle_css_id[2].'">
        '.$html_block[2].'
      </div>'.PHP_EOL;
  break;
  case '4_8':
    $out .= '
      <div class="col-xs-12 col-sm-4 '.$individuelle_css_klasse[1].'" '.$individuelle_css_id[1].'">
        '.$html_block[1].'
      </div>
      <div class="col-xs-12 col-sm-8 '.$individuelle_css_klasse[2].'" '.$individuelle_css_id[2].'">
        '.$html_block[2].'
      </div>'.PHP_EOL;
  break;
}

if(rex::isBackend()) {


echo '
  <div class="form-horizontal output">'.PHP_EOL;
  echo $outback;
  echo '
    <h2 class="weitere_einstellungen">Weitere Einstellungen</h2>

    <div class="form-group">
      <label class="col-sm-3 control-label">Raster</label>
      <div class="col-sm-9">
        <div class="gridimage img'.$grid.'"></div>
      </div>
    </div>'.PHP_EOL;

  if ($individuelle_css_id_container !='') {
    echo '
      <div class="form-group">
        <label class="col-sm-3 control-label">Individuelle Conatiner CSS ID</label>
        <div class="col-sm-9">
           '.$individuelle_css_id_container.'
        </div>
      </div>'.PHP_EOL;
  }

  if ($individuelle_css_klasse_container !='') {
    echo '
      <div class="form-group">
        <label class="col-sm-3 control-label">Individuelle Conatiner CSS Klasse</label>
        <div class="col-sm-9">
           '.$individuelle_css_klasse_container.'
        </div>
      </div>'.PHP_EOL;
  }

  if ($mediamanagertyp != 'standard') {
    echo '
      <div class="form-group">
        <label class="col-sm-3 control-label">Media Manager Typ</label>
        <div class="col-sm-9">
          '.$mediamanagertyp.'
        </div>
      </div>'.PHP_EOL;
  }

  echo '
  </div>'.PHP_EOL;

} else {

  if ($individuelle_css_id_container !='') {
    $individuelle_css_id_container = 'id="'.$individuelle_css_id_container.'"1';
  }

  echo  '
    <div '.$individuelle_css_id_container.' class="container-fluid '.$individuelle_css_klasse_container.'">
      <div class="container">
        <div class="row">
          '.$out.'
        </div>
      </div>
   </div>
  '.PHP_EOL;

}

if(rex::isBackend()) {

echo '
<style>
 @media (max-width:767px) {
  .output .control-label {
    margin-left: 10px;
    color: #a5abb1
  }
  .output .col-sm-9 {
    padding-left: 25px;
  }
}

.warning {
  color: #f00;
}

.bereichswrapper {
  margin: 5px 0 20px 0;
  background: #f5f5f5;
  padding: 0 15px 30px 15px;
  border: 1px solid #9da6b2;
}

.control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

.output h2 {
  font-size: 12px !important;
  padding: 10px 10px 5px 10px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

.output h2.weitere_einstellungen {
  margin: 15px 0 30px 0;
}

.output h3 {
  font-size: 12px !important;
  padding: 5px 5px 5px 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

.output .col-sm-9 img {
    margin-top: 4px;
}

.gridimage {
  width: 340px;
  height: 60px;
  border: 1px solid #ccc;
  margin: 0 0 8px 0;
}

.img12 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAQ9JREFUeNrs3TEKgzAYgNFagpuDBxC8/3HcBVcRXAQRQVJPYIcWapr3BpdAhh8+IoikiDE+gPw8jQDED4gfED8gfkD8gPgB8QPiB+4tXC8vy2JGkKiqqpz8gPgB8YP4AfED4gfED4gfED8gfkD8gPgB8QN/Gv84jsMwGCjkFf9xHH3fix8SEj7fYl3Xs/x9300TMoq/67p5ns0Rsou/ruuyLM/X/mmaTBMyir9pmvO5bZv4IS0+9YH4AfED4gfED/yR8J1dQmjb1jQhIUWM8WLZjT2QLjf2AOIHxA/iB8QPiB8QPyB+QPyA+AHxA+IHxA/czpu/+gAnPyB+QPyA+AHxA+IHxA+IHxA/8BMvAQYAX1c3Eu5IAT8AAAAASUVORK5CYII=);
}
.img6_6 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAgxJREFUeNrs3c1LInEYwPFNByl8icyLLMogXjr1L/T/gxcPZaJS3VJ8QaEXLd3f7sCyl929LLjM7/M5xGjQ4Zn5No+UeHI4HL4A8SkYAYgfED8gfkD8gPgB8QPiB8QP/N+SP397s9mYUZ5Uq1Wn2+l25wdrPyB+QPyA+AHxA+IHxA+IHxA/IH5A/ID4gaNJ/tUPen5+fn19TdPUTPPt/f19Pp9vt9tKpVKv1wsF94+44//8/ByPx+GCEH++zWazu7u7/X6fPTw7O7u+vj49PTWZSNf+l5eX29vbUL5p5ttutxsMBqH8TqcTmq/VamHXGw6HJhPpnb/f7y8WC3OMQdj2w4oXVv12u/390kmSXq+3XC5NJtL4Ly4uSqVSuCbCQmia+RbOctjzLy8vs4fZpzyGXwEmE2n8rVYrfH17exN/7n39ITv++PgYjUbhoNFomEyk8ROh1Wp1f38fXvCXy+Xw+t9AxE8UHh4eHh8fw87fbDa73W6xWDQT8ZN/k8nk6ekpBH91dWXhFz8Rbfuh/HCQpmmpVFqv19nztVrNcMRPnk2n0+xgPB7/+vzNzY3hxBt/kiT+ty/3zs/Pww3fHHLjJPtr7e/4CJec8Yk9TvdP3pUBkRI/iB8QPyB+QPyA+AHxA+IHxA+IHxA/IH7guP7yrj7AnR8QPyB+QPyA+AHxA+IHxA+IHziKbwIMAO4pnqqPCpuHAAAAAElFTkSuQmCC);
}
.img4_4_4 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAvdJREFUeNrs3VtLomsYBuDRpJTMNtqOqYgKKhD6C/1/6CQiozRWUtDWon3ZZp7pgw4Wi1mjGTnMdR2En0EHd+/9vc9rG1Ovr6/fgL9PWgSg/IDyA8oPKD+g/IDyA8oPKD/Q3TK//vTV1ZWMftPAwIAkJfkHJWnnB2M/oPyA8gPKDyg/oPyA8gPKDyg/oPyA8gPKD3yBTKe+0NHR0d3d3ezsrEzb9vDwcHZ29vj4mM/nR0ZG0mm35jbd3t6en5+/vLwMDw9HmAL5xPI/Pz/XarVYtcrftpOTk0qlEus1uczlcisrK9lsVjKt2t/fj9X4/m40ExMTS0tLYvmUsT/uspubm9F8abat2WxubW1F8+fm5qLzhUIhxqjt7W3JtOr+/j6aH0PT8vJyuVzu6+s7PDw8PT2VTOd3/vX19UajIccPimk/pqcY9WdmZn5+VzKZtbW1GFwl06pYjbHnx24/Pj4el5eXl/V6/ebmplQqCafD5Y8zVW9vbyzcmFql+ZFzU8z5xWIxuUxG1rgFSKZVY2NjcQ9Noot5KrmBxjOS6Xz5p6enk1lL+T/i+5vk8dPTU7VajQc2q3YW9Jt48M+b5Mz/6/9m5cxPV7i4uIiBP4bV/v7+OP8LpG1DQ0OxM8VYGmf+5C5Ah3d+OijW6N7eXsz8k5OTCwsLPT09MmlVHO+vr6/z+fzQm8HBwY2NjYODAz+HsvN3r93d3Sh/Op0ul8uLi4ua3/boVKlU6vV6cplKpeLj+w9QsfN345JN1mtsUDGpxtifPF8oFITTkmKxWK1Wj4+PI7pcLler1eLJ0dFRySh/l4rFmjxIFuu71dVV4bQkm83Oz89HjDs7O8kzcQTw6sknlj+TyThTfUQcTWPDl0NHTE1NlUqlRqPRbDZj/4+TfzL88y+p99+C/E/eHeX3eZ8ZSf5ZSXrBD/5Syg/KDyg/oPyA8gPKDyg/oPyA8gPKDyg/oPzA1/qfv+oD7PyA8gPKDyg/oPyA8gPKDyg/oPzAl/ghwAAFHxBk8znuiwAAAABJRU5ErkJggg==);
}
.img3_3_3_3 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAA3FJREFUeNrs3dtLKlEYxuEUcbLMrKzpokIsIkHoJui2P737LgoL6STZCTpoiZnmdLCXWTJ0sWtDBO291u+5kJwg+Fzzzvq+nDLW7/eHALgnzksAEH4AhB8A4QdA+AEQfgCEHwDhB0D4AfzbEl9/++HhwcqyPc9LJpOffTcIgl6vZ2XhY2NjLDfLzc4P0PYDIPwACD8Awg+A8AMg/AAIPwDCD4DwAyD8AAg/AMIP4NckfuoHXV9fd7vdfD7vzmvXaDTa7XYikZiYmBgZGXGk6k6nc39///b2pqrT6bRTaVHV5+fn/X7fjvP8Z8L/+vparVaDIHAk/Kp3d3e32WxGR/Ih6wu/uLjQQkcf9DI7O7uysuJO+E9OThR+s9y0/YOtoFKpKPnunASnp6dKvva91dXVpaWlWCxWq9VarZbdVT89PSn58Xi8WCyWSiXP866urur1uiOLrn7HJJ+2f6BcLt/d3bk2LN3c3OhxeXk5k8mo+9VpoRFAj3pqcdVaaO352u1939dTXezOzs4eHx9zuZz1K/7y8nJwcDA6Oqp6Cf+ATv1kMqk2+Pb21p3wa6tPpVJR1E0brOHf7qpnZmYmJydNmc/Pz7rY6QsdcWHFDw8Pe73e2tra1tYW4R+Yn583DaFT4V9fX//YBWhL1OVgamrK7qoTIX1RC5mZ/+t/FGVNoyeFQkE7v0118Vbf96nfOT4+rlQqSr4m/+HhYUcKz2azuuir49PMb64CFtOGf3R0ND4+bvY5Zn4Mdbvdvb09TYDKvIZ/F7pfFdtut9PpdDakPOgVuLy8tPttjmazqRnHvL8THSyXy3Nzc//7ohP+79CYs7Ozoz1BrX6xWLR+2o9ioD3Q932VbH7xMRS+9e1C7brqfXyqQc/81pPwO2d/f1/J1wS4sLDQ6XTMQS9kcdW60mnM0fSbyWRSqVS1WtXB6elpu9faD0VPNzc39bixsUHb76IgCMztPWqDt7e3o+PW3+ejAWdxcVGZ1/5vjmgEKBQKnBJOh199rzs39n52d6fGYOtr16Cby+XU9GoM1v6vkk3z7w6bzvNYdKvmH/ERLpbhE3tY7ghv9QGOIvwA4QdA+AEQfgCEHwDhB0D4ARB+AIQfAOEHQPgBEH4Av+svf9UHgJ0fAOEHQPgBEH4AhB8A4QdA+AEQfgCEH8CveBdgACF2bQzem2woAAAAAElFTkSuQmCC);
}
.img6_3_3 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAvtJREFUeNrs3W1LIlEYgGE1HdNqQktCF0UlhEAwoh/QT/cH6AcVVERT+xCYmG9TvmtPnV1ZWHI3dsHlzH19GHSDhaNzzzw6xTg3m40DgP24eAkA4gdA/ACIHwDxAyB+AMQPgPgBED+A/5t794/H4zGvkU5OTk5s+HZ7vV7DMD776Xw+n81mNny7OfMDjP0AiB8A8QMgfgDED4D4ARA/AOIHQPwAiB8A8QMgfgB74P5X/1Gn05lMJvF4nNdUb7PZrNfrzefz4+PjYDDoctni/LFer5+fny3L8vv9Z2dnBwcHxP/darVqNBqyQxC/3rrdbqVSkRLUU5/Pl8lkDg8P9V617NiFQuHl5UU9NQwjnU6bpsnY73h9fS2Xy/IC0YbeFotFtVqV8pPJpDQve7/MerVaTfuFN5tNKT8UCl1fX0ciEdnV9Vj13575i8WijEOEYQcy7cuIJ6N+LBZ733Xc7nw+3+/37bBw2aZSKY/HI4e8x8fH7RRg6/gDgYBMQbJPyEBIHnqTd1nmfPnEq56quzzKIUD7hd/c3MhWypft09OTbOUISPyOaDQq2+l0Svza+/ZBPV4ul/V6XR6cn59rv/DtlxrZbFYdBRKJhAbr4lIfvmwwGMjAPxqNjo6O5PO/fRYej8dl8FksFqVSSYMvudzsyviSVqvVbrdl5g+Hw5eXl3pc9Nqt0+nI9uLiQl3MyuVylmXJqLudg4gf+ru/v394eJDgr66u7DDwK/IBR872pmn6fD556nQ6HR9X/hn7YaNpX8pX069hGKMftF+4OsxVq9V+v99sNsfjsfSvwbGPMz/+lPqiWzQajZ///e7uTu+FJxIJOcYNh8NCoaDO/PJ5R00BxP9+vYff7dPe6enpjltfaExWfXt7q369Vx4Hg0Gv16vBupzqau1nuGOPZrhjz6+4Yw8AeyF+gPgBED8A4gdA/ACIHwDxAyB+AMQPgPgBED8A4gewX7/5qz4AnPkBED8A4gdA/ACIHwDxAyB+AMQPgPgB7MWbAAMARkEV6b+++m4AAAAASUVORK5CYII=);
}
.img3_6_3 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAvRJREFUeNrs3WtLIlEcgHFdbbykYl4IkmQEEQRBCaGv7wcQvCIRifpGMPF+Gccw97+eRXpRuxALW2ee34uhLVgY5zxzzmnc1X08Hl0AnOcHLwFA/ACIHwDxAyB+AMQPgPgBED8A4gfwtXn//OPVaqXlaft8PsMwPvrpfr+3bZvBweX+7sLhMDM/AOIHQPwA8QMgfgDED4D4ARA/AOIHQPwAiB8A8QMgfgBfi/df/UWj0ciyLNM0nfPaTSaT9Xrt9Xqvrq6CwSCDSWOvr6/T6VQut1zoeDzu8XiI/7fD4dDtdvf7vUPil/NttVrz+fz8HfOESLQkA7vRaGw2G/VHwzAKhUIkEmHZ79put51OR14g54yGwWAg5YdCoWKxmM1m3W53v99fLpd0oqVeryflJ5PJUql0c3MjQ/3x8ZGZ39VsNmU55LTR8Pz8LMdcLie3f1nzz2Yz2QLIUYPZAO/u79Tlvri4kEs8HA7PqwBHxy9DX1ZBsgwej8fOGQ0y1QcCgXPq6vMOZfNPJ1q6u7uTo5R/vu/HYjHid93e3spxt9s5Kv77+/u3qwBZ+8jtIB6P04mW/H6/+qJSqai7QCaT0eC8eNT3ebLeeXp66nQ6Ur7s/M9DBLoyTVNu8S8vL61WS4NfcrFS/STLstrttuz9pHnZDeqxDsS7RqORHK+vr9UDnWq1ul6vZambSqWI33Fkm1Ov123blnkgn8+z29ebrO9kto9EIoFAwHX6jY/r9OSfZb8TPTw8SPmXl5fpdHq73S5P+N++dZVIJNRFn81mvV5vtVpJ/+qbzPzOIps99fYeWfPXarW3G0Le56OlTCYjN/fFYtFoNNTMn81m1SqA+H895XLOuD8ej++ebDQapRMtGYZRLpfV23vl61gs5vP5NDgvt3pG/RE+sQdc7u+LT+wBQPwAiB8gfgDED4D4ARA/AOIHQPwAiB8A8QMgfgDED+DL+cu/6gPAzA+A+AEQPwDiB0D8AIgfAPEDIH4AxA/gv/gpwAAthiJ8l+WEIQAAAABJRU5ErkJggg==);
}
.img3_3_6 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAwRJREFUeNrs3V9LInEUxvFVBifNzNTMCw2pCAPBG6H3/woUCw1KUCkoK5M0/4ykPTgge9G2Nwu1c76fC9ERgjMzz5zfoakJrVarXwDsCbMLAMIPgPADIPwACD8Awg+A8AMg/AAIP4Cfzfn669FoFMiyXdeNRCJ/+tbzvPl8HsjCd3Z2DB5us74+3HR+gGU/AMIPgPADIPwACD8Awg+A8AMg/AAIPwDCD4DwAyD8AL6B869+0MPDw3Q6LRaLdvbd8/PzeDx2HGdvby8WixmpejKZvLy8LJdLVR2Px4mQ9fC/v7+3223P84yEX/VeXFwMh8PNluJa4Au/vb3Vgd486CWXy5VKJVJkd9mvVtBsNpV8O3ut2+0q+ep7lUrl5OQkFAp1Op3X19dgVz2bzZT8cDh8dnZWLpdd172/v396eiJFRjt/o9EYDAbW9lq/39fr6elpIpHQ6lfLYI0AetXHAFetA62er25/cHCgj7rY9Xq9t7e3TCZDkCyGX6d+JBLRMvjx8dHOXlOrj0ajm6j7y2AN/8GuOpvNplIpv8zFYqGLnd5oCykyGv5CoeAvCE2F//z8/PdVgFqiLgfpdDrg58qa3nTW/Jn/638UhYDP/GZpvXNzc9NsNpV8Tf5bW1tGCk8mk7roa8Wnmd+/CsBi5zdrOp1eXl5q4lXmNfxbWP2q2PF4HI/Hk2u7u7vaA3d3d6Z+v0vnt05jTr1eVxi01K9Wq0bm3uFw2Gq1er2e/1HrHb0ul0vOBzq/IVdXV/P5fHt7+/DwcDKZ+BvdtQBXrSudxpx+v59IJKLRaLvd1sb9/X3OB8Jvhed5/u096vy1Wm2zPfD3+WjAOT4+Vuavr6/9LRoBjo6OOCVMh99xHDuD32q1+rRYjcGBrz2fz2cymcFgsFgs1P9Vsr/4x/8otLlV81M8sSdgeGKPKTyxBwDhB0D4AcIPgPADIPwACD8Awg+A8AMg/AAIPwDCD4DwA/hx/vJXfQDo/AAIPwDCD4DwAyD8AAg/AMIPgPADIPwAvsWHAAMARlAaCQUVROkAAAAASUVORK5CYII=);
}
.img8_4 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAg1JREFUeNrs3c9LInEYwOFNB0k0I+siiyLipVP/Qv8/dPGgJY6oNxVLErS0cr+7c9nL/jiYI/k8BxkVOrzMp3mlZE622+034PhkjADED4gfED8gfkD8gPgB8QPiBw5b9Pe3F4uFGbFnZ2dnzsk9TNKVH6z9gPgB8QPiB8QPiB8QPyB+QPyA+AHxA+IHUhDt6geNx+PValWv182U1L2+vs5ms/V6XSwWy+VyJuMi92nxv7+/x3EcZi1+UjedTjudzsfHR/I0n8/f3Nycnp6azO7X/uVy2W63Q/mmSeo2m839/X0ov9FohOZLpVJYSLvdrsns/srfarUeHx/NkQMRtv2wh4ZVv1ar/Ty/o+ju7u7p6clkdh//xcVFLpcL4w67lmmSunAqhj3/8vIyeZrcijL8CjCZ3cdfrVbD48vLi/g5BN9/SY7f3t56vV44uLq6Mpndxw+HaT6fPzw8hA/8hUIhfP43EPFzFAaDwXA4DDt/pVJpNpvZbNZMxM/X1+/3R6NRCP76+trCL36OaNsP5YeDer2ey+Wen5+T10ulkuGIn69sMpkkB3Ec//767e2t4XxK/FEU+d8+DsH5+Xm44JvD/zhJ/hD6J+6Owv65Y89+JukLD3CkxA/iB8QPiB8QPyB+QPyA+AHxA+IHxA+IH0jXP77VB7jyA+IHxA+IHxA/IH5A/ID4AfEDqfghwAD6BZ6qshTg0AAAAABJRU5ErkJggg==);
}
.img4_8 {
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAVQAAAA8CAIAAAC2INVhAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAhBJREFUeNrs3U9LInEcwOFNBzEypfIiizKEl069Bd8/ePFgJY1YtxQ1Evrj3/3tzmUvuxsZ25TPc4jRoMO3+ThfKZm9zWbzDdg9OSMA8QPiB8QPiB8QPyB+QPyA+IFsi/7+7dlsZkavdHh4aJJ8onPSlR+s/YD4AfED4gfED4gfED8gfkD8gPgB8QPiBz5A9F4/6O7u7unpKY5jM32zl5eX8Xg8n89LpdLx8XEu56WZzMe/Wq2SJAlnrfjfbDQaXVxcrNfr9OH+/v75+XmxWDQZsrv2Pz4+drvdUL5pvtlisbi8vAzln56ehubL5XJYo3q9nsmQ3St/p9OZTCbmuKWw7YftKaz6jUbj528litrt9nQ6NRmyG//R0VGhUAgnbthaTXOb901hzz85OUkfpjdQDC8BJkN246/X6+Hr8/Oz+Lfx/Zf0eLlcXl9fh4NqtWoyZDd+3tf9/f3V1VV4w39wcBDe/xsI4t8Jg8Hg5uYm7Py1Wq3ZbObzeTNB/F9fv9+/vb0NwZ+dnVn4Ef8Obfuh/HAQx3GhUHh4eEifL5fLhoP4v7LhcJgeJEny+/OtVstwyHT8URT5375tVCqVcME3B/6nvfRPyn/iPjOv5449fK5z0kdHYEeJH8QPiB8QPyB+QPyA+AHxA+IHxA+IHxA/8LH+8ak+wJUfED8gfkD8gPgB8QPiB8QPiB/4ED8EGADiTZ6qytwGIAAAAABJRU5ErkJggg==);
}
</style>'.PHP_EOL;
}

