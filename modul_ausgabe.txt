<?php

// Online Prüfung
$online = rex_var::toArray('REX_VALUE[20]');
$online_switch                   = $online[1];
$online_time                     = time();
$online_start                    = $online[2];
$online_end                      = $online[3];

$sonstiges = rex_var::toArray('REX_VALUE[13]');
$individuelle_css_klasse     = $sonstiges[1];
$imagemangertyp              = $sonstiges[2];

if ($imagemangertyp == '') {
  $imagemangertyp = '768';
}

  $msgonline = '
  <div class="rex-message"><div class="rex-info" style="font-size: 15px; font-weight: normal;"><p><span>Für diesen Inhalt ist ein in Veröffentlichungszeitraum angegeben ('.$online_start.' - '.$online_end.')<br/><b>Dieser Inhalt wird auf der Webseite angezeigt.</b><span></p></div></div>';

  $msgoffline = '
  <div class="rex-message"><div class="rex-warning" style="font-size: 15px; font-weight: normal;"><p><span>Für diesen Inhalt ist ein in Veröffentlichungszeitraum angegeben ('.$online_start.' - '.$online_end.')<br/><b>Dieser Inhalt wird momentan NICHT auf der Webseite angezeigt.</b><span></p></div></div>';

$outback = '
  <table style="width: 100%; background-color: #eee;" >
';

$out = '
  <div class="container with-inner">
    <div class="row">


';

// Vars BLOCK 1
$block1_text = rex_var::toArray('REX_VALUE[1]');
$block1_text_ueberschrift        = $block1_text[1];
$block1_text_ueberschrift_groesse= $block1_text[4];
$block1_text_kurztext            = $block1_text[2];
$block1_text_fliesstext          = $block1_text[3];

$block1_bild = rex_var::toArray('REX_VALUE[2]');
$block1_bild_datei               = "REX_FILE[1]";
$block1_bild_alt                 = $block1_bild[1];
$block1_bild_infos               = $block1_bild[2];
$block1_bild_position            = $block1_bild[3];
$block1_bild_anpassen            = $block1_bild[4];

$block1_link = rex_var::toArray('REX_VALUE[3]');
$block1_link_extern              = $block1_link[1];
$block1_link_intern              = "REX_LINK_ID[1]";
$block1_link_bezeichnung         = $block1_link[2];
$block1_link_ueberschrift        = $block1_link[3];
$block1_link_modal             = "REX_LINK_ID[5]";

// Vars BLOCK 2
$block2_text = rex_var::toArray('REX_VALUE[4]');
$block2_text_ueberschrift        = $block2_text[1];
$block2_text_ueberschrift_groesse= $block2_text[4];
$block2_text_kurztext            = $block2_text[2];
$block2_text_fliesstext          = $block2_text[3];

$block2_bild = rex_var::toArray('REX_VALUE[5]');
$block2_bild_datei               = "REX_FILE[2]";
$block2_bild_alt                 = $block2_bild[1];
$block2_bild_infos               = $block2_bild[2];
$block2_bild_position            = $block2_bild[3];
$block2_bild_anpassen            = $block2_bild[4];

$block2_link = rex_var::toArray('REX_VALUE[6]');
$block2_link_extern              = $block2_link[1];
$block2_link_intern              = "REX_LINK_ID[2]";
$block2_link_bezeichnung         = $block2_link[2];
$block2_link_ueberschrift        = $block2_link[3];
$block2_link_modal             = "REX_LINK_ID[6]";

// Vars BLOCK 3
$block3_text = rex_var::toArray('REX_VALUE[7]');
$block3_text_ueberschrift        = $block3_text[1];
$block3_text_ueberschrift_groesse= $block3_text[4];
$block3_text_kurztext            = $block3_text[2];
$block3_text_fliesstext          = $block3_text[3];

$block3_bild = rex_var::toArray('REX_VALUE[8]');
$block3_bild_datei               = "REX_FILE[3]";
$block3_bild_alt                 = $block3_bild[1];
$block3_bild_infos               = $block3_bild[2];
$block3_bild_position            = $block3_bild[3];
$block3_bild_anpassen            = $block3_bild[4];

