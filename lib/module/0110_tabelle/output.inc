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
$table_data = getdyntable($table_data);

$out = '<table class="table">';
$rowcount=0;
foreach ($table_data as $row) {
    $out .= '<tr>';

    foreach ($row as $col) {
        ($rowcount==0) ? $out .= '<th>' : $out .= '<td>';
        $out .= $col;
        ($rowcount==0) ? $out .= '</th>' : $out .= '</td>';
    }
    $out .= '</tr>';
    $rowcount++;
}
$out .= '</table>';

if (!rex::isBackend()) {
  echo '<div class="container">'.$out.'</div>';
} else {
  echo $out;
}
?>
