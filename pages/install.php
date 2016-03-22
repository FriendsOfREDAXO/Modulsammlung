<?php
echo '
<table class="table table-striped table-hover">
  <thead>
    <tr>
      <th class="rex-table-icon"></th>
      <th style="width: 100%">Modulbezeichnung</th>
      <th>Info</th>
      <th>Techn. Infos</th>
      <th>Installieren</th>
    </tr>
  </thead>
<tbody>
';


////////
//
// EWS : Text / Bild / Video / Link | 1-4 Spalten
//
////////
$ews_modul_name = '';

echo '
  <tr>
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <td class="rex-table-icon"><i class="rex-icon rex-icon-module" style="font-size: 2rem; margin: 7px 0 0 8px;"></i></a></td>
      <td data-title="Modulbezeichnung" style="display: inline-block; width: 100%; border: none;">
        <input class="form-control" type="text" name="ews_modul_name" value="0010 - Text / Bild / Video / Link | 1-4 Spalten">
        <input type="hidden" name="install" value="1">
      <dl class="rex-form-group form-group">
        <dd style="float: left; margin: 10px 0 -10px 10px;">
          <div class="checkbox"><label><input type="checkbox" name="ueberschrift" checked>Überschrift</label></div>
          <div class="checkbox"><label><input type="checkbox" name="text" checked>Textfelder</label></div>
        </dd>
       <dd style="float: left; margin: 10px 0 -10px 10px;">
          <div class="checkbox"><label><input type="checkbox" name="bild" >Bild</label></div>
          <div class="checkbox"><label><input type="checkbox" name="video" >Video</label></div>
        </dd>
        <dd style="float: left; margin: 10px 0 -10px 10px;">
          <div class="checkbox"><label><input type="checkbox" name="link" >Link</label></div>
          <!-- <div class="checkbox"><label><input type="checkbox" name="download" >Download</label></div> -->
        </dd>
        </dl>


          <div id="ews_info" class="collapse">
          <div style="padding: 10px; background: #f5f5f5; border: 1px solid #ccc;">
            '.rex_file::get(rex_path::addon('modulsammlung','module/ews_modul_info.inc')).'
          </div>
          </div>
          <div id="ews_css" class="collapse" >
            <div style="padding: 10px 0 10px 0;">
            <pre>'.rex_file::get(rex_path::addon('modulsammlung','module/ews_modul_css.inc')).'</pre>
          </div>
        </div>
      </td>
    <td data-title="Info"><span class="btn btn-success" data-toggle="collapse" data-target="#ews_info">Info</span></td>
    <td data-title="Techn. Infos"><span class="btn btn-success" data-toggle="collapse" data-target="#ews_css">CSS Angaben</span></td>
    <td data-title="Installieren">
      <input type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $ews_modul_name) . '" />
    </td>
    </form>
    </tr>
';


