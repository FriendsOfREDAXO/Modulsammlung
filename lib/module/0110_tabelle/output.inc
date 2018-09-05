<?php
if(!function_exists('getdyntable')) {
    function getdyntable($string) {
        $tmp = explode('[ROW|ROW]', $string);
        $table = array();
        for($i=0;$i<count($tmp);$i++) {
            $tmp2 = explode('[COL|COL]', $tmp[$i]);
            foreach($tmp2 as $col) {
                $table[$i][] = trim($col);
            }
        }
        return $table;
    }
}

$table_data = "REX_VALUE[1]";
$table_class = "REX_VALUE[2]";
$table_caption = "REX_VALUE[3]";
$table_legend = "REX_VALUE[4]";
$set_table_class = ($table_class != '') ? ' '.$table_class : '';
$set_table_caption = ($table_caption != '') ? '<caption>'.$table_caption.'</caption>' : '';
$set_table_legend = ($table_legend != '') ? '<span class="legend">'.$table_legend.'</span>' : '';
$table_data = getdyntable($table_data);

$out = '<table class="table'.$set_table_class.'">';
$out .= $set_table_caption;

$rowcount = 0;
$issetThead = $issetTfoot = false;

foreach ($table_data as $row) {
    // Falls erste (Kopf-)Zeile ist und irgendeine Zelle gesetzt, dann thead öffnen
    if ($rowcount == 0) {
        foreach ($row as $th) {
            if ($th != '' && $issetThead == false) {
                $out .= '<thead><tr>';
                $issetThead = true;
            }
        }
    }

    // Wenn nicht Kopf- und Fußzeile ist Zeile öffnen
    $out .= ($rowcount != 0 && $rowcount != count($table_data)-1) ? '<tr>' : '';

    // Falls letzte (Fuß-)Zeile ist und irgendeine Zelle gesetzt, dann thead öffnen
    if ($rowcount == count($table_data)-1) {
        foreach ($row as $tf) {
            if ($tf != '' && $issetTfoot == false) {
                $out .= '<tfoot><tr>';
                $issetTfoot = true;
            }
        }
    }

    foreach ($row as $col) {
        if ($rowcount == 0 && $issetThead === true) {
            $out .= '<th>'.$col.'</th>';
        } else if ($rowcount == count($table_data)-1 && $issetTfoot === true) {
            $out .= '<td>'.$col.'</td>';
        } else if ($rowcount != 0 && $rowcount != count($table_data)-1) {
            $out .= '<td>'.$col.'</td>';
        }
    }

    // Wenn nicht Kopf- und Fußzeile ist Zeile schließen
    $out .= ($rowcount != 0 && $rowcount != count($table_data)-1) ? '</tr>' : '';

    // Falls erste (Kopf-)Zeile und $issetThead true gesetzt, dann thead schließen
    if ($rowcount == 0 && $issetThead == true) {
        $out .= '</tr></thead>';
    }

    // Falls letzte (Fuß-)Zeile und $issetThead true gesetzt, dann thead schließen
    if ($rowcount == 0 && $issetTfoot == true) {
        $out .= '</tr></tfoot>';
    }

    $rowcount++;
}

$out .= '</table>';

$out .= $set_table_legend;

if (!rex::isBackend()) {
    echo '<section class="dyntable">'.$out.'</section>';
} else {
    echo $out;
}
