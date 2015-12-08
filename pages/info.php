<?php

$fragment = new rex_fragment();
$content = '<p>

<h3>Modulsammlung</h3>

<p>Zweck dieses Addons ist die schnelle und unkomplizierte Installation einiger "Standard" Module</p>

';

$fragment = new rex_fragment();
$fragment->setVar('class', 'info', false);
$fragment->setVar('title', $this->i18n('info'), false);
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
