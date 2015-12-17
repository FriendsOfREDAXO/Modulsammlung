
<?php

function sitemapliste2(&$openul,$lev,$PathIndex,$lastcat)       {
    $time = time();
        {
        if($openul == 0)            {
            print '<ul class="navLevel'.$PathIndex.'space">';
            $openul = 1;
        }

        if($lastcat == $lev){
                      $last = 'Last';
                      $last2 = '';
        } else {
                      $last = '';
                      $last2 = 'navLevel'.$PathIndex;
        }

        if(sizeof($lev->getChildren()) != 0 OR count($lev->getArticles()) > 1){
            $open = 'Open';
        } else {
            $open = '';
        }

        print '<li class="navLevel'.$PathIndex.$open.$last.'"><a class="'.$last2.'" href="'.$lev->getUrl().'">'.$lev->getName().'</a>';


        ////////////ARTIKEL START///////////////////

        $article = $lev->getArticles();
        $i=0;
        $j=0;
        if (count($article) > 1) {
         echo '<ul class="navLevel'.$PathIndex.'space">';

         foreach ($article as $var) {
                 if ($var->isOnline(true) and $articleId != $lev->getId()){
                    $i = $i+1;
                 }
         }

         foreach ($article as $var) {

           $articleId = $var->getId();
           $articleName = $var->getName();

           if ($var->isOnline(true) and $articleId != $lev->getId()){
                   $j = $j + 1;
                   if($j == $i){
                      $last = 'Last';
                      $last2 = '';
                   } else {
                      $last = '';
                      $last2 = 'navLevel'.$PathIndex;
                   }
                   print '<li class="navLevel'.$PathIndex.$last.'"><a class="'.$last2.'" href="'.rex_getUrl($articleId).'">'.$articleName.'</a></li>';

           }
         }
         echo '</ul>';
        }
        ////////////ARTIKEL ENDE/////////////////////

        $levSize = sizeof($lev->getChildren());

        if($_SESSION['USR_TYP'] < $lev->getValue("art_type_id")){
            $levSize = 0;
        }

        if($levSize != 0)
        {
            $opensubul = 0;
            $k = 0;
            foreach($lev->getChildren() as $sublevel) {
                $k = $k + 1;
                if($k == $levSize){
                      $lastcat = $sublevel;
                }
                sitemapliste2($opensubul,$sublevel,$PathIndex + 1,$lastcat);
            }
            if($opensubul == 1)
                echo "</ul>";
        }
        echo "</li>\n";
    }
}

$openul = 0;


foreach (rex_category::get(RootCategories) as $lev1){
    sitemapliste2($openul,$lev1,1,0);
}

if($openul == 1) {
    echo "</ul>\n";
}

?>
</div>

