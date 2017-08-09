<?php

$artikel          = 'REX_VALUE[2]';
$start_artikel    = 'REX_VALUE[3]';
$seo_infos        = 'REX_VALUE[4]';

if ('REX_VALUE[id=1 isset=1]') {
    $text = markitup::parseOutput ('textile', 'REX_VALUE[id=1 output="html"]');
} else {
    $text = '';
}

if ($artikel == 'ja') { $artikel = 1; } else { $artikel = 0; };
if ($start_artikel == 'ja') { $start_artikel = 1; } else { $start_artikel = 0; };
if ($seo_infos == 'ja') { $seo_infos = 1; } else { $seo_infos = 0; };

function ModulPrintCatList($categories, $printArticles, $printStartArticles, $showSeoInfo) {
  if(is_array($categories) && count($categories) > 0) {
    echo '<ul>';
      foreach ($categories as $cat) {
        if ($cat->isOnline()){

        $session = rex_backend_login::hasSession();
          if ($session) {
            $edit = '<a target="_blank" class="seositemapedit" href="/redaxo/index.php?page=content/metainfo&article_id='.$cat->getId().'&clang='.rex_clang::getCurrentId().'">Bearbeiten</a>';
          } else {
            $edit = '';
          }

          echo '<li><a href="'.$cat->getURL().'">'.$cat->getName().'</a>'.$edit;
          if(($showSeoInfo && !$printArticles) || ($showSeoInfo && $printArticles && !$printStartArticles) ){
            //Anzeige des Startartikels (wenn online)
            $art = $cat->getStartArticle();
            if($art->isOnline()){
              $articleDescription = $art->getValue("yrewrite_description");
              $articleTitle       = $art->getValue("yrewrite_title");
              if ($articleTitle) {
                echo '<br/><span><strong>Title:</strong> '.$articleTitle.'</span>';
              } else {
                echo '<br/><span class="warning" ><strong>Title:</strong> Bitte einen individuellen Titel eintragen!</span>';
              }
              if ($articleDescription) {
                echo '<br/><span><strong>Beschreibung:</strong> '.$articleDescription.'</span>';
              } else {
                echo '<br/><span class="warning" ><strong>Beschreibung:</strong> Bitte eine Beschreibung eintragen!</span>';
              }
            }
          }
        if($printArticles) {
          $articles = $cat->getArticles();
          if(is_array($articles) && count($articles) > 0) {
            $tmp_str = '';
            foreach ($articles as $art) {

          $session = rex_backend_login::hasSession();
            if ($session) {
              $edit = '<a target="_blank" class="seositemapedit" href="/redaxo/index.php?page=content/metainfo&article_id='.$art->getId().'&clang='.rex_clang::getCurrentId().'">Bearbeiten</a>';
            } else {
              $edit = '';
            }



              if( ($art->isOnline()&& !$art->isStartArticle()) || ($art->isOnline()&& $printStartArticles) ){
                $tmp_str .= '<li><a href="'.$art->getURL().'">'.$art->getName().'</a>'.$edit;
                if($showSeoInfo) {
                  $articleDescription = $art->getValue("yrewrite_description");
                  $articleTitle       = $art->getValue("yrewrite_title");
                  if ($articleTitle) {
                    $tmp_str .= '<br/><span><strong>Title:</strong> '.$articleTitle.'</span>';
                  } else {
                    $tmp_str .= '<br/><span class="warning" ><strong>Title:</strong> Bitte einen individuellen Titel eintragen!</span>';
                  }
                  if ($articleDescription) {
                    $tmp_str .= '<br/><span><strong>Beschreibung:</strong> '.$articleDescription.'</span>';
                  } else {
                    $tmp_str .= '<br/><span class="warning" ><strong>Beschreibung:</strong> Bitte eine Beschreibung eintragen!</span>';
                  }
                }
                $tmp_str .= '</li>';
              }
            }
            if($tmp_str != ''){
              echo '<ul class="artikel">';
              echo $tmp_str;
              echo '</ul>';
            }
          }
        }
        ModulPrintCatList($cat->getChildren(), $printArticles, $printStartArticles, $showSeoInfo);
        echo '</li>';
      }
    }
    echo '</ul>';
  }
}

if(!rex::isBackend()) {

$categories = rex_category::getRootCategories();
echo '<div class="container">';
echo '<div class="col-xs-6">';
echo $text;
echo '</div>';
echo '<div class="col-xs-6">';
echo '<div id="sitemap">';
if (is_array($categories) && count($categories) > 0){
      ModulPrintCatList($categories,$artikel,$start_artikel,$seo_infos);
}echo '</div></div>';

} else {
 echo '
  <div id="seositemap" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Sitemap</h2>
     ';

  if ($text !='') {
  echo '
    <div class="form-group">
      <label class="col-sm-3 control-label">Text</label>
      <div class="col-sm-9">'.$text.'</div>
    </div>';
  }
  echo '<div class="form-group">
         <label class="col-sm-3 control-label">Artikel anzeigen</label>
         <div class="col-sm-9">REX_VALUE[2]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Startartikel anzeigen</label>
         <div class="col-sm-9">REX_VALUE[3]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">SEO Infos anzeigen</label>
         <div class="col-sm-9">REX_VALUE[3]</div>
       </div>
    </div>
  </div>

<style>
#seositemap .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#seositemap .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#seositemap  h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

</style>'.PHP_EOL;
}
