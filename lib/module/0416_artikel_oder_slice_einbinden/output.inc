<?php
if( "REX_VALUE[2]" != "" )
{
  // Im Backend den Link zur Quelle anzeigen
  if(rex::isBackend())
  {
    $master = rex_article::get(REX_LINK[id=1 output=id]);
    print '<div class="alert alert-dismissible alert-info">
	<strong>Eingebundener Inhalt aus: </strong> <a type="button" class="btn btn-primary" href="index.php?page=content&article_id=REX_LINK[id=1 output=id]&mode=edit&clang=1">';
    print $master->getName().'</a></div>';
  }


  if ( "REX_VALUE[2]" == "kompletter_artikel" )
  {
    // kompletten Artikel einbinden

    $art = rex_article::get('REX_LINK[id=1]');

          // Artikelinhalt auslesen inkl. aktuelle Sprache
          $article = new rex_article_content($art->getId(), $art->getClang());
    echo $article->getArticle(1);
  }
  else
  {
    // Den Slice/Block laden und anzeigen
    if (rex_article_slice::getArticleSliceById( "REX_VALUE[2]" ))
    {
    $slice = rex_article_slice::getArticleSliceById( "REX_VALUE[2]" );
    print $slice->getSlice();
    }
  }
}
else
{
  // Im Backend kurzen (Fehler-)Text ausgeben
  if(rex::isBackend())
{
    print "<p>Noch keinen Slice/Block ausgew&auml;hlt.</p>";
  }
}