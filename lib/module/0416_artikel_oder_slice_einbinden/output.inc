<?php
if( "REX_VALUE[2]" != "" )
{
  // Artikel-Existenz prüfen
  $article = rex_article::get('REX_LINK[id=1]');
  
  if (!$article) {
    if (rex::isBackend()) {
      print '<div class="alert alert-dismissible alert-danger">
        <strong>Fehler:</strong> Der ausgewählte Artikel existiert nicht mehr. Bitte aktualisieren oder entfernen Sie den Block.
      </div>';
    }
    return;
  }

  // Im Backend den Link zur Quelle anzeigen
  if(rex::isBackend())
  {
    $master = rex_article::get(REX_LINK[id=1 output=id]);
    print '<div class="alert alert-dismissible alert-info">
    <strong>Eingebundener Inhalt aus: </strong> <a type="button" class="btn btn-primary" href="index.php?page=content&article_id=REX_LINK[id=1 output=id]&mode=edit&clang=1">';
    print $master->getName().'</a></div>';
  }

  if ( "REX_VALUE[2]" === "kompletter_artikel" )
  {
    // kompletten Artikel einbinden
    $article_content = new rex_article_content($article->getId(), $article->getClang());
    echo $article_content->getArticle(1);
  }
  else
  {
    // Slice-Existenz prüfen
    $slice = rex_article_slice::getArticleSliceById("REX_VALUE[2]");
    
    if (!$slice) {
      if (rex::isBackend()) {
        print '<div class="alert alert-dismissible alert-danger">
          <strong>Fehler:</strong> Der ausgewählte Block/Slice existiert nicht mehr. Bitte aktualisieren oder entfernen Sie den Block.
        </div>';
      }
      return;
    }

    // Den Slice/Block laden und anzeigen
    print $slice->getSlice();
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
