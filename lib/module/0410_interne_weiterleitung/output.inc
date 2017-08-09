<?php
if(!rex::isBackend()) {
  if ('REX_LINK[id=1]' != '') {
    ob_end_clean();
      header("HTTP/1.1 301 Moved Permanently");
      header("Location: ".rex_geturl('REX_LINK[id=1]', rex_clang::getCurrentId()));
    exit;
  }
} else {
 echo '
  <div id="interne_weiterleitung" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Interne Weiterleitung</h2>
     ';

  echo '<div class="form-group">
         <label class="col-sm-3 control-label">Artikel</label>
         <div class="col-sm-9"><a href="index.php?page=content&article_id=REX_LINK[id=1 output=id]">REX_LINK[id=1 output=name]</a></div>
       </div>
    </div>
  </div>

<style>
#interne_weiterleitung .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#interne_weiterleitung .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#interne_weiterleitung  h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

</style>'.PHP_EOL;
}
