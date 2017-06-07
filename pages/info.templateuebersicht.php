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
		$green = "class='grey'";
	} else {
		$green = "class='green'";
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
<table class="tg">
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
?>
<style type="text/css">
	.tg  {border-collapse:collapse;border-spacing:0; width: 100%;}
	.tg td{font-family:Arial, sans-serif;font-size:14px;padding:10px 5px !important;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
	.tg th{font-family:Arial, sans-serif;font-size:14px;padding: 5px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal; font-weight: bold;}
	.tg tr.green {background: #BADEC0; font-weight: bold;}
	.tg tr.grey {background: #eee; color: #000;}

</style>