$block3_link = rex_var::toArray('REX_VALUE[9]');
$block3_link_extern              = $block3_link[1];
$block3_link_intern              = "REX_LINK_ID[3]";
$block3_link_bezeichnung         = $block3_link[2];
$block3_link_ueberschrift        = $block3_link[3];
$block3_link_modal             = "REX_LINK_ID[7]";

// Vars BLOCK 4
$block4_text = rex_var::toArray('REX_VALUE[10]');
$block4_text_ueberschrift        = $block4_text[1];
$block4_text_ueberschrift_groesse= $block4_text[4];
$block4_text_kurztext            = $block4_text[2];
$block4_text_fliesstext          = $block4_text[3];

$block4_bild = rex_var::toArray('REX_VALUE[11]');
$block4_bild_datei               = "REX_FILE[4]";
$block4_bild_alt                 = $block4_bild[1];
$block4_bild_infos               = $block4_bild[2];
$block4_bild_position            = $block4_bild[3];
$block4_bild_anpassen            = $block4_bild[4];

$block4_link = rex_var::toArray('REX_VALUE[12]');
$block4_link_extern              = $block4_link[1];
$block4_link_intern              = "REX_LINK_ID[4]";
$block4_link_bezeichnung         = $block4_link[2];
$block4_link_ueberschrift        = $block4_link[3];
$block4_link_modal             = "REX_LINK_ID[8]";


