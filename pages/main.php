<?php


$dir = '../redaxo/src/addons/modulsammlung/lib/module';
$modulesdirs = glob($dir.'/*',GLOB_ONLYDIR);

$moduls = array();
$moduls_errors = array();
$modulausgabe = array();


function show_errors($errors = array()) {
  echo '<ul>';
  foreach ($errors as $error) {
    echo '<li>'.$error.'</li>';
  }
  echo '</ul>';
}

foreach ($modulesdirs as $dir) {

    // echo $dir.'<br/>';
    // echo basename($dir).'<br/>';

  $module_key = basename($dir);


  if (file_exists($dir.'/config.inc')) {
    $moduls[$module_key]['config'] = parse_ini_file($dir.'/config.inc',TRUE);
  } else {
    $moduls_errors[] = 'config.inc nicht vorhanden in: '.$dir;
  }

  if (file_exists($dir.'/info.inc')) {
    $moduls[$module_key]['info'] = file_get_contents($dir.'/info.inc');
  } else {
    $moduls_errors[] = 'info.inc nicht vorhanden in: '.$dir;
  }


  if (file_exists($dir.'/styles_scss.inc')) {
    $moduls[$module_key]['styles_scss'] = file_get_contents($dir.'/styles_scss.inc');
  } else {
    $moduls[$module_key]['styles_scss'] = '';
  }
  if (file_exists($dir.'/styles_css.inc')) {
    $moduls[$module_key]['styles_css'] = file_get_contents($dir.'/styles_css.inc');
  } else {
    $moduls[$module_key]['styles_css'] = '';
  }

  if (file_exists($dir.'/input.inc')) {
    $moduls[$module_key]['input'] = file_get_contents($dir.'/input.inc');
  } else {
    $moduls_errors[] = 'input.inc nicht vorhanden in: '.$dir;
  }

  if (file_exists($dir.'/output.inc')) {
    $moduls[$module_key]['output'] = file_get_contents($dir.'/output.inc');
  } else {
    $moduls_errors[] = 'output.inc nicht vorhanden in: '.$dir;
  }

  if (file_exists($dir.'/metainfos.inc')) {
    $moduls[$module_key]['metainfos'] = $dir.'/metainfos.inc';
  } else {
    $moduls[$module_key]['metainfos'] = '';
  }

  if (file_exists($dir.'/mediamanager.inc')) {
    $moduls[$module_key]['mediamanager'] = $dir.'/mediamanager.inc';
  } else {
    $moduls[$module_key]['mediamanager'] = '';
  }

}

