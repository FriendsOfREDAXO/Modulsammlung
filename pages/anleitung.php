<?php

$fragment = new rex_fragment();
$content = '<p>

<h3>Text - Bild - Modul für REDAXO 5</h3>

<p>Redaxo Modul für die Pflege von Inhalten die auf einer responsiven Webseite ausgegeben werden.</p>

<br/>
<p><b>Aktuelle Voraussetzungen</b></p>

<ul>
<li> Redactor Addon oder</li>
</ul>

<br/>
<p><b>Empfehlung</b></p>

<ul>
<li>Media Manager Typ: "standard" anlegen</li>
</ul>


';

$fragment = new rex_fragment();
$fragment->setVar('class', 'info', false);
$fragment->setVar('title', $this->i18n('anleitung'), false);
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
