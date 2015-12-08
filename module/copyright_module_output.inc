<?php

$query = mysql_query("SELECT * FROM rex_media WHERE med_copyright != '' ORDER BY originalname");


$out = '<div class="container">
        <div class="copyrightlist">';
$out_back = '';

if($sql->getRows()) { // nicht 0!
    while($sql->hasNext()) {
        echo $sql->getValue('name');
        echo '<br>';
        $sql->next(); // nächster Eintrag laden.
    }
}




  if($query != null) {
    for($i=0; $i<mysql_num_rows($query); $i++) {
        $file=mysql_fetch_object($query);
        $filename   = $file->filename;
        $copyright  = $file->med_copyright;

      if (in_array( substr($filename, -3), array("jpg","png","gif"))) {
        $out .= '<div class="item">'.PHP_EOL;
        $out .= '<img src="'.$REX['HTDOCS_PATH'].'index.php?rex_img_type=bildercopyright&rex_img_file='.$filename.'" alt="'.$filename.'"/>'.PHP_EOL;
        $out .= '<div class="filename">'.$filename.'</div>'.PHP_EOL;
        $out .= '<div class="copyright">### Copyright ### '.$copyright.'</div>'.PHP_EOL;
        $out .= '</div>'.PHP_EOL;
      }
    }
  } else {
    echo 'FEHLER !!! Es konnten keine Daten gelesen werden.'.PHP_EOL;
  }

$out .= '</div></div>'.PHP_EOL;

if(!rex::isBackend()) {
  echo $out;
} else {
  echo $out_back;
}

?>