if (count($moduls_errors) > 0) {
  show_errors($moduls_errors);
} else {

  foreach ($moduls as $module_key => $modul) {
    /*
    $modulausgabe[] = '
      <tr>
        <td>
          '.var_dump($modul['config']).'
        </td>
      </tr>
    ';
    */

  $statusfarbe  = '';
  $statusinfo   = '';
  $folder       = '';
  // Status: Fertig
  if ($modul['config']['status'] == 1) {
    $statusfarbe = ' color: #36404F; ';
    $statusinfo = 'Fertig';
  }
  // Status: in Bearbeitung
  if ($modul['config']['status'] == 2) {
    $statusfarbe = ' color: #6999D7; ';
    $statusinfo = 'In Bearbeitung';
  }
  // Status: geplant
  if ($modul['config']['status'] == 0) {
    $statusfarbe = ' color: #BF5E52; ';
    $statusinfo = 'Entwicklung geplant';
  }

  $modulausgabe[] = '
    <tr>
      <form action="' . rex_url::currentBackendPage() . '" method="POST">
      <td class="rex-table-icon">

<i data-toggle="collapse" data-target="#'.$module_key.'_code" class="rex-icon rex-icon-module" style="'.$statusfarbe.' font-size: 2rem; margin: 7px 0 0 8px;" title="'.$statusinfo.'"></i></td>
        <td data-title="Modul">
          <input class="form-control" type="text" name="modul_name" value="'.$modul['config']['modulname'].'">
          <input type="hidden" name="install" value="'.$module_key.'">
          <div id="'.$module_key.'_info" class="collapse">

            <p class="accordiontitle">Info</p>
            <div style="padding: 10px; background: #f5f5f5; border: 1px solid #ccc;">
              '.$modul['info'].'
            </div>
            </div>

          <div id="'.$module_key.'_code" class="collapse">
            <p class="accordiontitle">Input</p>
             '.rex_string::highlight($modul['input']).'
            <p class="accordiontitle">Output</p>
             '.rex_string::highlight($modul['input']).'
          </div>


            <div id="'.$module_key.'_scss" class="collapse">
              <div style="padding: 10px 0 10px 0;" >
              ';

      if($modul['styles_scss']) {
             $modulausgabe[] = '
             <p class="accordiontitle">SCSS</p>
             '.rex_string::highlight($modul['styles_scss']);
      }
      if($modul['styles_css']) {
             $modulausgabe[] = '
             <p class="accordiontitle">CSS</p>
             '.rex_string::highlight($modul['styles_css']);
      }
 $modulausgabe[] = '
            </div>
          </div>

        </td>
      <td>
        <span class="btn btn-success" data-toggle="collapse" data-target="#'.$module_key.'_info">Info</span>
      </td>
      <td>
      ';
  if ($moduls[$module_key]['styles_scss'] OR $moduls[$module_key]['styles_css']) {
    $modulausgabe[] = '<span class="btn btn-success" data-toggle="collapse" data-target="#'.$module_key.'_scss">Styles</span>'  ;
  }


  $modulausgabe[] = '</td>
      <td>';
      if ($modul['config']['status'] != 0) {
  $modulausgabe[] = '<input type="submit" class="btn btn-primary" class="rex-button" value="Modul installieren" />';
      }
  $modulausgabe[] = '
      </td>
    </form>
  </tr>';


  if (rex_request('install') == $module_key) {
        //$modul_name           = $modul['config']['modulname'];

        $modul_name           = rex_post("modul_name", 'string');
        if ($modul_name == '') {
          echo rex_view::warning('Bitte einen Modulnamen angeben!');
        } else {

        if($moduls[$module_key]['metainfos'] != '') {
          include($moduls[$module_key]['metainfos']);
        }

        if($moduls[$module_key]['mediamanager'] != '') {
          include($moduls[$module_key]['mediamanager']);
        }

        // Ordner in Assets kopieren
        if (array_key_exists('assets_folder',$modul['config'])  && $modul['config']['assets_folder'] != '') {
          $srcdir = '../redaxo/src/addons/modulsammlung/lib/module/'.$module_key.'/'.$modul['config']['assets_folder'];
          // echo $srcdir;
          rex_dir::copy($srcdir ,'.././assets/'.$modul['config']['assets_folder']);
             echo rex_view::success('Der Ordner '.$modul['config']['assets_folder'].' wurde in den Assets Ordner kopiert.');
          }


         $input = $moduls[$module_key]['input'];
         $output = $moduls[$module_key]['output'];

         $mi = rex_sql::factory();
         $mi->debugsql = 0;
         $mi->setTable('rex_module');
         $mi->setValue('input', $input);
         $mi->setValue('output', $output);
         $mi->setValue('name', $modul_name);
         $mi->insert();
         $modul_id = (int) $mi->getLastId();
         echo rex_view::success('Das Modul "' . $modul_name . '" wurde angelegt. ');
        }
      }


 }
}
$content = '
<div id="modulsammlung">
  <div class="row">
    <table class="table table-striped table-hover">
      <thead>
        <tr>
          <th class="rex-table-icon"></th>
          <th class="td_title">Modul</th>
          <th class="td_info"></th>
          <th class="td_scss"></th>
          <th class="td_install"></th>
        </tr>
      </thead>
      <tbody>
';

$content .= implode($modulausgabe);

$content .= '
      </tbody>
    </table>
  </div>
</div>';


$fragment = new rex_fragment();
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