<?php
/*

$outback = '
  <table style="width: 100%; background-color: #eee;" >
  ';

 // Ueberschrift
  $ueberschrift_outback = '';
  if ("REX_VALUE[1]") {

      $outback .= '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Überschrift</td>
        <td style="padding: 5px;">REX_VALUE[1]</td>
      </tr>
      ';
  }





// FLiesstext
    if("REX_VALUE[2]") { // Text
      $fliesstext = htmlspecialchars_decode("REX_VALUE[2]",ENT_QUOTES);
      $fliesstext = str_replace('<br />','', $fliesstext);
      $fliesstext  = rex_a79_textile( $fliesstext);

      $outback .= '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Fliesstext</td>
        <td style="padding: 5px;">'.$fliesstext.'</td>
      </tr>
      ';
    } else {
      $fliesstext = '';
    }



  // Berücksichtigt SEO42 -> $article->getValue("seo_description")
  // Zwei Ebenen


$sitemap = '<div id="sitemap"><ul>'.PHP_EOL;

foreach (OOCategory::getRootCategories() as $lev1) {

  $catId = $lev1->getId();

  // Level 1
  if($lev1->isOnline()) {
    $lev1Size = sizeof($lev1->getChildren());

    if ($lev1->getValue("art_verstecken") != '|true|') { // Artikel verstecken



        $sitemap .='<li><a href="'.$lev1->getUrl().'">'.htmlspecialchars($lev1->getName()).'</a>'.PHP_EOL;
        // Description
        if ('REX_VALUE[6]' == "ja") {
          if ($lev1->getValue("seo_description") == '') {
            $sitemap .= '<p class="warning">Bitte eine Beschreibung eintragen!</p>'.PHP_EOL;
          } else {
            $sitemap .= '<p class="description">'.$lev1->getValue("seo_description").'</p>'.PHP_EOL;
          }
        }
      }



      // Artikel
      if ('REX_VALUE[5]' == "ja") {
      $articles = $lev1->getArticles(true); // Alle Artikel der Kategorie auslesen, die Online sind
      if (is_array( $articles) && count( $articles) > 2) {
        $sitemap .='<ul class="artikel">'.PHP_EOL;
        foreach ( $articles as $article) {
          if ( $article->isStartPage()) continue; // Startartikel ausblenden
            if ($article->getValue("art_verstecken") != '|true|') { // Artikel verstecken

                $sitemap .='<li><a href="'.$article->getUrl().'">'.$article->getName().'</a>'.PHP_EOL;
                  // Description
                  if ('REX_VALUE[6]' == "ja") {
                    if ($article->getValue("seo_description") == '') {
                      $sitemap .= '<p class="warning">Bitte eine Beschreibung eintragen!</p>'.PHP_EOL;
                    } else {
                      $sitemap .= '<p class="description">'.$article->getValue("seo_description").'</p>'.PHP_EOL;
                    }
                  }
                $sitemap .= '</li>'.PHP_EOL;

            }
          }
        $sitemap .='</ul>'.PHP_EOL;
        }
      }

      // Level 2
      $lev1Size = sizeof($lev1->getChildren());
      if($lev1Size != "0") {
        $sitemap .='<ul class="subnav2">'.PHP_EOL;
        foreach ($lev1->getChildren() as $lev2) {
          if ($lev2->isOnline()) {
              if ($lev2->getValue("art_verstecken") != '|true|') { // Artikel verstecken

                $sitemap .='<li><a href="'.$lev2->getUrl().'">'.htmlspecialchars($lev2->getName()).'</a>'.PHP_EOL;
                  // Description
                  if ('REX_VALUE[6]' == "ja") {
                    if ($lev2->getValue("seo_description") == '') {
                      $sitemap .= '<p class="warning">Bitte eine Beschreibung eintragen!</p>'.PHP_EOL;
                    } else {
                      $sitemap .= '<p class="description">'.$lev2->getValue("seo_description").'</p>'.PHP_EOL;
                    }

                $sitemap .='</li>'.PHP_EOL;

                }
              }



            // Artikel
            if ('REX_VALUE[5]' == "ja") {
            $articles2 = $lev2->getArticles(true); // Alle Artikel der Kategorie auslesen, die Online sind
            if (is_array( $articles2) && count( $articles2) > 2) {
              $sitemap .='<ul class="artikel"><ul>'.PHP_EOL;
              foreach ( $articles2 as $article2) {
                if ( $article2->isStartPage()) continue; // Startartikel ausblenden
                  if ($article2->getValue("art_verstecken") != '|true|') { // Artikel verstecken


                      $sitemap .='<li><a href="'.$article2->getUrl().'">'.$article2->getName().'</a>'.PHP_EOL;
                      // Description
                      if ('REX_VALUE[6]' == "ja") {
                        if ($article2->getValue("seo_description") == '') {
                          $sitemap .= '<p class="warning">Bitte eine Beschreibung eintragen!</p>'.PHP_EOL;
                        } else {
                          $sitemap .= '<p class="description">'.$article2->getValue("seo_description").'</p>'.PHP_EOL;
                        }
                      }

                      $sitemap .='</li>'.PHP_EOL;

                  }
                }
              $sitemap .='</ul">'.PHP_EOL;
            }
            }
              $sitemap .='</ul">'.PHP_EOL;
          }
        }
      $sitemap .='</ul>'.PHP_EOL; // Ende Level 2
      }
    $sitemap .='</li>'.PHP_EOL;
  }
}
$sitemap .= '</ul><div>'.PHP_EOL; // Ende Level 1



    $outback .= '
      <tr>
        <td style="padding: 5px; width: 150px; font-weight: bold;">Sitemap</td>
        <td style="padding: 5px;">Wird angezeigt</td>
      </tr>
      ';


  if ('REX_VALUE[5]' == "ja") {
      $outback .= '
        <tr>
          <td style="padding: 5px; width: 150px; font-weight: bold;">Artikel anzeigen</td>
          <td style="padding: 5px;">ja</td>
        </tr>
        ';
  }

  if ('REX_VALUE[6]' == "ja") {
      $outback .= '
        <tr>
          <td style="padding: 5px; width: 150px; font-weight: bold;">Beschreibung anzeigen</td>
          <td style="padding: 5px;">ja</td>
        </tr>
        ';
  }


$outback .= '
  </table>
  ';



if(!$REX['REDAXO']) {
//
//  Frontend
//
echo '<div class="container">'.PHP_EOL;
  echo '<div class="row">'.PHP_EOL;


    echo '<div class="col-xs-12 col-sm-6 col-md-6">'.PHP_EOL;
      echo '<h1>REX_VALUE[1]</h1>'.PHP_EOL;
      echo $fliesstext;
    echo '</div>'.PHP_EOL;

    echo '<div class="col-xs-12 col-sm-6 col-md-6 sitemap">'.PHP_EOL;
      echo $sitemap;
    echo '</div>'.PHP_EOL;

  echo '</div>'.PHP_EOL;
echo '</div>'.PHP_EOL;

} else {
//
//  Backend
//

  echo $outback;



}


*/


if(!rex::isBackend()) {

$REX['sidebar_krol']['sidenavi'] = rex::getProperty('sidebar_krol');

if (isset($REX['sidebar_krol']) && isset($REX['sidebar_krol']['sidenavi']) && $REX['sidebar_krol']['sidenavi'] != '') {
   echo  '
    <div class="container-fluid">
   ';
 } else {
   echo '
    <div class="container">
   ';
 }


  echo 'SIEDBAR'.PHP_EOL;


} else {

 echo '
  <div id="trennlinie" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Abstand oder Trennlinie mit/ohne Grafik</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Abstand in PX</label>
         <div class="col-sm-9">'.$abstand.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Linie anzeigen</label>
         <div class="col-sm-9">REX_VALUE[2]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Grafik anzeigen</label>
         <div class="col-sm-9">REX_VALUE[3]</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Breite des Trenners</label>
         <div class="col-sm-9">'.$breite.'</div>
       </div>
    </div>
  </div>


<style>
#trennlinie.bereichswrapper {
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

</style>

  '.PHP_EOL;
}

?>

