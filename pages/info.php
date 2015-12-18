<?php

$fragment = new rex_fragment();
$content = '<p>

<h3>Modulsammlung</h3>
<br/>
<p>Zweck dieses Addons ist die schnelle und unkomplizierte Installation einiger "Standard" Module.</p>
<p>Da es keinen Updateprozess vorhandener Module gibt (ist auch nicht geplant) kann das Addon nach der Installation der gewünschten Module eigentlich wieder gelöscht werden.<p>

<p>Selbstverständlich können (und sollen) die Module nach der Installation individuell angepasst werden.</p>

<p>Legt doch bitte für alle auftretende Fehler, Notices und Wünsche ein Issue an:
<a href="https://github.com/olien/REX5-Modulsammlung" target="_blank">https://github.com/olien/REX5-Modulsammlung</a></p>

';

$fragment = new rex_fragment();
$fragment->setVar('class', 'info', false);
$fragment->setVar('title', $this->i18n('info'), false);
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