for ($i=1; $i<=4; $i++)  {

// HTML Block

   ${'htmlblock'.$i} = '';
   ${'outblock'.$i} = '
      <tr>
      <td colspan="2" style="padding: 5px; font-size:16px;font-weight: bold; border-bottom: 2px solid #D9E1E4; border-top: 15px solid #D9E1E4;padding-left: 165px;">
        Bereich '.$i.'
      </td>
      </tr>
    ';



  // Kurztext
    if(${'block'.$i.'_text_kurztext'} !='' ) { // Text
      ${'kurztext'.$i} = htmlspecialchars_decode(${'block'.$i.'_text_kurztext'},ENT_QUOTES);
      ${'kurztext'.$i} = str_replace('<br />','', ${'kurztext'.$i});
      ${'kurztext'.$i}  = rex_a79_textile( ${'kurztext'.$i});

      $kurztext = '<div class="kurztext">'.${'kurztext'.$i}.'</div>'.PHP_EOL;
      $out_kurztext = '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Kurztext</td>
        <td style="padding: 5px;">'.${'kurztext'.$i}.'</td>
      </tr>
      ';
    } else {
      $kurztext = '';
      $out_kurztext = '';
    }



  // Fliesstext
    if(${'block'.$i.'_text_fliesstext'} !='' ) { // Text
      ${'fliesstext'.$i} = htmlspecialchars_decode(${'block'.$i.'_text_fliesstext'},ENT_QUOTES);
      ${'fliesstext'.$i} = str_replace('<br />','', ${'fliesstext'.$i});
      ${'fliesstext'.$i}  = rex_a79_textile( ${'fliesstext'.$i});


      $fliesstext = '<div class="fliesstext">'.${'fliesstext'.$i}.'</div>'.PHP_EOL;

      if (${'block'.$i.'_text_ueberschrift_groesse'} == "faq") {
      $fliesstext = '<div class="accordioninhalt">'.${'fliesstext'.$i}.'</div>'.PHP_EOL;
    }



      // ***

      $out_fliesstext = '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Fliesstext</td>
        <td style="padding: 5px;">'.${'fliesstext'.$i}.'</td>
      </tr>
      ';
    } else {
       $fliesstext = '';
       $out_fliesstext = '';
    }


    $linkanfang           = '';
    $linkende             = '';
    $out_linkextern       = '';
    $out_linkintern       = '';
    $out_linkbezeichnung  = '';
    $out_ueberschiftverlinkt  = '';

  if (${'block'.$i.'_link_intern'} != '') {
    $linkanfang = '<a href="'.rex_geturl(${'block'.$i.'_link_intern'}, $REX['CUR_CLANG']).'">';
    $linkende   = '</a>'.PHP_EOL;


    $article=OOArticle::getArticleById(${'block'.$i.'_link_intern'});
    $name=$article->getName();

    $out_linkintern = '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Interner Link</td>
        <td style="padding: 5px;"><a href="index.php?page=content&article_id=REX_LINK_ID[1]&mode=edit">'.$name.'</a></td>
      </tr>
      ';
  }

  if (${'block'.$i.'_link_extern'} !='') {

      if(${'block'.$i.'_link_extern'} != str_replace("http://", "",${'block'.$i.'_link_extern'})) {
        $linkanfang = '<a href="'.${'block'.$i.'_link_extern'}.'">';
      } else {
        $linkanfang = '<a href="http://'.${'block'.$i.'_link_extern'}.'">';
      }

      $out_linkextern = '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Externer Link</td>
        <td style="padding: 5px;">'.${'block'.$i.'_link_extern'}.'</td>
      </tr>
      ';

    $linkende   = '</a>'.PHP_EOL;
  }



  if (${'block'.$i.'_link_bezeichnung'}) {
    $textlink = $linkanfang.${'block'.$i.'_link_bezeichnung'}.$linkende;

      $out_linkbezeichnung = '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Link Bezeichnung</td>
        <td style="padding: 5px;">'.${'block'.$i.'_link_extern'}.'</td>
      </tr>
      ';

  } else {
    $textlink = '';
  }


  // Modal

  if (${'block'.$i.'_link_modal'}) {

    $Modalartikelid =  ${'block'.$i.'_link_modal'};
    $ModalArtikel = new rex_article;
      $ModalArtikel->setCLang($REX['CUR_CLANG']);
      $ModalArtikel->setArticleID($Modalartikelid);

  if (${'block'.$i.'_link_modal_bezeichnung'}) {
    $linkbezeichnung = ${'block'.$i.'_link_modal_bezeichnung'};

  } else {
    $linkbezeichnung = '###mehr###';
  }

    $article=OOArticle::getArticleById($Modalartikelid);
    $name=$article->getName();

    $modal = '<a href="'.rex_getUrl($Modalartikelid).'" class="boxer" >'.$linkbezeichnung.'</a>'.PHP_EOL;

    $out_link_modal = '
        <td style="padding: 5px; width: 150px; font-weight: bold;">Link zum Modalinhalt</td>
        <td style="padding: 5px;"><a href="index.php?page=content&article_id='.$Modalartikelid.'&mode=edit">'.$name.'</a></td>
      </tr>
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Modallink Bezeichnung</td>
        <td style="padding: 5px;">'.$linkbezeichnung.'</td>
      </tr>
      ';

  } else {
    $modal = '';
    $out_link_modal = '';
    $name = '';
  }



  // Ueberschrift
  if (${'block'.$i.'_text_ueberschrift'}  != '') {

      if (${'block'.$i.'_link_ueberschrift'}  == 'ja') {
        $ueberschrift = '<'.${'block'.$i.'_text_ueberschrift_groesse'}.' class="ueberschrift">'.$linkanfang.${'block'.$i.'_text_ueberschrift'}.$linkende.'</'.${'block'.$i.'_text_ueberschrift_groesse'}.'>'.PHP_EOL;
      } else {
        $ueberschrift = '<'.${'block'.$i.'_text_ueberschrift_groesse'}.' class="ueberschrift">'.${'block'.$i.'_text_ueberschrift'}.'</'.${'block'.$i.'_text_ueberschrift_groesse'}.'>'.PHP_EOL;
      }


      if (${'block'.$i.'_text_ueberschrift_groesse'} == "faq") {
      $ueberschrift = '<div class="accordionueberschrift" rel="REX_SLICE_ID" id="REX_SLICE_ID"><p>'.${'block'.$i.'_text_ueberschrift'}.'</p></div>'.PHP_EOL;
    }


      if (${'block'.$i.'_text_ueberschrift_groesse'} == "faq") {
        ${'block'.$i.'_text_ueberschrift_groesse'} = 'FAQ';
    }

      $out_ueberschrift = '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Überschrift</td>
        <td style="padding: 5px;">'.${'block'.$i.'_text_ueberschrift'}.'</td>
      </tr>
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Überschrift Grösse</td>
        <td style="padding: 5px;">'.${'block'.$i.'_text_ueberschrift_groesse'}.'</td>
      </tr>

      ';
  } else {
      $ueberschrift = '';
      $out_ueberschrift = '';
  }


  if (${'block'.$i.'_bild_datei'}) {

    $media        = OOMedia::getMediaByName(${'block'.$i.'_bild_datei'});
    $titel        = $media->getTitle();
    $beschreibung = $media->getDescription();
    $copyright    = $media->getCopyright();

    if (${'block'.$i.'_bild_anpassen'} == '') {
      $width = 'width="100%"';
    } else {
      $width = '';
    }

    ${'bild'.$i}  = '<img src="./files/'.${'block'.$i.'_bild_datei'}.'" alt="'.${'block'.$i.'_bild_alt'}.'" '.$width.' />';

  if($imagemangertyp !='') {
      ${'bild'.$i}  = '<img src="index.php?rex_img_type='.$imagemangertyp.'&amp;rex_img_file='.${'block'.$i.'_bild_datei'}.'" alt="'.${'block'.$i.'_bild_alt'}.'" '.$width.' />';
  }

    if ($titel != '' ) {
        $out_titel = $titel;
        $titel = '<p class="bildtitel">'.$titel.'</p>'.PHP_EOL;
    } else {
        $titel = '';
        $out_titel= '';
    }
    if ($beschreibung != '' ) {
        $out_beschreibung = $beschreibung;
        $beschreibung = '<p class="bildbeschreibung">'.$beschreibung.'</p>'.PHP_EOL;
    } else {
        $beschreibung = '';
        $out_beschreibung = '';
    }
    if ($copyright != '') {
        $out_copyright = $copyright;
        $copyright = '<p class="bildcopyright">'.$copyright.'</p>'.PHP_EOL;
    } else {
        $copyright = '';
        $out_copyright = '';
    }

    if (${'block'.$i.'_bild_infos'} == 'ja') {
      $bild = '<div class="bild">'.$linkanfang.${'bild'.$i}.$linkende.PHP_EOL;
      $bild .= $copyright;
      $bild .= $titel;
      $bild .= $beschreibung;
      $bild .= '</div>'.PHP_EOL;


      $out_bild = '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Bild</td>
        <td style="padding: 5px;"><img src="index.php?rex_img_type=rex_mediapool_detail&rex_img_file='.${'block'.$i.'_bild_datei'}.'" /></td>
      </tr>
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Bild Datei</td>
        <td style="padding: 5px;">'.${'block'.$i.'_bild_datei'}.'</td>
      </tr>
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Bild Titel</td>
        <td style="padding: 5px;">'.$out_titel.'</td>
      </tr>
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Bild Beschreibung</td>
        <td style="padding: 5px;">'.$out_beschreibung.'</td>
      </tr>
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Bild Copyright</td>
        <td style="padding: 5px;">'.$out_copyright.'</td>
      </tr>
      ';

    } else {
      $bild = '<div class="bild">'.$linkanfang.${'bild'.$i}.$linkende.'</div>'.PHP_EOL;

      $out_bild = '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Bild</td>
        <td style="padding: 5px;"><img src="index.php?rex_img_type=rex_mediapool_detail&rex_img_file='.${'block'.$i.'_bild_datei'}.'" /></td>
      </tr>
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Bild Datei</td>
        <td style="padding: 5px;">'.${'block'.$i.'_bild_datei'}.'</td>
      </tr>
      ';


    }

  } else {
      $bild = '';
      $out_bild = '';
  }


  switch(${'block'.$i.'_bild_position'})
      {
        case ("nachueberschrift"):
             ${'htmlblock'.$i} .= $ueberschrift;
             ${'htmlblock'.$i} .= $bild;
             ${'htmlblock'.$i} .= $kurztext;
             ${'htmlblock'.$i} .= $fliesstext;
             ${'htmlblock'.$i} .= $textlink;
             ${'htmlblock'.$i} .= $modal;

             ${'outblock'.$i} .= $out_ueberschrift;
             ${'outblock'.$i} .= $out_bild;
             ${'outblock'.$i} .= $out_kurztext;
             ${'outblock'.$i} .= $out_fliesstext;
             ${'outblock'.$i} .= $out_linkextern;
             ${'outblock'.$i} .= $out_linkintern;
             ${'outblock'.$i} .= $out_linkbezeichnung;
             ${'outblock'.$i} .= $out_link_modal;

        break;

        case ("nachteaser"):
             ${'htmlblock'.$i} .= $ueberschrift;
             ${'htmlblock'.$i} .= $kurztext;
             ${'htmlblock'.$i} .= $bild;
             ${'htmlblock'.$i} .= $fliesstext;
             ${'htmlblock'.$i} .= $textlink;
             ${'htmlblock'.$i} .= $modal;

             ${'outblock'.$i} .= $out_ueberschrift;
             ${'outblock'.$i} .= $out_kurztext;
             ${'outblock'.$i} .= $out_bild;
             ${'outblock'.$i} .= $out_fliesstext;
             ${'outblock'.$i} .= $out_linkextern;
             ${'outblock'.$i} .= $out_linkintern;
             ${'outblock'.$i} .= $out_linkbezeichnung;
             ${'outblock'.$i} .= $out_link_modal;

        break;

        case ("unten"):
             ${'htmlblock'.$i} .= $ueberschrift;
             ${'htmlblock'.$i} .= $kurztext;
             ${'htmlblock'.$i} .= $fliesstext;
             ${'htmlblock'.$i} .= $textlink;
             ${'htmlblock'.$i} .= $bild;
             ${'htmlblock'.$i} .= $modal;

             ${'outblock'.$i} .= $out_ueberschrift;
             ${'outblock'.$i} .= $out_kurztext;
             ${'outblock'.$i} .= $out_fliesstext;
             ${'outblock'.$i} .= $out_bild;
             ${'outblock'.$i} .= $out_linkextern;
             ${'outblock'.$i} .= $out_linkintern;
             ${'outblock'.$i} .= $out_linkbezeichnung;
             ${'outblock'.$i} .= $out_link_modal;

        break;

        default:
             ${'htmlblock'.$i} .= $bild;
             ${'htmlblock'.$i} .= $ueberschrift;
             ${'htmlblock'.$i} .= $kurztext;
             ${'htmlblock'.$i} .= $fliesstext;
             ${'htmlblock'.$i} .= $textlink;
             ${'htmlblock'.$i} .= $modal;


             ${'outblock'.$i} .= $out_bild;
             ${'outblock'.$i} .= $out_ueberschrift;
             ${'outblock'.$i} .= $out_kurztext;
             ${'outblock'.$i} .= $out_fliesstext;
             ${'outblock'.$i} .= $out_linkextern;
             ${'outblock'.$i} .= $out_linkintern;
             ${'outblock'.$i} .= $out_linkbezeichnung;
             ${'outblock'.$i} .= $out_link_modal;

        break;
  }

}


  // Bild