if (rex_request('install',"integer") == 1) {
  $ews_modul_name           = rex_post("ews_modul_name", 'string');
  $ews_modul_ueberschrift   = rex_post("ueberschrift", 'string');
  $ews_modul_text           = rex_post("text", 'string');
  $ews_modul_video          = rex_post("video", 'string');
  $ews_modul_bild           = rex_post("bild", 'string');
  $ews_modul_link           = rex_post("link", 'string');
  $ews_modul_download       = rex_post("download", 'string');

  if ($ews_modul_name == '') {
    echo rex_view::warning('Bitte einen Modulnamen angeben!');
  } else {
    $mediamanager_standard_typ = rex_sql::factory();
    $mediamanager_standard_typ->setTable('rex_media_manager_type');
    $mediamanager_standard_typ->setValue('name','standard');
    $mediamanager_standard_typ->setValue('description','Zur Darstellung der Bilder im Content.');

    try {
      $mediamanager_standard_typ->insert();
      echo rex_view::success('Der Media Manager Typ wurde angelegt. ');
    } catch (rex_sql_exception $e) {
      echo rex_view::warning('Der Media Manager Typ wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
    }

    $mediamanager_standard_typ_id = (int) $mediamanager_standard_typ->getLastId();

    $mediamanager_standard_typ_effekt = rex_sql::factory();
    $mediamanager_standard_typ_effekt->setTable('rex_media_manager_type_effect');
    $mediamanager_standard_typ_effekt->setValue('type_id', $mediamanager_standard_typ_id);
    $mediamanager_standard_typ_effekt->setValue('priority', 1);
    $mediamanager_standard_typ_effekt->setValue('effect', 'resize');
    $mediamanager_standard_typ_effekt->setValue('parameters', '{"rex_effect_crop":{"rex_effect_crop_width":"","rex_effect_crop_height":"","rex_effect_crop_offset_width":"","rex_effect_crop_offset_height":"","rex_effect_crop_hpos":"center","rex_effect_crop_vpos":"middle"},"rex_effect_filter_blur":{"rex_effect_filter_blur_repeats":"10","rex_effect_filter_blur_type":"gaussian","rex_effect_filter_blur_smoothit":""},"rex_effect_filter_sharpen":{"rex_effect_filter_sharpen_amount":"80","rex_effect_filter_sharpen_radius":"0.5","rex_effect_filter_sharpen_threshold":"3"},"rex_effect_flip":{"rex_effect_flip_flip":"X"},"rex_effect_header":{"rex_effect_header_download":"open_media","rex_effect_header_cache":"no_cache"},"rex_effect_insert_image":{"rex_effect_insert_image_brandimage":"","rex_effect_insert_image_hpos":"left","rex_effect_insert_image_vpos":"top","rex_effect_insert_image_padding_x":"-10","rex_effect_insert_image_padding_y":"-10"},"rex_effect_mediapath":{"rex_effect_mediapath_mediapath":""},"rex_effect_mirror":{"rex_effect_mirror_height":"","rex_effect_mirror_set_transparent":"colored","rex_effect_mirror_bg_r":"","rex_effect_mirror_bg_g":"","rex_effect_mirror_bg_b":""},"rex_effect_resize":{"rex_effect_resize_width":"750","rex_effect_resize_height":"320","rex_effect_resize_style":"maximum","rex_effect_resize_allow_enlarge":"enlarge"},"rex_effect_rounded_corners":{"rex_effect_rounded_corners_topleft":"","rex_effect_rounded_corners_topright":"","rex_effect_rounded_corners_bottomleft":"","rex_effect_rounded_corners_bottomright":""},"rex_effect_workspace":{"rex_effect_workspace_width":"","rex_effect_workspace_height":"","rex_effect_workspace_hpos":"left","rex_effect_workspace_vpos":"top","rex_effect_workspace_set_transparent":"colored","rex_effect_workspace_bg_r":"","rex_effect_workspace_bg_g":"","rex_effect_workspace_bg_b":""}}');

        try {
          $mediamanager_standard_typ_effekt->insert();
          echo rex_view::success('Der Media Manager Effekt wurde angelegt und kann konfiguriert werden!');
        } catch (rex_sql_exception $e) {
              echo rex_view::warning('Der Media Manager Effekt wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
        }

    $input = rex_file::get(rex_path::addon('modulsammlung','module/ews_modul_input.inc'));

    if ($ews_modul_ueberschrift != '') {
      $input = str_replace("0;//ueberschrift", "1;//ueberschrift", $input);
    }
    if ($ews_modul_text != '') {
      $input = str_replace("0;//text", "1;//text", $input);
    }
    if ($ews_modul_video != '') {
      $input = str_replace("0;//video", "1;//video", $input);
    }
    if ($ews_modul_bild != '') {
      $input = str_replace("0;//bild", "1;//bild", $input);
    }
    if ($ews_modul_link != '') {
      $input = str_replace("0;//link", "1;//link", $input);
    }
    if ($ews_modul_download != '') {
      $input = str_replace("0;//download", "1;//download", $input);
    }

    $output = rex_file::get(rex_path::addon('modulsammlung','module/ews_modul_output.inc'));


    $mi = rex_sql::factory();
    $mi->debugsql = 0;
    $mi->setTable('rex_module');
    $mi->setValue('input', $input);
    $mi->setValue('output', $output);
    $mi->setValue('name', $ews_modul_name);
    $mi->insert();
    $modul_id = (int) $mi->getLastId();
    echo rex_view::success('Das Modul "' . $ews_modul_name . '" wurde angelegt. ');
  }
}




////////
//
// Abstand oder Trennlinie mit/ohne Grafik
//
////////
$abstand_modul_name = '';
echo '
  <tr>
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <td class="rex-table-icon"><i class="rex-icon rex-icon-module" style="font-size: 2rem; margin: 7px 0 0 8px;"></i></a></td>
      <td data-title="Modulbezeichnung">

        <input class="form-control" type="text" name="abstand_modul_name" value="0020 - Abstand oder Trennlinie mit/ohne Grafik">
        <input type="hidden" name="install" value="2">

          <div id="abstand_info" class="collapse">
          <div style="margin-top: 10px;padding: 10px; background: #f5f5f5; border: 1px solid #ccc;">
            '.rex_file::get(rex_path::addon('modulsammlung','module/abstand_modul_info.inc')).'
          </div>
          </div>
          <div id="abstand_css" class="collapse">
            <div style="padding: 10px 0 10px 0;">
            <pre style="margin-top: 10px;">'.rex_file::get(rex_path::addon('modulsammlung','module/abstand_modul_css.inc')).'</pre>
          </div>
        </div>

      </td>
    <td data-title="Info"><span class="btn btn-success" data-toggle="collapse" data-target="#abstand_info">Info</span></td>
    <td data-title="Techn. Infos"><span class="btn btn-success" data-toggle="collapse" data-target="#abstand_css">SCSS Angaben</span></td>
    <td data-title="Installieren">
      <input type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $abstand_modul_name) . '" />
    </td>
    </form>
    </tr>
';
    if (rex_request('install',"integer") == 2) {
      $abstand_modul_name           = rex_post("abstand_modul_name", 'string');

      if ($abstand_modul_name == '') {
        echo rex_view::warning('Bitte einen Modulnamen angeben!');
      } else {
       $input = rex_file::get(rex_path::addon('modulsammlung','module/abstand_modul_input.inc'));
       $output = rex_file::get(rex_path::addon('modulsammlung','module/abstand_modul_output.inc'));

       $mi = rex_sql::factory();
       $mi->debugsql = 0;
       $mi->setTable('rex_module');
       $mi->setValue('input', $input);
       $mi->setValue('output', $output);
       $mi->setValue('name', $abstand_modul_name);
       $mi->insert();
       $modul_id = (int) $mi->getLastId();
       echo rex_view::success('Das Modul "' . $abstand_modul_name . '" wurde angelegt. ');
      }
    }




////////
//
// Google Maps / Routenplaner
//
////////

$googlemaps_modul_name = '';
echo '
  <tr>
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <td class="rex-table-icon"><i class="rex-icon rex-icon-module" style="font-size: 2rem; margin: 7px 0 0 8px;"></i></a></td>
      <td data-title="Modulbezeichnung" style="display: inline-block; width: 100%; ">
        <input class="form-control" type="text" name="googlemaps_modul_name" value="0030 - Google Maps / Routenplaner">
        <input type="hidden" name="install" value="3">
          <div id="googlemaps_info" class="collapse">
            <div style="margin-top: 10px;padding: 10px; background: #f5f5f5; border: 1px solid #ccc;">
              '.rex_file::get(rex_path::addon('modulsammlung','module/googlemaps_modul_info.inc')).'
            </div>
          </div>
          <div id="googlemaps_css" class="collapse">
            <div style="padding: 10px 0 10px 0;">
            <pre style="margin-top: 10px;">'.rex_file::get(rex_path::addon('modulsammlung','module/googlemaps_modul_css.inc')).'</pre>
          </div>
        </div>
      </td>
    <td data-title="Info"><span class="btn btn-success" data-toggle="collapse" data-target="#googlemaps_info">Info</span></td>
    <td data-title="Techn. Infos"><span class="btn btn-success" data-toggle="collapse" data-target="#googlemaps_css">CSS Angaben</span></td>
    <td data-title="Installieren">
      <input type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $googlemaps_modul_name) . '" />
    </td>
    </form>
    </tr>
