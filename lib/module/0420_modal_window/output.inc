<?php
if (!rex_addon::get('markitup')->isAvailable() OR !rex_addon::get("yform")->isAvailable() OR !rex_plugin::get("yform", "tools")->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp", "yForm" und das Plugin "yForm/tools" Addon!');
}


$modal_title = 'REX_VALUE[id=2]';
$modal_text = markitup::parseOutput('textile', 'REX_VALUE[id=1 output="html"]');

$now_date = date('Y-m-d H:i');

$date = DateTime::createFromFormat('d-m-Y H:i', "REX_VALUE[3]");
$start_date = $date->format('Y-m-d H:i');

$date = DateTime::createFromFormat('d-m-Y H:i', "REX_VALUE[4]");
$end_date = $date->format('Y-m-d H:i');


if ($end_date == '') {
    if (rex::isBackend()) {
        echo rex_view::info('Es wurde kein Enddatum eingetragen. Block ist deaktiviert!');
    }
}

if ($start_date > $now_date AND $start_date != '') {

    if (rex::isBackend()) {
        echo rex_view::info('Das Startdatum liegt in der Zukunft. Dieser Block ist noch deaktiviert!');
    }
}

if ($start_date <= $now_date AND $end_date <= $now_date AND $end_date != '') {

    if (rex::isBackend()) {
        echo rex_view::info('Der Zeitraum ist abgelaufen. Dieser Block wurde deaktiviert!');
    }
}

if ($start_date <= $now_date AND $end_date >= $now_date AND ($start_date OR $end_date) != '') {

    if (!rex::isBackend()) {

        $output = array();

        $output[] = '<div id="infoModal" class="rex_infoModal modal fade" role="dialog">';
        $output[] = '<div class="modal-dialog">';
        $output[] = '<div class="modal-content">';
        # modal title
        $output[] = '<div class="modal-header">';
        $output[] = ' <button type="button" class="close" data-dismiss="modal">&times;</button>';
        $output[] = ' <h4 class="modal-title">' . $modal_title . '</h4>';
        $output[] = '</div>';
        #modal content
        $output[] = '<div class="modal-body">';
        $output[] = $modal_text;
        $output[] = '</div>';
        # modal footer
        $output[] = '<div class="modal-footer">';
        $output[] = ' <button type="button" class="btn btn-default" data-dismiss="modal">Fenster schließen</button>';
        $output[] = '</div>';

        $output[] = '</div>';
        $output[] = '</div>';
        $output[] = '</div>';

        echo join("\n", $output);

        $modal_js =
            PHP_EOL . '  <script>' .
            PHP_EOL . '  jQuery(document).ready(function () {' .
            PHP_EOL . '    jQuery(".rex_infoModal").modal("show");' .
            PHP_EOL . '  });' .
            PHP_EOL . '  </script>' . PHP_EOL;

        rex_extension::register('OUTPUT_FILTER', function (rex_extension_point $ep) use ($modal_js) {
            $suchmuster = '</body>';
            $ersetzen = $modal_js . "\n</body>";
            $ep->setSubject(str_replace($suchmuster, $ersetzen, $ep->getSubject()));
        });

    } else {
        echo '<h3>'.$modal_title . '</h3>';
        echo $modal_text;

        echo '<p>Startzeit: REX_VALUE[3]</p>';
        echo '<p>Endzeit: REX_VALUE[4]</p>';
    }
}
?>