// HTML
if ('REX_VALUE[18]' == '12') {

  $out .= '
        <div class="col-xs-12 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $outback .= $outblock1;


} else if ('REX_VALUE[18]' == '6_6') {

  $out .= '
        <div class="col-xs-12 col-sm-6 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-6 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock2.'
            </div>
        </div>';

  $outback .= $outblock1;
  $outback .= $outblock2;

} else if ('REX_VALUE[18]' == '4_4_4') {

  $out .= '
        <div class="col-xs-12 col-sm-4 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-4 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock2.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-4 '.$individuelle_css_klasse.'">
              <div class="inner">
           '.$htmlblock3.'
            </div>
        </div>';

  $outback .= $outblock1;
  $outback .= $outblock2;
  $outback .= $outblock3;

} else if ('REX_VALUE[18]' == '3_3_3_3') {

  $out .= '
        <div class="col-xs-12 col-sm-6 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-6 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock2.'
            </div>
        </div>';

  $out.= '<div class="clearfix visible-sm"></div>';

  $out .= '
        <div class="col-xs-12 col-sm-6 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock3.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-6 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock4.'
            </div>
        </div>';

  $outback .= $outblock1;
  $outback .= $outblock2;
  $outback .= $outblock3;
  $outback .= $outblock4;

} else if ('REX_VALUE[18]' == '6_3_3') {

  $out .= '
        <div class="col-xs-12 col-sm-6 col-md-6 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-3 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock2.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-3 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock3.'
            </div>
        </div>';

  $outback .= $outblock1;
  $outback .= $outblock2;
  $outback .= $outblock3;

} else if ('REX_VALUE[18]' == '3_6_3') {

  $out .= '
        <div class="col-xs-12 col-sm-3 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-6 col-md-6 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock2.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-3 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock3.'
            </div>
        </div>';

  $outback .= $outblock1;
  $outback .= $outblock2;
  $outback .= $outblock3;

} else if ('REX_VALUE[18]' == '3_3_6') {

  $out .= '
        <div class="col-xs-12 col-sm-3 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-3 col-md-3 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock2.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-6 col-md-6 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock3.'
            </div>
        </div>';

  $outback .= $outblock1;
  $outback .= $outblock2;
  $outback .= $outblock3;


} else if ('REX_VALUE[18]' == '8_4') {

  $out .= '
        <div class="col-xs-12 col-sm-8 col-md-8 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-4 col-md-4 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock2.'
            </div>
        </div>';

  $outback .= $outblock1;
  $outback .= $outblock2;

} else if ('REX_VALUE[18]' == '4_8') {

  $out .= '
        <div class="col-xs-12 col-sm-4 col-md-4 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock1.'
            </div>
        </div>';

  $out .= '
        <div class="col-xs-12 col-sm-8 col-md-8 '.$individuelle_css_klasse.'">
          <div class="inner">
           '.$htmlblock2.'
            </div>
        </div>';

  $outback .= $outblock1;
  $outback .= $outblock2;

}
$out .= '
    </div>
  </div>