';

    if (rex_request('install',"integer") == 3) {
      $googlemaps_modul_name           = rex_post("googlemaps_modul_name", 'string');

      if ($googlemaps_modul_name == '') {
        echo rex_view::warning('Bitte einen Modulnamen angeben!');
      } else {
       $input = rex_file::get(rex_path::addon('modulsammlung','module/googlemaps_modul_input.inc'));
       $output = rex_file::get(rex_path::addon('modulsammlung','module/googlemaps_modul_output.inc'));

       $mi = rex_sql::factory();
       $mi->debugsql = 0;
       $mi->setTable('rex_module');
       $mi->setValue('input', $input);
       $mi->setValue('output', $output);
       $mi->setValue('name', $googlemaps_modul_name);
       $mi->insert();
       $modul_id = (int) $mi->getLastId();
       echo rex_view::success('Das Modul "' . $googlemaps_modul_name . '" wurde angelegt. ');
      }
    }

////////
//
// Text / Kontaktformular
//
////////

$text_kontaktformular_modul_name = '';
echo '
  <tr>
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <td class="rex-table-icon"><i class="rex-icon rex-icon-module" style="font-size: 2rem; margin: 7px 0 0 8px;"></i></a></td>
      <td data-title="Modulbezeichnung">

        <input class="form-control" type="text" name="text_kontaktformular_modul_name" value="0040 - Text / Kontaktformular">
        <input type="hidden" name="install" value="7">

          <div id="text_kontaktformular_info" class="collapse">
            <div style="margin-top: 10px;padding: 10px; background: #f5f5f5; border: 1px solid #ccc;">
              '.rex_file::get(rex_path::addon('modulsammlung','module/text_kontaktformular_modul_info.inc')).'
            </div>
          </div>

      </td>
    <td data-title="Info"><span class="btn btn-success" data-toggle="collapse" data-target="#text_kontaktformular_info">Info</span></td>
    <td data-title="Techn. Infos"></td>
    <td data-title="Installieren">
      <input type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $text_kontaktformular_modul_name) . '" />
    </td>
    </form>
    </tr>
