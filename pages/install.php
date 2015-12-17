<?php
////////
//
// EWS : Text / Bild / Video / Link | 1-4 Spalten
//
////////
$content = '';
$ews_modul_name = '';
$content .= '
  <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <dl class="rex-form-group form-group">
      <dt><label>Modulname</label></dt>
        <dd><input class="form-control" type="text" name="ews_modul_name" value="0010 - Text / Bild / Video / Link | 1-4 Spalten"></dd>
      </dl>
      <dl class="rex-form-group form-group">
      <dd>
        <div class="checkbox"><label><input type="checkbox" name="ueberschrift" >Überschrift</label></div>
        <div class="checkbox"><label><input type="checkbox" name="text" >Textfelder</label></div>
        <div class="checkbox"><label><input type="checkbox" name="bild" >Bild</label></div>
        <div class="checkbox"><label><input type="checkbox" name="video" >Video</label></div>
        <div class="checkbox"><label><input type="checkbox" name="link" >Link</label></div>
        <!-- <div class="checkbox"><label><input type="checkbox" name="download" >Download</label></div> -->
      </dd>
    </dl>
    <input type="hidden" name="install" value="1">
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
          $mediamanager_standard_typ_id = (int) $mediamanager_standard_typ->getLastId();
          echo rex_view::success('Der Media Manager Typ wurde angelegt. ');
        } catch (rex_sql_exception $e) {
              echo rex_view::warning('Der Media Manager Typ wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
        }

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

$content .= '<input style="float:right;" type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $ews_modul_name) . '" />';

$content .= '</form>';

$content .= '
  <button class="btn btn-success" data-toggle="collapse" data-target="#ews">Modul Info</button>
  <div id="ews" class="collapse" style="padding: 0;">
    <div style="padding: 10px 15px 10px 15px;margin-top: 20px;background: #F3F6FB; border: 1px solid #3CB594;">
    <h3>Text / Bild / Video / Link | 1-4 Spalten</h3>
    <p>Redaxo Modul für die Pflege von Inhalten die auf einer responsiven Webseite ausgegeben werden.</p>
    <br/>
    <b>Voraussetzungen</b>
    <ul>
      <li>Redactor oder MarkItUp (+Textile) Addon</li>
    </ul>
    <br/><br/>
    <ul>
      <li>Der Media Manager Typ <i>standard</i> wird angelegt und kann konfiguriert werden.</li>
      <li>Das Meta Info Feld (Medien) <i>med_no_copyright_out</i> wird angelegt.</li>
    </ul>
    <br/><br/>
    <b>CSS für die Einbindung von Videos</b>
    <pre style="padding: 20px 20px 0 20px; margin-top: 10px;">
.responsive-video iframe {
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
}

.responsive-video {
  position: relative;
  padding-bottom: 56.25%; /* Default for 1600x900 videos 16:9 ratio*/
  padding-top: 0px;
  height: 0;
  overflow: hidden;
}
    </pre>
  </div>
</div>
';

$fragment = new rex_fragment();
$fragment->setVar('class', 'edit');
$fragment->setVar('title', 'Text / Bild / Video / Link | 1-4 Spalten', false);
$fragment->setVar('body', $content , false);
echo $fragment->parse('core/page/section.php');

////////
//
// Abstand oder Trennlinie mit/ohne Grafik
//
////////

$content = '';
$abstand_modul_name = '';

$content .= '
  <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <dl class="rex-form-group form-group">
      <dt><label>Modulname</label></dt>
      <dd><input class="form-control" type="text" name="abstand_modul_name" value="0020 - Abstand oder Trennlinie mit/ohne Grafik"></dd>
    </dl>
  <input type="hidden" name="install" value="2">';

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

$content .= '<input style="float:right;" type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $abstand_modul_name) . '" />';
$content .= '</form>';

$content .= '
<button class="btn btn-success" data-toggle="collapse" data-target="#abstand">Modul Info</button>
<div id="abstand" class="collapse" style="padding: 0;">
    <div style="padding: 10px 15px 10px 15px;margin-top: 20px;background: #F3F6FB; border: 1px solid #3CB594;">

    <h3>Abstand oder Trennlinie mit/ohne Grafik</h3>

    <p>Redaxo Modul für das Einfügen eines Abstandes bzw. einer Trennlinie mit oder ohne Grafik.</p>

    <br/>
    <b>Voraussetzungen</b>
    <ul>
        <li>Grafik "trenner.png" 30px x 30px im Files Ordner / Medienpool</li>
    </ul>
    </div>
</div>
';

    $fragment = new rex_fragment();
    $fragment->setVar('class', 'edit');
    $fragment->setVar('title', 'Abstand oder Trennlinie mit/ohne Grafik', false);
    $fragment->setVar('body', $content , false);
    echo $fragment->parse('core/page/section.php');

////////
//
// Google Maps / Routenplaner
//
////////

$content = '';
$googlemaps_modul_name = '';

$content .= '
  <form action="' . rex_url::currentBackendPage() . '" method="POST">
    <dl class="rex-form-group form-group">
      <dt><label>Modulname</label></dt>
      <dd><input class="form-control" type="text" name="googlemaps_modul_name" value="0030 - Google Maps Modul / Routenplaner"></dd>
    </dl>
  <input type="hidden" name="install" value="3">';

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

$content .= '<input style="float:right;" type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $googlemaps_modul_name) . '" />';
$content .= '</form>';

$content .= '
<button class="btn btn-success" data-toggle="collapse" data-target="#googlemaps">Modul Info</button>
<div id="googlemaps" class="collapse" style="padding: 0;">
    <div style="padding: 10px 15px 10px 15px;margin-top: 20px;background: #F3F6FB; border: 1px solid #3CB594;">

     <h3>Google Maps Modul / Routenplaner</h3>
    <p>Redaxo Modul für die Ausgabe einer Google Map mit einigen Konfigurationsmöglichkeiten und Ausgabe eines Routenplaners.</p>
    <br/>
    <b>Voraussetzungen</b>
    <ul>
      <li>jQuery im Frontend</li>
      <li>Redactor oder MarkItUp (+Textile) Addon</li>
    </ul>
    <br/><br/>
    <b>Minmale CSS Angaben für die Darstellung der Karte</b>
    <pre style="padding: 20px 20px 0 20px; margin-top: 10px;">

#map_canvas {
  width: 100%;
  height: 150px;
}

    </pre>
  </div>
