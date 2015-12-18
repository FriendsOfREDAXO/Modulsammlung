<?php
header('Content-Type: text/html; charset=utf-8');

error_reporting(E_ALL); // error_reporting(0);

$siteStartArticle  = rex_article::getSiteStartArticleId();
$currentArtikelId  = rex_article::getCurrentId();
$notfoundArticleId = rex_article::getNotfoundArticleId();

$artikelStatus    = rex_article::getCurrent()->getValue('status');


$REX['sidebar_krol']['sidenavi'] = '';
$sidenaviselect = '';

?>
<!DOCTYPE html>
<head>


<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" rel="stylesheet" integrity="sha256-7s5uDGW3AHqw6xtJmNNtr+OBRJUlgkNJEo78P4b0yRw= sha512-nNo+yCHEyn0smMxSswnf/OnX6/KwJuZTlNZBjauKhTK0c+zT+q5JOCx0UFhXQ6rJR9jg6Es8gPuD2uZcYDLqSw==" crossorigin="anonymous">

<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js" integrity="sha256-KXn5puMvxCw+dAYznun+drMdG1IFl3agK0p/pqT9KAo= sha512-2e8qq0ETcfWRI4HJBzQiA3UoyFk6tbNyG+qSaIBZLyW9Xf3sWZHN/lxe9fTh1U45DpPf07yj94KsUHHWe4Yk1A==" crossorigin="anonymous"></script>

</head>
<body>

<section id="content">
<?php
  $content = $this->getArticle(1);  // ctype 1 (Hauptinhalt)
  $content = $this->getArticle(1);  // ctype 2 (Seitenleiste)

  if ($nav_sidebar  != '' ) {   $showconatiner = true; }

  if ($currentArtikelId == $siteStartArticle) { $showconatiner = false; }

  $out= '';
    if ($showconatiner != false) {
      $out .= '
        <div class="container">
          <div class="row">
            <div class="sidebar col-sm-3 col-xs-12">
              '.
              $content2.
              $nav_artikel.
              $nav_sidebar
              .'
            </div>
            <div class="col-sm-9 col-xs-12">
            '.$content1.'
            </div>
          </div>
        </div>';
    } else {
       $out .=  $content1;
    }
  echo $out;
?>
</section>


</body>
</html>

