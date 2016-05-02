<?php

$out = '<div class="container">
        <div class="copyrightlist">';

$sql = rex_sql::factory();
// $sql->setDebug();
$sql->setTable(rex::getTablePrefix().'media');
$sql->setWhere('med_copyright != "" AND med_no_copyright_out != "|true|"');
$sql->select();

if($sql->getRows()) {
    while($sql->hasNext()) {

        $filename   = $sql->getValue('filename');
        $copyright  = $sql->getValue('med_copyright');;

          if (in_array( substr($filename, -3), array("jpg","png","gif"))) {
            $out .= '<div class="item">'.PHP_EOL;
            $out .= '<img src="index.php?rex_media_type=bildercopyright&rex_media_file='.$filename.'" alt="'.$filename.'"/>'.PHP_EOL;
            $out .= '<div class="filename">'.$filename.'</div>'.PHP_EOL;
            $out .= '<div class="copyright">{{ Copyright }} '.$copyright.'</div>'.PHP_EOL;
            $out .= '</div>'.PHP_EOL;
          }
        $sql->next();
    }
}

$out .= '</div></div>'.PHP_EOL;

if(!rex::isBackend()) {
  echo $out;
} else {
  echo '
  <div id="copyright" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Alle Bilder mit aus dem Medienpool mit Copyright anzeigen</h2>
       <div class="form-group">
         <div class="col-sm-12 control-label">Alle Bilddateien (jpg,png,gif) im Medienpool deren Copyrightinfo ausgefüllt ist werden im Frontend ausgegeben. Ausnahmen bilden die Bilder bei denen im Medienpool das Feld "Nicht in der Copyrightliste ausgeben" aktiviert ist.</div>
       </div>
    </div>
  </div>

<style>
#copyright .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#copyright .control-label {
  text-align: left;
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#copyright  h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

</style>
';
}

?>