</div>
';

    $fragment = new rex_fragment();
    $fragment->setVar('class', 'edit');
    $fragment->setVar('title', 'Google Maps Modul / Routenplaner', false);
    $fragment->setVar('body', $content , false);
    echo $fragment->parse('core/page/section.php');

////////
//
// Alle Bilder mit aus dem Medienpool mit Copyright anzeigen
//
////////

    $content = '';
    $copyright_modul_name = '';

    $content .= '
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
        <dl class="rex-form-group form-group">
            <dt><label>Modulname</label></dt>
            <dd><input class="form-control" type="text" name="copyright_modul_name" value="0100 - Alle Bilder mit aus dem Medienpool mit Copyright anzeigen"></dd>
        </dl>
    <input type="hidden" name="install" value="4">';

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
          $mediamanager_typ_id = (int) $mediamanager_typ->getLastId();
          echo rex_view::success('Der Media Manager Typ wurde angelegt. ');
        } catch (rex_sql_exception $e) {
              echo rex_view::warning('Der Media Manager Typ wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
        }

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

    $content .= '<input style="float:right;" type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $copyright_modul_name) . '" />';

    $content .= '</form>';

 $content .= '
<button class="btn btn-success" data-toggle="collapse" data-target="#copyright">Modul Info</button>
<div id="copyright" class="collapse" style="padding: 0;">
    <div style="padding: 10px 15px 10px 15px;margin-top: 20px;background: #F3F6FB; border: 1px solid #3CB594;">

    <h3>Alle Bilder mit aus dem Medienpool mit Copyright anzeigen</h3>

    <p>Alle Bilddateien (jpg,png,gif) im Medienpool deren Copyrightinfo ausgefüllt ist werden im Frontend ausgegeben. Ausnahmen bilden die Bilder bei denen im Medienpool das Feld "Nicht in der Copyrightliste ausgeben" aktiviert ist.</p>

    <br/>
    <ul>
        <li>Der Media Manager Typ <i>bildercopyright</i> wird angelegt und kann konfiguriert werden.</li>
        <li>Das Meta Info Feld (Medien) <i>med_no_copyright_out</i> wird angelegt.</li>
    </ul>
    </div>
</div>
';

    $fragment = new rex_fragment();
    $fragment->setVar('class', 'edit');
    $fragment->setVar('title', 'Alle Bilder mit aus dem Medienpool mit Copyright anzeigen', false);
    $fragment->setVar('body', $content , false);
    echo $fragment->parse('core/page/section.php');

