<?php
  echo '<b>Link</b><br/>';
  if ('REX_LINK[id=1]' != '') {
    $art = rex_article::get("REX_LINK[id=1]");
    echo '<a href="'.rex_geturl('REX_LINK[id=1]', '.REX_CLANG_ID.').'" title="'.$art->getValue("name").'">'.$art->getValue("name").'</a>';
  }

  echo '<br/><hr/><br/>';

  echo '<b>Linkliste</b><br/>';

  $linkliste = '<ul class="list-group">';

  $articles = explode(',', "REX_LINKLIST[id=1]");
    foreach($articles as $article_id){
      $art = rex_article::get($article_id);

      $linkliste .='
      <li>
        <a href="'.rex_geturl($art->getValue('id'), '.REX_CLANG_ID.').'" title="'.$art->getValue('name').'" />
          '.$art->getValue("name").'
        </a>
      </li>';
    }

  $linkliste .= '</ul>';

  echo $linkliste;
