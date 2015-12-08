<?php

    $content = '';
    $ews_modul_name = '';

     $content .= '
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
        <dl class="rex-form-group form-group">
            <dt><label>Modulname</label></dt>
            <dd><input class="form-control" type="text" name="ews_modul_name" value="0010 - Text / Bild / Link | 1-4 Spalten"></dd>
        </dl>
        <dl class="rex-form-group form-group">
            <dd>
            <div class="checkbox"><label><input type="checkbox" name="ueberschrift" >Überschrift</label></div>
            <div class="checkbox"><label><input type="checkbox" name="text" >Textfelder</label></div>
            <div class="checkbox"><label><input type="checkbox" name="bild" >Bild</label></div>
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
      $ews_modul_bild           = rex_post("bild", 'string');
      $ews_modul_link           = rex_post("link", 'string');
      $ews_modul_download       = rex_post("download", 'string');

    if ($ews_modul_name == '') {
        echo rex_view::warning('Bitte einen Modulnamen angeben!');

    } else {

        $input = rex_file::get(rex_path::addon('modulsammlung','module/ews_module_input.inc'));

        if ($ews_modul_ueberschrift != '') {
            $input = str_replace("0;//ueberschrift", "1;//ueberschrift", $input);
        }
        if ($ews_modul_text != '') {
            $input = str_replace("0;//text", "1;//text", $input);
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

        $output = rex_file::get(rex_path::addon('modulsammlung','module/ews_module_output.inc'));

            $mi = rex_sql::factory();
            $mi->debugsql = 0;
            $mi->setTable('rex_module');
            $mi->setValue('input', $input);
            $mi->setValue('output', $output);


            $mi->setValue('name', $ews_modul_name);
            $mi->insert();
            $module_id = (int) $mi->getLastId();
            echo rex_view::success('Das Modul "' . $ews_modul_name . '" wurde angelegt. ');
    }
  }

    $content .= '<input style="float:right;" type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $ews_modul_name) . '" />';




    $content .= '</form>';

 $content .= '
<button class="btn btn-success" data-toggle="collapse" data-target="#ews">Modul Info</button>
<div id="ews" class="collapse" style="padding: 0;">
    <div style="padding: 10px 15px 10px 15px;margin-top: 20px;background: #F3F6FB; border: 1px solid #3CB594;">

    <h3>Text / Bild / Link | 1-4 Spalten</h3>

    <p>Redaxo Modul für die Pflege von Inhalten die auf einer responsiven Webseite ausgegeben werden.</p>

    <br/>
    <b>Aktuelle Voraussetzungen</b>
    <ul>
        <li>Redactor oder MarkItUp (+Textile) Addon</li>
    </ul>

    <br/>
    <b>Empfehlung</b>
    <ul>
        <li>Media Manager Typ: "standard" anlegen</li>
    </ul>

    </div>
</div>
';

    $fragment = new rex_fragment();
    $fragment->setVar('class', 'edit');
    $fragment->setVar('title', 'Text / Bild / Link | 1-4 Spalten', false);
    $fragment->setVar('body', $content , false);
    echo $fragment->parse('core/page/section.php');



////// Abstand oder Trennlinie mit/ohne Grafik

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

        $input = rex_file::get(rex_path::addon('modulsammlung','module/abstand_module_input.inc'));


        $output = rex_file::get(rex_path::addon('modulsammlung','module/abstand_module_output.inc'));

        $mi = rex_sql::factory();
        $mi->debugsql = 0;
        $mi->setTable('rex_module');
        $mi->setValue('input', $input);
        $mi->setValue('output', $output);

            $mi->setValue('name', $abstand_modul_name);
            $mi->insert();
            $module_id = (int) $mi->getLastId();
            echo rex_view::success('Das Modul "' . $abstand_modul_name . '" wurde angelegt. ');
    }
  }

    $content .= '<input style="float:right;" type="submit" class="btn btn-primary" class="rex-button" value="' . $this->i18n('form_modul_install_button', $abstand_modul_name) . '" />';

    $content .= '</form>';

 $content .= '
<button class="btn btn-success" data-toggle="collapse" data-target="#leer">Modul Info</button>
<div id="leer" class="collapse" style="padding: 0;">
    <div style="padding: 10px 15px 10px 15px;margin-top: 20px;background: #F3F6FB; border: 1px solid #3CB594;">

    <h3>Abstand oder Trennlinie mit/ohne Grafik</h3>

    <p>Redaxo Modul für das Einfügen eines Abstandes bzw. einer Trennlinie mit oder ohne Grafik.</p>

    <br/>
    <b>Aktuelle Voraussetzungen</b>
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



////// Alle Bilder mit aus dem Medienpool mit Copyright anzeigen

    $content = '';
    $copyright_modul_name = '';

    $content .= '
    <form action="' . rex_url::currentBackendPage() . '" method="POST">
        <dl class="rex-form-group form-group">
            <dt><label>Modulname</label></dt>
            <dd><input class="form-control" type="text" name="copyright_modul_name" value="0110 - Alle Bilder mit aus dem Medienpool mit Copyright anzeigen"></dd>
        </dl>
    <input type="hidden" name="install" value="3">';

  if (rex_request('install',"integer") == 3) {

      $copyright_modul_name           = rex_post("copyright_modul_name", 'string');

    if ($copyright_modul_name == '') {
        echo rex_view::warning('Bitte einen Modulnamen angeben!');

    } else {

        $input = rex_file::get(rex_path::addon('modulsammlung','module/copyright_module_input.inc'));
        $output = rex_file::get(rex_path::addon('modulsammlung','module/copyright_module_output.inc'));

        $mi = rex_sql::factory();
        $mi->debugsql = 0;
        $mi->setTable('rex_module');
        $mi->setValue('input', $input);
        $mi->setValue('output', $output);

            $mi->setValue('name', $copyright_modul_name);
            $mi->insert();
            $module_id = (int) $mi->getLastId();
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

    <p>Alle Bilder die im Medienpool deren Copyrightinfo ausgefüllt ist haben werden ausgegeben.</p>

    <br/>
    <b>Empfehlung</b>
    <ul>
        <li>Media Manager Typ: "bildercopyright" anlegen</li>
    </ul>
    </div>
</div>
';

    $fragment = new rex_fragment();
    $fragment->setVar('class', 'edit');
    $fragment->setVar('title', 'Alle Bilder mit aus dem Medienpool mit Copyright anzeigen', false);
    $fragment->setVar('body', $content , false);
    echo $fragment->parse('core/page/section.php');