';


  if (rex_request('install',"integer") == 7) {
    $text_kontaktformular_modul_name           = rex_post("text_kontaktformular_modul_name", 'string');

    if ($text_kontaktformular_modul_name == '') {
      echo rex_view::warning('Bitte einen Modulnamen angeben!');
    } else {
      $input = rex_file::get(rex_path::addon('modulsammlung','module/text_kontaktformular_modul_input.inc'));
      $output = rex_file::get(rex_path::addon('modulsammlung','module/text_kontaktformular_modul_output.inc'));

      $mi = rex_sql::factory();
      $mi->debugsql = 0;
      $mi->setTable('rex_module');
      $mi->setValue('input', $input);
      $mi->setValue('output', $output);
      $mi->setValue('name', $text_kontaktformular_modul_name);
      $mi->insert();
      $modul_id = (int) $mi->getLastId();
        echo rex_view::success('Das Modul "' . $text_kontaktformular_modul_name . '" wurde angelegt. ');
      }
    }


////////
//
// Nur Text
//
////////

$nur_text_modul_name = '';
echo '
  <tr>
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <td class="rex-table-icon"><i class="rex-icon rex-icon-module" style="font-size: 2rem; margin: 7px 0 0 8px;"></i></a></td>
      <td data-title="Modulbezeichnung">

        <input class="form-control" type="text" name="nur_text_modul_name" value="0060 - Nur Text (Footer, Seitenleiste etc.)">
        <input type="hidden" name="install" value="6">

          <div id="nur_text_info" class="collapse">
            <div style="margin-top: 10px;padding: 10px; background: #f5f5f5; border: 1px solid #ccc;">
              '.rex_file::get(rex_path::addon('modulsammlung','module/nur_text_modul_info.inc')).'
            </div>
          </div>

      </td>
    <td data-title="Info"><span class="btn btn-success" data-toggle="collapse" data-target="#nur_text_info">Info</span></td>
    <td data-title="Techn. Infos"></td>
    <td data-title="Installieren">
      <input type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $nur_text_modul_name) . '" />
    </td>
    </form>
    </tr>
';

    if (rex_request('install',"integer") == 6) {
      $nur_text_modul_name           = rex_post("nur_text_modul_name", 'string');

      if ($nur_text_modul_name == '') {
        echo rex_view::warning('Bitte einen Modulnamen angeben!');
      } else {
       $input = rex_file::get(rex_path::addon('modulsammlung','module/nur_text_modul_input.inc'));
       $output = rex_file::get(rex_path::addon('modulsammlung','module/nur_text_modul_output.inc'));

       $mi = rex_sql::factory();
       $mi->debugsql = 0;
       $mi->setTable('rex_module');
       $mi->setValue('input', $input);
       $mi->setValue('output', $output);
       $mi->setValue('name', $nur_text_modul_name);
       $mi->insert();
       $modul_id = (int) $mi->getLastId();
       echo rex_view::success('Das Modul "' . $nur_text_modul_name . '" wurde angelegt. ');
      }
    }


