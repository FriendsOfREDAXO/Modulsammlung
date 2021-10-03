<?php

$templateinfos = '';

$sql = rex_sql::factory();
$sql->setQuery("SELECT rex_template.id as id,rex_template.name, COUNT(s.template_id) as occurence
    FROM rex_template
    LEFT JOIN rex_article as s
    ON (s.template_id=rex_template.id)
    GROUP BY rex_template.id ORDER by occurence DESC");

foreach ($sql->getArray() as $row)   {
	if ($row['occurence'] == 0) {
		$green = "class=''";
	} else {
		$green = "class='success'";
	}

	$templateinfos .= '
      <tr '.$green.'>
        <td class="id">'.$row['id'].'</td>
        <td class="tg-031e">'.$row['name'].'</td>
        <td class="tg-031e">'.$row['occurence'].'</td>
      </tr>
    ';
}

$content = '
<table class="table">
  <tr>
    <th class="tg-031e">'.$this->i18n('template_id').'</th>
    <th class="tg-031e">'.$this->i18n('template_bezeichnung').'</th>
    <th class="tg-031e">'.$this->i18n('template_verwendung').'</th>
  </tr>
  '.$templateinfos.'
</table>';

$fragment = new rex_fragment();
$fragment->setVar('class', 'info', false);
$fragment->setVar('title', $this->i18n('template_benutzung'), false);
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
