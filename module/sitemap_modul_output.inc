<?php
//  ToDo
//  - testen ob Redactor funktioniert
//
//
//  Das Modul basiert auf einem Modul von Stefan Kittel (k²bytes)
//  Sitemap, Kategorieliste mit Artikeln und Textauszug
//  (http://www.redaxo.org/de/download/module/?modul_id=450)
//
//

$editor                 = 0;
if(!rex_addon::get('rex_redactor')->isAvailable() AND !rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "Redactor" oder das "MarkItUp" Addon!');
}
if(rex_addon::get('rex_redactor')->isAvailable()) {
  $editor = 'redactor';
 }
if(rex_addon::get('rex_markitup')->isAvailable()) {
  $editor = 'markitup';
}


$text             = 'REX_VALUE[1]';
$artikel          = 'REX_VALUE[2]';
$start_artikel    = 'REX_VALUE[3]';
$seo_infos        = 'REX_VALUE[4]';

if ($text !='') {
  if ($editor == 'markitup' AND rex_addon::get('textile')->isAvailable()) {
    $text = htmlspecialchars_decode($text);
    $text = str_replace('<br />', '',$text);
    $text = rex_textile::parse($text);
    $text = str_replace('###', '&#x20;',$text);
  }
}

if ($artikel == 'ja') { $artikel = 1; } else { $artikel = 0; };
if ($start_artikel == 'ja') { $start_artikel = 1; } else { $start_artikel = 0; };
if ($seo_infos == 'ja') { $seo_infos = 1; } else { $seo_infos = 0; };

function ModulPrintCatList($categories, $printArticles, $printStartArticles, $showSeoInfo) {
  if(is_array($categories) && count($categories) > 0) {
    echo '<ul>';
      foreach ($categories as $cat) {
        if ($cat->isOnline()){
          echo '<li><a href="'.$cat->getURL().'">'.$cat->getName().'</a>';
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
              if( ($art->isOnline()&& !$art->isStartArticle()) || ($art->isOnline()&& $printStartArticles) ){
                $tmp_str .= '<li><a href="'.$art->getURL().'">'.$art->getName().'</a>';
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
  <div id="trennlinie" class="bereichswrapper">
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
#trennlinie .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#trennlinie .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#trennlinie  h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

</style>'.PHP_EOL;
}

?>
