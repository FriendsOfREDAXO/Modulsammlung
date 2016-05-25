<?php
if(!rex::isBackend()) {

  if ('REX_MEDIA[1]' != '') {

    require('./assets/spreadsheed_reader/excel_reader2.php');
    require('./assets/spreadsheed_reader/SpreadsheetReader.php');

    $reader = new SpreadsheetReader('./media/REX_MEDIA[1]');

    $table[] = "<table>";
    foreach ($reader as $row) {
       $table[] =  "<tr>";
       foreach ($row as $column) {
        $table[] = "<td>$column</td>";
       }
       $table[] = "</tr>";
    }
    $table[] = "</table>";

    print implode($table);

  }
} else {
  echo '
  <div id="excel2table" class="bereichswrapper">
    <div class="form-horizontal output">
      ';

  if('REX_MEDIA[1]' != '') {
    echo '
      <div class="form-group">
         <label class="col-sm-3 control-label">Excel Datei</label>
         <div class="col-sm-9">REX_MEDIA[1]</div>
      </div>';
  } else {
    echo  '
      <div class="form-group">
         <label class="col-sm-3 control-label">Excel Datei</label>
        <div class="col-sm-9 warning"><b>ACHTUNG:</b><br/>Sie haben keine Excel-Datei angegeben. Das ist recht sinnfrei wenn dieses Modul benutzt wird!</div>
      </div>';
  };

  echo '
    </div>
  </div>

  <style>
  #excel2table .bereichswrapper {
    margin: 5px 0 5px 0;
    background: #f5f5f5;
    padding: 5px 15px 5px 15px;
    border: 1px solid #9da6b2;
  }

  #excel2table .control-label {
    font-weight: normal;
    font-size: 12px;
    margin-top: -6px;
  }

  #excel2table h2.ueberschrift {
    font-size: 12px !important;
    padding: 0 10px 10px 10px;
    margin-bottom: 15px;
    width: 100%;
    font-weight: bold;
    border-bottom: 1px solid #31404F;
  }

  #excel2table .warning {
    color: #f00;
  }

  </style>';
}
