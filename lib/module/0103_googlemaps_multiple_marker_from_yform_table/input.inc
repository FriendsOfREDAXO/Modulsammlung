<?php /*
D . Google Map 3 - Input
 *
 * Hinweis zur Verwendung dieses Moduls.
 *
 * Voraussetzung für dieses Modul ist das yform AddOn mit installiertem Geo Plugin. Außerdem muss eine yform Tabelle angelegt sein, die ein Feld vom Typ Geoposition enthält.
 * Der Google Map Api Key muss dort hinterlegt sein. Ein Google Map api Key kann hier https://developers.google.com/maps/documentation/javascript/get-api-key?hl=de generiert werden.
 *
 * Alle Datensätze, die im Geopositionsfeld einen Eintrag haben, werden auf der Karte dargestellt.
 *
 * Das Infofenster ist ein Feld, welches mit beliebigem HTML Code befüllt werden kann. Es können Feldnamen aus der yform Tabelle mit dem Geocode als Platzhalter eingesetzt werden.
 *
 * Es sind zwei verschiedene Darstellungsmöglichkeiten für das Infofenster für jeden Marker möglich.
 * - Als ganz normales Infowindow. Dabei wird das Infowindow mit einem kleinen Pfeil am jeweiligen Marker dargestellt und die Karte wird gegebenenfalls verschoben, sodass das Infowindow dargestellt wird
 * - Als Overlay. Dabei ist das Overlay unabhängig von der Karte, die Information wird einfach mittig über der Karte angezeigt. Das Overlay ist leichter per css zu formatieren als das Google Infowindow.
 *
 * Beispiel:
 *
 * <h3>###name###</h3>
 * <p>###strasse###<br>
 * ###plz### ###ort###</p>
 *
 * Das Modul wurde mit REDAXO 5.4 und yform 2.3 getestet.
 *
 * Es wurde bewusst einfach gehalten. Es enthält keine Markercluster und alles benötigte css und js steht im Modul. Es ist kein jquery notwendig.
 *
 * Fragen?
 * Wolfgang Bund
 * post@agile-websites.de
 * http://agile-websites.de
 *
 */?>

<?php

$tables = rex_sql::showTables();
$check = true;
$message = [];
if (in_array(rex::getTable('yform_field'),$tables) == false) {
    $message[] = 'Die Tabelle '.rex::getTable('yform_field').' existiert nicht. Ist das yform AddOn installiert und aktiviert?';
    $check = false;
}
if (in_array(rex::getTable('yform_table'),$tables) == false) {
    $message[] = 'Die Tabelle '.rex::getTable('yform_table').' existiert nicht. Ist das yform AddOn installiert und aktiviert?';
    $check = false;
}
if (rex_addon::exists('yform') == false) {
    $message[] = 'Das AddOn yform ist nicht installiert.';
    $check = false;
}
if (rex_addon::exists('yform','geo') == false) {
    $message[] = 'Das Plugin Geo für yform ist nicht installiert.';
    $check = false;
}

if ($check) :

$qry = 'SELECT f.id, f.table_name, f.name f_name, f.label f_label, f.googleapikey, t.name t_name FROM '.rex::getTable('yform_field').' f '
        . 'LEFT JOIN '.rex::getTable('yform_table').' t ON f.table_name = t.table_name '
        . ' WHERE type_name = "google_geocode"';
$res = rex_sql::factory()->getArray($qry);
?>


<div class="form-group row">
    <label class="col-sm-2 control-label" for="value-4">Tabellenfeld mit Geocode auswählen</label>
    <div class="col-sm-10">
        <select name="REX_INPUT_VALUE[4]" id="value-4">
            <option value="">--- Bitte auswählen ---</option>
            <?php foreach ($res as $k=>$v) : ?>
            <option value='<?= json_encode(['id'=>$v['id'],'table'=>$v['table_name'],'field'=>$v['f_name'],'key'=>$v['googleapikey']]) ?>' <?= "REX_VALUE[id=4 output=html]" == json_encode(['id'=>$v['id'],'table'=>$v['table_name'],'field'=>$v['f_name'],'key'=>$v['googleapikey']]) ? ' selected="selected"' : '' ?>><?= $v['t_name'] ?> | <?= $v['f_label']?></option>
            <?php endforeach ?>
        </select>
    </div>
</div>

<div class="form-group row">
    <label class="col-sm-2 control-label" for="value-3">Text für das Infofenster (HTML)</label>
    <div class="col-sm-10">
        <textarea class="form-control" id="value-3" name="REX_INPUT_VALUE[3]" style="height:150px">REX_VALUE[3]</textarea>
        <p><strong>Hinweis: </strong> Feldnamen aus der Datenbank können als Platzhalter eingesetzt werden. z.B. ###plz### ###ort###</p>
    </div>
</div>

<div class="form-group row">
    <label class="col-sm-2 control-label" for="value-2">Darstellung</label>
    <div class="col-sm-10">
        <?php $select_array = ['Infowindow'=>'infowindow', 'Overlay'=>'overlay']; ?>
        <select name="REX_INPUT_VALUE[2]" id="value-2" size="2">
            <?php foreach ($select_array as $k=>$v) : ?>
            <option value="<?= $v ?>"<?= "REX_VALUE[2]" == $v ? ' selected="selected"' : '' ?>><?= $k ?></option>
            <?php endforeach ?>
        </select>
    </div>
</div>



<?php else : ?>
    <h3 style="color:red">Hinweis</h3>
    <p><?= implode('</p><p>',$message) ?></p>
<?php endif; ?>
