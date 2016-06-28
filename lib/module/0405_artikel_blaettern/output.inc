<?php
if(!rex::isBackend()) {

  $output[]           = '';
  $prev               = 0;
  $next               = 0;
  $last               = 0;
  $divider = '<li> - </li>';
  $currentCategoryId  = rex_category::getCurrent()->getValue('id');
  $currentArtikelId   = rex_article::getCurrentId();

  $links = array();

  foreach($articles = rex_category::getCurrent()->getArticles(true) as $article) {
    if($article !== NULL) {
      $id = $article->getId();
      if($id == $currentArtikelId AND $id != $currentCategoryId) {
        $prev = $last;
        $article = new rex_article_content($last);
        $links[] = '<li><a id="zurueck" href="'.rex_getUrl($prev).'">'.$article->getValue('name').'</a></li>';
      }

      if($last == $currentArtikelId) {
        $next = $id;
        $article = new rex_article_content($next);
        $links[] = '<li><a id="weiter" href="'.rex_getUrl($next).'">'.$article->getValue('name').'</a></li>';
        break;
      }
      $last = $id;
    }
  }
  $output[] = '<ul>'.implode($divider, $links).'</ul>';
  echo implode($output);
} else {
  echo '
  <div id="artikelblaettern" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Artikel blättern</h2>
       <div class="form-group">
         <div class="col-sm-12 control-label">
           <p>Die Links werden im Frontend ausgegeben.</p>
         </div>
       </div>
    </div>
  </div>

<style>
#artikelblaettern .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#artikelblaettern .control-label {
  text-align: left;
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#artikelblaettern  h2 {
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
