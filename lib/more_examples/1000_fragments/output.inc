<?php

$articles = rex_category::getCurrent()->getArticles();

if (count($articles)) {
    $elements = [];
    foreach ($articles as $article) {
        if (!$article->isOnline()) {
            continue;
        }
        $elements[] = ['url' => $article->getUrl(), 'label' => $article->getName()];
    }

    // entweder ohne framework
    $fragment = new \rex_fragment();
    $fragment->setVar('elements', $elements, false);
    echo '<br/><b>Ausgabe mit Fragement:</b> <i>1000_article-list.php</i>';
    echo $fragment->parse('1000_article-list.php');

    // oder bootstrap
    $fragment = new \rex_fragment();
    $fragment->setVar('elements', $elements, false);
    echo '<br/><b>Ausgabe mit Fragement:</b> <i>1000_article-list-bootstrap.php</i>';
    echo $fragment->parse('1000_article-list-bootstrap.php');
}

