<?php
$output_frontend   = array();
$output_backend    = array();
$download_be_dateien = '';
$download_fe_dateien = '';


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

if (!function_exists('parse_icon')) {
  function parse_icon($ext) {
    switch (strtolower($ext)) {
      case 'doc': return '<i class="fa fa-file-word-o"></i>&nbsp;';
      case 'pdf': return '<i class="fa fa-file-pdf-o"></i>&nbsp;';
      case 'zip': return '<i class="fa fa-archive-pdf-o"></i>&nbsp;';
      case 'jpg': return '<i class="fa fa-file-image-o"></i>&nbsp;';
      case 'png': return '<i class="fa fa-file-image-o"></i>&nbsp;';
      case 'gif': return '<i class="fa fa-file-image-o"></i>&nbsp;';
      default:
      return '';
    }
  }
}

if('REX_VALUE[1]' != '') {
  $output_frontend[] = '
     <div class="col-xs-12">
        <h3>REX_VALUE[1]</h3>
     </div>';

  $output_backend[] = '
    <div class="form-group">
       <label class="col-sm-3 control-label">Überschrift</label>
       <div class="col-sm-9">REX_VALUE[1]</div>
    </div>';
}

if('REX_VALUE[2]' != '') {
  $text = markitup::parseOutput ('textile', 'REX_VALUE[id=2 output="html"]');
  $output_backend[] = '
    <div class="form-group">
       <label class="col-sm-3 control-label">Text</label>
       <div class="col-sm-9">'.$text.'</div>
    </div>';
}

if ('REX_MEDIALIST[1]' !='') {
  $arr = explode(",",'REX_MEDIALIST[1]');

  foreach ($arr as $value_dl) {
    $extension = substr(strrchr($value_dl, '.'), 1);
    $parsed_icon = parse_icon($extension);
    $downloadmedia = rex_media::get($value_dl);
    $file_desc = $downloadmedia->getValue('med_description');

    $download_be_dateien .= $value_dl.'<br/>';

    $download_fe_dateien .='<li><a href="index.php?rex_media_type=download&rex_media_file='.$value_dl.'">'.$parsed_icon;

    if ($file_desc != "") {
      $download_fe_dateien .= $file_desc;
    } else {
      $download_fe_dateien .= $value_dl;
    }

    $download_fe_dateien .= ' ('.datei_groesse(rex_path::media($value_dl)).')</a></li>';
  }

  $output_backend[] .= '
    <div class="form-group">
      <label class="col-sm-3 control-label">Dateien</label>
      <div class="col-sm-9">'.$download_be_dateien.'</div>
    </div>'.PHP_EOL;
} else {
  $output_backend[] .= '
    <div class="form-group">
      <label class="col-sm-3 control-label">Dateien</label>
      <div class="col-sm-9 warning"><b>ACHTUNG:</b><br/>Sie haben keine Dateien für den Download angegeben. Das ist recht sinnfrei wenn dieses Modul benutzt wird!</div>
    </div>'.PHP_EOL;
}

$output_frontend[] = '
    <div class="col-xs-12 col-sm-6">
      '.$text.'
    </div>
    <div class="col-xs-12 col-sm-6">
      <ul>'.$download_fe_dateien.'</ul>
    </div>';



if(!rex::isBackend()) {
  // Ausgabe Frontend
  echo '
  <div class="container">
    <div class="row">
      '.implode($output_frontend).'
    </div>
  </div>';

} else {
  // Ausgabe Backend
  echo '
  <div id="text_download" class="bereichswrapper">
    <div class="form-horizontal output">
      <h2 class="ueberschrift" >Text / Downloads</h2>
      '.implode($output_backend).'
    </div>
  </div>

  <style>
  #text_download .bereichswrapper {
    margin: 5px 0 5px 0;
    background: #f5f5f5;
    padding: 5px 15px 5px 15px;
    border: 1px solid #9da6b2;
  }

  #text_download .control-label {
    font-weight: normal;
    font-size: 12px;
    margin-top: -6px;
  }

  #text_download h2.ueberschrift {
    font-size: 12px !important;
    padding: 0 10px 10px 10px;
    margin-bottom: 15px;
    width: 100%;
    font-weight: bold;
    border-bottom: 1px solid #31404F;
  }

  #text_download .warning {
    color: #f00;
  }


  </style>';
}