';


$outback .= '
  </table>
  ';


if(!$REX['REDAXO']) {
//
//  Frontend
//
if ($online_switch == "ja") {
  if( $online_time > strtotime($online_start) && $online_time < strtotime($online_end) ) {
    echo $out;
  }
} else {
    echo $out;
}

} else {

// Zeiteinstellung
if ($online_switch == "ja") {
  if( $online_time > strtotime($online_start) && $online_time < strtotime($online_end) ) {
    echo $msgonline;
  } else {
    echo $msgoffline;
  }
}

//
//  Backend
//

  echo $outback;

  echo '<table style="width: 100%;" >'.PHP_EOL;
  echo '<tr>'.PHP_EOL;
  echo '<td style="padding: 5px; width: 150px; font-weight: bold;">Anordung</td>'.PHP_EOL;
  echo '<td style="padding: 5px;"><img src="../files/addons/be_style/plugins/agk_skin_krol/REX_VALUE[18].png" /></td>'.PHP_EOL;
  echo '</tr>'.PHP_EOL;

  if ($individuelle_css_klasse !='') {
  echo '<tr>'.PHP_EOL;
  echo '<td style="padding: 5px; width: 150px; font-weight: bold;">Individuelle CSS Klasse</td>'.PHP_EOL;
  echo '<td style="padding: 5px;">'.$individuelle_css_klasse.'</td>'.PHP_EOL;
  echo '</tr>'.PHP_EOL;
  }
  if ($imagemangertyp !='') {
  echo '<tr>'.PHP_EOL;
  echo '<td style="padding: 5px; width: 150px; font-weight: bold;">Image Manager Typ</td>'.PHP_EOL;
  echo '<td style="padding: 5px;">'.$imagemangertyp.'</td>'.PHP_EOL;
  echo '</tr>'.PHP_EOL;
  }

  echo '</table>'.PHP_EOL;

}



?>



