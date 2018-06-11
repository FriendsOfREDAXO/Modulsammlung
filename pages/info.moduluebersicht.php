<?php

$func               = rex_request('func', 'string');

if ($func == 'deleteunusedmoduls') {
  $sql = rex_sql::factory();
  $sql->setQuery("SELECT rex_module.id as id,rex_module.name, COUNT(s.module_id) as occurence
    FROM rex_module
    LEFT JOIN rex_article_slice as s
    ON (s.module_id=rex_module.id)
    GROUP BY rex_module.id ORDER by occurence DESC");

  foreach ($sql->getArray() as $row)   {
    if ($row['occurence'] == 0) {

        $sql_del = rex_sql::factory();
        $sql_del->setTable('rex_module');
        $sql_del->setWhere('id = '.$row['id']);

        if ($sql_del->delete()) {
          echo '<div class="alert alert-success">'.$this->i18n('modul_geloescht').$row['id'].'</div>';
        }

    }
  }
}

  $modulinfos = '';

  $sql = rex_sql::factory();
  $sql->setQuery("SELECT rex_module.id as id,rex_module.name, COUNT(s.module_id) as occurence
    FROM rex_module
    LEFT JOIN rex_article_slice as s
    ON (s.module_id=rex_module.id)
    GROUP BY rex_module.id ORDER by occurence DESC");

  foreach ($sql->getArray() as $row)   {
    if ($row['occurence'] == 0) {
      $green = "class='grey'";
    } else {
      $green = "class='green'";
    }

    $modulinfos .= '
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
    <th class="tg-031e">'.$this->i18n('modul_id').'</th>
    <th class="tg-031e">'.$this->i18n('modul_bezeichnung').'</th>
    <th class="tg-031e">'.$this->i18n('modul_verwendung').'</th>
  </tr>
  '.$modulinfos.'
</table>';

$content .= '<button id="moduledelete" class="btn btn-delete">'.$this->i18n('module_loeschen').'</button>';

$fragment = new rex_fragment();
$fragment->setVar('class', 'info', false);
$fragment->setVar('title', $this->i18n('modul_benutzung'), false);
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
?>
<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0; width: 100%;}
.tg td{font-family:Arial, sans-serif;font-size:14px;padding:10px 5px !important;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
.tg th{font-family:Arial, sans-serif;font-size:14px;padding: 5px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal; font-weight: bold;}
.tg tr.green {background: #BADEC0; font-weight: bold;}
.tg tr.grey {background: #eee; color: #000;}
#moduledelete { font-size: 12px; margin-top: 8px; float: right;}

</style>
<script>
$("#moduledelete").click(function(){
  location.replace("index.php?page=modulsammlung/info/moduluebersicht&func=deleteunusedmoduls" );
});
</script>