////////
//
// Alle Bilder mit aus dem Medienpool mit Copyright anzeigen
//
////////

$copyright_modul_name = '';
echo '
  <tr>
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <td class="rex-table-icon"><i class="rex-icon rex-icon-module" style="font-size: 2rem; margin: 7px 0 0 8px;"></i></a></td>
      <td data-title="Modulbezeichnung">

        <input class="form-control" type="text" name="copyright_modul_name" value="0100 - Alle Bilder mit aus dem Medienpool mit Copyright anzeigen">
        <input type="hidden" name="install" value="4">

          <div id="copyright_info" class="collapse">
          <div style="margin-top: 10px;padding: 10px; background: #f5f5f5; border: 1px solid #ccc;">
            '.rex_file::get(rex_path::addon('modulsammlung','module/copyright_modul_info.inc')).'
          </div>
          </div>
        </div>

      </td>
    <td data-title="Info"><span class="btn btn-success" data-toggle="collapse" data-target="#copyright_info">Info</span></td>
    <td data-title="Techn. Infos"></td>
    <td data-title="Installieren">
      <input type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $copyright_modul_name) . '" />
    </td>
    </form>
    </tr>
';
  if (rex_request('install',"integer") == 4) {

      $copyright_modul_name           = rex_post("copyright_modul_name", 'string');

    if ($copyright_modul_name == '') {
        echo rex_view::warning('Bitte einen Modulnamen angeben!');

    } else {

        $input = rex_file::get(rex_path::addon('modulsammlung','module/copyright_modul_input.inc'));
        $output = rex_file::get(rex_path::addon('modulsammlung','module/copyright_modul_output.inc'));

        rex_metainfo_add_field('Nicht in der Copyrightliste ausgeben', 'med_no_copyright_out', '3','','5','','','','');

        $mediamanager_typ = rex_sql::factory();
        $mediamanager_typ->setTable('rex_media_manager_type');
        $mediamanager_typ->setValue('name','bildercopyright');
        $mediamanager_typ->setValue('description','Zur Darstellung der Bilder in der Copyrightliste.');

        try {
          $mediamanager_typ->insert();
          echo rex_view::success('Der Media Manager Typ wurde angelegt. ');
        } catch (rex_sql_exception $e) {
              echo rex_view::warning('Der Media Manager Typ wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
        }

        $mediamanager_typ_id = (int) $mediamanager_typ->getLastId();

        $mediamanager_typ_effekt = rex_sql::factory();
        $mediamanager_typ_effekt->setTable('rex_media_manager_type_effect');
        $mediamanager_typ_effekt->setValue('type_id', $mediamanager_typ_id);
        $mediamanager_typ_effekt->setValue('priority', 1);
        $mediamanager_typ_effekt->setValue('effect', 'resize');
        $mediamanager_typ_effekt->setValue('parameters', '{"rex_effect_crop":{"rex_effect_crop_width":"","rex_effect_crop_height":"","rex_effect_crop_offset_width":"","rex_effect_crop_offset_height":"","rex_effect_crop_hpos":"center","rex_effect_crop_vpos":"middle"},"rex_effect_filter_blur":{"rex_effect_filter_blur_repeats":"10","rex_effect_filter_blur_type":"gaussian","rex_effect_filter_blur_smoothit":""},"rex_effect_filter_sharpen":{"rex_effect_filter_sharpen_amount":"80","rex_effect_filter_sharpen_radius":"0.5","rex_effect_filter_sharpen_threshold":"3"},"rex_effect_flip":{"rex_effect_flip_flip":"X"},"rex_effect_header":{"rex_effect_header_download":"open_media","rex_effect_header_cache":"no_cache"},"rex_effect_insert_image":{"rex_effect_insert_image_brandimage":"","rex_effect_insert_image_hpos":"left","rex_effect_insert_image_vpos":"top","rex_effect_insert_image_padding_x":"-10","rex_effect_insert_image_padding_y":"-10"},"rex_effect_mediapath":{"rex_effect_mediapath_mediapath":""},"rex_effect_mirror":{"rex_effect_mirror_height":"","rex_effect_mirror_set_transparent":"colored","rex_effect_mirror_bg_r":"","rex_effect_mirror_bg_g":"","rex_effect_mirror_bg_b":""},"rex_effect_resize":{"rex_effect_resize_width":"150","rex_effect_resize_height":"100","rex_effect_resize_style":"maximum","rex_effect_resize_allow_enlarge":"enlarge"},"rex_effect_rounded_corners":{"rex_effect_rounded_corners_topleft":"","rex_effect_rounded_corners_topright":"","rex_effect_rounded_corners_bottomleft":"","rex_effect_rounded_corners_bottomright":""},"rex_effect_workspace":{"rex_effect_workspace_width":"","rex_effect_workspace_height":"","rex_effect_workspace_hpos":"left","rex_effect_workspace_vpos":"top","rex_effect_workspace_set_transparent":"colored","rex_effect_workspace_bg_r":"","rex_effect_workspace_bg_g":"","rex_effect_workspace_bg_b":""}}');

        try {
          $mediamanager_typ_effekt->insert();
          echo rex_view::success('Der Media Manager Effekt wurde angelegt und kann konfiguriert werden!');
        } catch (rex_sql_exception $e) {
              echo rex_view::warning('Der Media Manager Effekt wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
        }

        $mi = rex_sql::factory();
        $mi->debugsql = 0;
        $mi->setTable('rex_module');
        $mi->setValue('input', $input);
        $mi->setValue('output', $output);
        $mi->setValue('name', $copyright_modul_name);
        $mi->insert();
        $modul_id = (int) $mi->getLastId();
        echo rex_view::success('Das Modul "' . $copyright_modul_name . '" wurde angelegt. ');
    }
  }




////////
//
// Sitemap
//
////////

$sitemap_modul_name = '';
echo '
  <tr>
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <td class="rex-table-icon"><i class="rex-icon rex-icon-module" style="font-size: 2rem; margin: 7px 0 0 8px;"></i></a></td>
      <td data-title="Modulbezeichnung">

        <input class="form-control" type="text" name="sitemap_modul_name" value="0110 - Sitemap">
        <input type="hidden" name="install" value="5">

          <div id="sitemap_info" class="collapse">
            <div style="margin-top: 10px;padding: 10px; background: #f5f5f5; border: 1px solid #ccc;">
              '.rex_file::get(rex_path::addon('modulsammlung','module/sitemap_modul_info.inc')).'
            </div>
          </div>
          <div id="sitemap_css" class="collapse" >
            <div style="padding: 10px 0 10px 0;">
            <pre style="margin-top: 10px;">'.rex_file::get(rex_path::addon('modulsammlung','module/sitemap_modul_css.inc')).'</pre>
          </div>
        </div>

      </td>
    <td data-title="Info"><span class="btn btn-success" data-toggle="collapse" data-target="#sitemap_info">Info</span></td>
    <td data-title="Techn. Infos"><span class="btn btn-success" data-toggle="collapse" data-target="#sitemap_css">CSS Angaben</span></td>
    <td data-title="Installieren">
      <input type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $sitemap_modul_name) . '" />
    </td>
    </form>
    </tr>
';


    if (rex_request('install',"integer") == 5) {
      $sitemap_modul_name           = rex_post("sitemap_modul_name", 'string');

      if ($sitemap_modul_name == '') {
        echo rex_view::warning('Bitte einen Modulnamen angeben!');
      } else {
       $input = rex_file::get(rex_path::addon('modulsammlung','module/sitemap_modul_input.inc'));
       $output = rex_file::get(rex_path::addon('modulsammlung','module/sitemap_modul_output.inc'));

       $mi = rex_sql::factory();
       $mi->debugsql = 0;
       $mi->setTable('rex_module');
       $mi->setValue('input', $input);
       $mi->setValue('output', $output);
       $mi->setValue('name', $sitemap_modul_name);
       $mi->insert();
       $modul_id = (int) $mi->getLastId();
       echo rex_view::success('Das Modul "' . $sitemap_modul_name . '" wurde angelegt. ');
      }
    }




echo '
</tbody>
</table>';



