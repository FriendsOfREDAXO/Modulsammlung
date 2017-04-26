<?php

$articles = rex_category::getCurrent()->getArticles();

if (count($articles)) {
  $output[] = '<ul>';
    foreach ($articles as $article) {
      if ($article->getValue('status') != 0) { // Offline
        if ($article instanceof rex_article && !$article->isStartArticle()) {
            $output[] = '<li><a href="'.rex_geturl($article->getValue('id'), rex_clang::getCurrentId()).'">'.$article->getValue('name').'</a></li>';
        }
      }
    }
  $output[] = '</ul>';
}


if(!rex::isBackend()) {
  echo implode('',$output);
} else {
  echo '
  <div id="artikelliste" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Artikelliste</h2>
       <div class="form-group">
         <div class="col-sm-12 control-label">
           <p>Die Artikelliste wird im Frontend ausgegeben.</p>
         </div>
       </div>
    </div>
  </div>

<style>
#artikelliste .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#artikelliste .control-label {
  text-align: left;
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#artikelliste  h2 {
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
