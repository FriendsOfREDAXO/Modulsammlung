<?php
if(!rex::isBackend()) {
  $art = rex_article::get("REX_LINK[id=1]");
  $content = new rex_article_content;
  $content->setArticleID($art->getId());
  if("REX_VALUE[2]" == 'nein') {
    echo $content->getArticle();
  } else {
    echo $content->getArticleTemplate();
  }
} else {
 echo '
  <div id="artikel_einbinden" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Artikel einbinden</h2>
     ';

      echo '<div class="form-group">
             <label class="col-sm-3 control-label">Artikel</label>
             <div class="col-sm-9">';
      if("REX_LINK[id=1]" != '') {
        echo '<a href="index.php?page=content&article_id=REX_LINK[id=1 output=id]">REX_LINK[id=1 output=name]</a>';
      } else {
        echo '<p class="warning"><b>ACHTUNG:</b><br/>Sie müssen einen Artikel angeben!</p>';
      }
      echo ' </div>
           </div>
      <div class="form-group">
             <label class="col-sm-3 control-label">Template mit einbinden</label>
             <div class="col-sm-9">';
      if("REX_VALUE[2]" == 'nein') {
        echo 'nein';
      } else {
        echo 'ja';
      }
      echo ' </div>
           </div>
        </div>
      </div>

<style>
#artikel_einbinden .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#artikel_einbinden .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#artikel_einbinden  h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

#artikel_einbinden .warning {
    color: #f00;
}
</style>'.PHP_EOL;
}
