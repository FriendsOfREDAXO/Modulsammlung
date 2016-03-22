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



$fragment = new rex_fragment();
$content = '';

$sql = rex_sql::factory();
// $sql->setDebug();
 $sql->setQuery("SELECT rex_module.id as id,rex_module.name, COUNT(s.module_id) as occurence
 FROM rex_module
 LEFT JOIN rex_article_slice as s
 ON (s.module_id=rex_module.id)
 GROUP BY rex_module.id ORDER by occurence");

$modulinfos = '';


  foreach ($sql->getArray() as $row)   {

    if ($row['occurence'] == 0) {
      $orange = "class='orange'";
    } else {
      $orange = '';
    }

    $modulinfos .= '
      <tr '.$orange.'>
        <td class="id">'.$row['id'].'</td>
        <td class="tg-031e">'.$row['name'].'</td>
        <td class="tg-031e">'.$row['occurence'].'</td>
      </tr>
    ';

  }

$content .= '
<table class="tg">
  <tr>
    <th class="tg-031e">Modul ID</th>
    <th class="tg-031e">Modul Bezeichnung</th>
    <th class="tg-031e">Verwendung</th>
  </tr>
  '.$modulinfos.'
</table>';



$fragment = new rex_fragment();
$fragment->setVar('class', 'info', false);
$fragment->setVar('title', "Aktuelle Modulbenutzung", false);
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
?>
<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0; width: 100%;}
.tg td{font-family:Arial, sans-serif;font-size:14px;padding:10px 5px !important;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
.tg th{font-family:Arial, sans-serif;font-size:14px;padding: 5px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal; font-weight: bold;}
.tg tr.orange {background: #efbf3d; }
</style>
