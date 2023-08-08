<?php
$dir = rex_path::addon('modulsammlung','lib/more_examples');
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
    $moduls_errors[] = $this->i18n('config_fehler').' '.$dir;
  }

  if (file_exists($dir.'/info.inc')) {
    $moduls[$module_key]['info'] = file_get_contents($dir.'/info.inc');
  } else {
    $moduls_errors[] = $this->i18n('info_fehler').' '.$dir;
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
    $moduls_errors[] = $this->i18n('input_fehler').' '.$dir;
  }

  if (file_exists($dir.'/output.inc')) {
    $moduls[$module_key]['output'] = file_get_contents($dir.'/output.inc');
  } else {
    $moduls_errors[] = $this->i18n('output_fehler').' '.$dir;
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

  if (file_exists($dir.'/template.inc')) {
    $moduls[$module_key]['template'] = $dir.'/template.inc';
  } else {
    $moduls[$module_key]['template'] = '';
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
    $statusinfo = $this->i18n('fertig');
  }
  // Status: in Bearbeitung
  if ($modul['config']['status'] == 2) {
    $statusfarbe = ' color: #6999D7; ';
    $statusinfo = $this->i18n('in_bearbeitung');
  }
  // Status: geplant
  if ($modul['config']['status'] == 0) {
    $statusfarbe = ' color: #BF5E52; ';
    $statusinfo = $this->i18n('entwicklung_geplant');
  }

  $modulausgabe[] = '
    <tr>
      <form action="' . rex_url::currentBackendPage() . '" method="POST">
      <td class="rex-table-icon">
        <i data-toggle="collapse" data-target="#'.$module_key.'_code" class="rex-icon rex-icon-module" style="'.$statusfarbe.' font-size: 2rem; margin: 7px 0 0 8px;" title="'.$statusinfo.'"></i>
      </td>
      <td data-title="'.$this->i18n('modul').'">
        <input class="form-control" type="text" name="modul_name" value="'.$modul['config']['modulname'].'">
        <input type="hidden" name="install" value="'.$module_key.'">
        <div id="'.$module_key.'_info" class="collapse">
          <p class="accordiontitle">Info</p>
          <div class="accordioncontent">
            '.$modul['info'].'
          </div>
        </div>
        <div id="'.$module_key.'_code" class="collapse">
          <p class="accordiontitle">'.$this->i18n('input').'</p>
          '.rex_string::highlight($modul['input']).'
          <p class="accordiontitle">'.$this->i18n('output').'</p>
          '.rex_string::highlight($modul['output']).'
        </div>
        <div id="'.$module_key.'_scss" class="collapse">
          <div style="padding: 10px 0 10px 0;" >';

          if($modul['styles_scss']) {
            $modulausgabe[] = '
              <p class="accordiontitle">'.$this->i18n('scss').'</p>
              '.rex_string::highlight($modul['styles_scss']);
          }
          if($modul['styles_css']) {
            $modulausgabe[] = '
              <p class="accordiontitle">'.$this->i18n('css').'</p>
              '.rex_string::highlight($modul['styles_css']);
          }
        $modulausgabe[] = '
            </div>
          </div>
        </td>
        <td>
          <span class="btn btn-success" data-toggle="collapse" data-target="#'.$module_key.'_info">'.$this->i18n('info').'</span>
        </td>
      <td>
      ';
      if ($moduls[$module_key]['styles_scss'] OR $moduls[$module_key]['styles_css']) {
        $modulausgabe[] = '<span class="btn btn-success" data-toggle="collapse" data-target="#'.$module_key.'_scss">'.$this->i18n('styles').'</span>'  ;
      }
  $modulausgabe[] = '</td>
      <td>';
       if ($modul['config']['status'] != 0) {
  $modulausgabe[] = '<input type="submit" class="btn btn-primary" class="rex-button" value="'.$this->i18n('modul_installieren').'" />';
      }
  $modulausgabe[] = '
      </td>
    </form>
  </tr>';

  if (rex_request('install') == $module_key) {
    //$modul_name           = $modul['config']['modulname'];

    $modul_name           = rex_post("modul_name", 'string');
      if ($modul_name == '') {
        echo rex_view::warning($this->i18n('modulname_fehler'));
      } else {
        if($moduls[$module_key]['metainfos'] != '') {
          include($moduls[$module_key]['metainfos']);
        }
        if($moduls[$module_key]['mediamanager'] != '') {
          include($moduls[$module_key]['mediamanager']);
        }
        if($moduls[$module_key]['template'] != '') {
          include($moduls[$module_key]['template']);
        }
        // Ordner in Assets kopieren
        if (array_key_exists('assets_folder',$modul['config'])  && $modul['config']['assets_folder'] != '') {
          $srcdir = '../redaxo/src/addons/modulsammlung/lib/module_mform_mblock/'.$module_key.'/'.$modul['config']['assets_folder'];
          // echo $srcdir;
          rex_dir::copy($srcdir ,'.././assets/'.$modul['config']['assets_folder']);
             echo rex_view::success($this->i18n('kopierter_ordner').' '.$modul['config']['assets_folder']);
          }

        // Ordner in Fragments kopieren
          if (array_key_exists('fragments_folder',$modul['config'])  && $modul['config']['fragments_folder'] != '') {
              $srcdir = '../redaxo/src/addons/modulsammlung/lib/more_examples/'.$module_key.'/'.$modul['config']['fragments_folder'];
              // echo $srcdir;
              rex_dir::copy($srcdir ,'../redaxo/src/addons/modulsammlung/'.$modul['config']['fragments_folder']);
              echo rex_view::success($this->i18n('kopierte_fragmente'));
          }

         $input = $moduls[$module_key]['input'];
         $output = $moduls[$module_key]['output'];

         $mi = rex_sql::factory();
//         $mi->setDebug();
         $mi->setTable('rex_module');
         $mi->setValue('input', $input);
         $mi->setValue('output', $output);
         $mi->setValue('name', $modul_name);
         $mi->insert();
         $modul_id = (int) $mi->getLastId();
         echo rex_view::success($this->i18n('modul_angelegt').' '.$modul_name);
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
          <th class="td_title">'.$this->i18n('modulsammlung_module_more_examples').'</th>
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
