<?php

$dir = '../redaxo/src/addons/modulsammlung/lib/pakete';
$modulesdirs = glob($dir.'/*',GLOB_ONLYDIR);

$templates = array();
$templates_errors = array();
$templateausgabe = array();


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
    $templates[$module_key]['config'] = parse_ini_file($dir.'/config.inc',TRUE);
  } else {
    $templates_errors[] = $this->i18n('config_fehler').' '.$dir;
  }

  if (file_exists($dir.'/info.inc')) {
    $templates[$module_key]['info'] = file_get_contents($dir.'/info.inc');
  } else {
    $templates_errors[] = $this->i18n('info_fehler').' '.$dir;
  }

  if (file_exists($dir.'/styles_scss.inc')) {
    $templates[$module_key]['styles_scss'] = file_get_contents($dir.'/styles_scss.inc');
  } else {
    $templates[$module_key]['styles_scss'] = '';
  }
  if (file_exists($dir.'/styles_css.inc')) {
    $templates[$module_key]['styles_css'] = file_get_contents($dir.'/styles_css.inc');
  } else {
    $templates[$module_key]['styles_css'] = '';
  }

  if (file_exists($dir.'/metainfos.inc')) {
    $templates[$module_key]['metainfos'] = $dir.'/metainfos.inc';
  } else {
    $templates[$module_key]['metainfos'] = '';
  }

  if (file_exists($dir.'/mediamanager.inc')) {
    $templates[$module_key]['mediamanager'] = $dir.'/mediamanager.inc';
  } else {
    $templates[$module_key]['mediamanager'] = '';
  }

  if (file_exists($dir.'/template.inc')) {
    $templates[$module_key]['template'] = file_get_contents($dir.'/template.inc');
  } else {
    $templates_errors[] = $this->i18n('template_fehler').' '.$dir;
  }

}

if (count($templates_errors) > 0) {
  show_errors($templates_errors);
} else {

  foreach ($templates as $module_key => $modul) {
    /*
    $templateausgabe[] = '
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

  $templateausgabe[] = '
    <tr>
      <form action="' . rex_url::currentBackendPage() . '" method="POST">
      <td class="rex-table-template">

<i data-toggle="collapse" data-target="#'.$module_key.'_code" class="rex-template rex-icon rex-icon-module" style="'.$statusfarbe.' font-size: 2rem; margin: 7px 0 0 8px;" title="'.$statusinfo.'"></i></td>
        <td data-title="'.$this->i18n('template').'">
          <input class="form-control" type="text" name="modul_name" value="'.$modul['config']['templatename'].'">
          <input type="hidden" name="install" value="'.$module_key.'">
          <div id="'.$module_key.'_info" class="collapse">

            <p class="accordiontitle">Info</p>
            <div class="accordioncontent">
              '.$modul['info'].'
            </div>
            </div>

          <div id="'.$module_key.'_code" class="collapse">
            <p class="accordiontitle">'.$this->i18n('template').'</p>
             '.rex_string::highlight($modul['template']).'
          </div>


            <div id="'.$module_key.'_scss" class="collapse">
              <div style="padding: 10px 0 10px 0;" >
              ';

      if($modul['styles_scss']) {
             $templateausgabe[] = '
             <p class="accordiontitle">'.$this->i18n('scss').'</p>
             '.rex_string::highlight($modul['styles_scss']);
      }
      if($modul['styles_css']) {
             $templateausgabe[] = '
             <p class="accordiontitle">'.$this->i18n('css').'</p>
             '.rex_string::highlight($modul['styles_css']);
      }
 $templateausgabe[] = '
            </div>
          </div>

        </td>
      <td>
        <span class="btn btn-success" data-toggle="collapse" data-target="#'.$module_key.'_info">'.$this->i18n('info').'</span>
      </td>
      <td>
      ';
  if ($templates[$module_key]['styles_scss'] OR $templates[$module_key]['styles_css']) {
    $templateausgabe[] = '<span class="btn btn-success" data-toggle="collapse" data-target="#'.$module_key.'_scss">'.$this->i18n('styles').'</span>'  ;
  }


  $templateausgabe[] = '</td>
      <td>';
      if ($modul['config']['status'] != 0) {
  $templateausgabe[] = '<input type="submit" class="btn btn-primary" class="rex-button" value="'.$this->i18n('template_installieren').'" />';
      }
  $templateausgabe[] = '
      </td>
    </form>
  </tr>';


  if (rex_request('install') == $module_key) {
        //$modul_name           = $modul['config']['templatename'];

        $modul_name           = rex_post("modul_name", 'string');
        if ($modul_name == '') {
          echo rex_view::warning($this->i18n('templatename_fehler'));
        } else {

        if($templates[$module_key]['metainfos'] != '') {
          include($templates[$module_key]['metainfos']);
        }

        if($templates[$module_key]['mediamanager'] != '') {
          include($templates[$module_key]['mediamanager']);
        }

         // Ordner in Assets kopieren
        if (array_key_exists('assets_folder',$modul['config'])  && $modul['config']['assets_folder'] != '') {
          $srcdir = '../redaxo/src/addons/modulsammlung/lib/module/'.$module_key.'/'.$modul['config']['assets_folder'];
          // echo $srcdir;
          rex_dir::copy($srcdir ,'.././assets/'.$modul['config']['assets_folder']);
             echo rex_view::success($this->i18n('kopierter_ordner').' '.$modul['config']['assets_folder']);
          }


         $template = $templates[$module_key]['template'];

         $mi = rex_sql::factory();
//         $mi->setDebug();
         $mi->setTable('rex_template');
         $mi->setValue('content', $template);
         $mi->setValue('name', $modul_name);
         $mi->insert();
         $modul_id = (int) $mi->getLastId();
          echo rex_view::success($this->i18n('template_angelegt').' '.$modul_name);
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
          <th class="rex-table-template"></th>
          <th class="td_title">'.$this->i18n('templates').'</th>
          <th class="td_info"></th>
          <th class="td_scss"></th>
          <th class="td_install"></th>
        </tr>
      </thead>
      <tbody>
';

$content .= implode($templateausgabe);

$content .= '
      </tbody>
    </table>
  </div>
</div>';


$fragment = new rex_fragment();
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');
